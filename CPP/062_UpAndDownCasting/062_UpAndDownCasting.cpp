// 062_UpAndDownCasting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
public:
    FightUnit()
        : Hp(100)
        , Att(10)
    {

    }

    void beDamaged(int _Att)
    {
        Hp -= _Att;
    }

    // 가상함수 문법은 부모의 함수를 자식이 사용할 때 각자 다른 방식으로 동작하길 원할때 쓴다.
    // 예를들어 부모의 GetAtt()를 상속받은 두 자식 중 한명은 다른 방식을 고수한다.
    // 그래서 한명은 override를 사용하여 자기 자신만의 부모와 이름이 같지만 로직이 다른 함수를 사용하고
    // 또 다른 한명은 완전히 부모와 같은 함수를 사용하게 된다.

    // 즉, 자식이 새롭게 정의하지 않으면 부모형으로 동작하게 되고
    // 자식이 새롭게 정의한다면 자식의 형으로 동작하게 된다.

    // 사용이유는 자식이 이름은 같지만, 다른 로직의 함수를 사용하고 싶을때 virtual를 선언한다
    virtual int GetAtt() const
    {
        return Att;
    }

    int GetHp() const
    {
        return Hp;
    }

private:
    int Hp;
    int Att;
};

class Player : public FightUnit
{
public:
    Player()
    {
        Lv = 3;
        Equip = 6;
    }

    // 오버라이드를 쓰는 이유?
    // 부모와 이름이 같은 함수지만, 같은 함수의 행동을 하기 싫어서
    // 
    // => Q: 그럼 GetAtt이름을 바꿔 안쓰면 되지 않느냐
    // => A: 생산성이 떨어지고, 나중에 코드가 길어졌을 때 일일이 못외워 사용하기 힘들어짐
    // => A: 그래서 전부 같은 이름이지만, 다형성을 이용해 다른 로직을 갖게 한다 
    int GetAtt() const override
    {
        return FightUnit::GetAtt() + Lv + Equip;
    }
    

private:
    int Lv;
    int Equip;

};



class Monster : public FightUnit
{

};


// 플레이어가 왼쪽값으로 호출되면 상관없지만,
// 몬스터가 왼쪽값으로 올때, 에러가 남
// 몬스터의 인수를 받아오는 플레이어 매개변수는 서로 호환이 되지 않음 

void Fight0(Player* _Left, Monster* _Right)
{
    int LeftAtt = _Left->GetAtt();
    int RightAtt = _Right->GetAtt();
    int a = 0;

    _Right->beDamaged(LeftAtt);
    _Left->beDamaged(RightAtt);
}

// 일일이 코드를 고치기 번거롭다.
void Fight1(Player* _Left, FightUnit* _Right)
{
    int LeftAtt = _Left->GetAtt();
    int RightAtt = _Right->GetAtt();
    int a = 0;

    _Right->beDamaged(LeftAtt);
    _Left->beDamaged(RightAtt);
}


void Fight3(FightUnit* _Left, FightUnit* _Right)
{
    // 최악의 방법은 의도적으로 부모의 자료형에서 자식의 자료형으로 바꾸는 다운캐스팅이다.
    // 부모 클래스로부터 상속을 받은 자식의 클래스는 부모와 독립적인 자식클래스의 메모리가 합쳐지기 때문에
    // 메모리로 봤을 때, 자식이 부모의 메모리보다 크다.
    // 부모 클래스의 포인터 자료형이 자식 클래스의 포인터 자료형으로 변환되면 알 수 없는 더미값이 추기됨
    // 그래서 이 방법은 위험한 방법이 됨

    // Player* PlayerPtr = (Player*)_Left; // 빈 공간이 확장됨 => 더미값 추가를 의미
    // _Right->Damage(PlayerPtr->GettPlayerAtt());

    int LeftAtt = _Left->GetAtt();
    int RightAtt = _Right->GetAtt();

    _Right->beDamaged(LeftAtt);
    _Left->beDamaged(RightAtt);
}


// 상속의 다형성

// 그래서 부모 클래스의 포인터로 전부 동일 시켰다.
// 이를 업캐스팅이라고 한다.

// 그런데 문제
// 부모 클래스의 포인트로 자기만의 override함수를 갖고 있는 클래스를 호출할 때,
// 함수는 누구 것의 호출되는가
// A: 자식의 override된 함수가 호출된다.
void Fight(FightUnit* _Left, FightUnit* _Right)
{
    int LeftAtt = _Left->GetAtt();
    int RightAtt = _Right->GetAtt();

    _Right->beDamaged(LeftAtt);
    std::cout << LeftAtt << "값 만큼 피해를 입었습니다." << "남은 Hp : " << _Right->GetHp() << std::endl;
    _Left->beDamaged(RightAtt);
    std::cout << RightAtt << "값 만큼 피해를 입었습니다." << "남은 Hp : " << _Left->GetHp() << std::endl;

    printf_s("\n");
}

int main()
{
    {
        FightUnit* Ptr;
    }

    {
        Player NewPlayer;
        Monster NewMonster;

        Player* PlayerPtr = &NewPlayer;

        // 이런 형변환을 해줘야되는 이유?

        // (FightUnit*) = (Player*)
        // 자신의 부모클래스로 암시적 형변환이 일어남
        FightUnit* Ptr = PlayerPtr;

        // 부모의 클래스포인터에 NewMonster 객체의 주소를 대입해라
        Ptr = &NewMonster;
        // Ptr = (FightUnit*)NewMonster;

        Fight(&NewMonster, &NewPlayer);
        Fight(Ptr, &NewPlayer);

        int MonsterHpResult = Ptr->GetHp();
        int PlayerHpResult = NewPlayer.GetHp();



        void(*FuncPtr)(FightUnit* _Left, FightUnit* _Right);
        FuncPtr = &Fight;
        FuncPtr(&NewMonster, &NewPlayer);

        MonsterHpResult = Ptr->GetHp();
        PlayerHpResult = NewPlayer.GetHp();

        int a = 0;
    }

    {
        Monster TestMonster;
        Player TestPlayer;


        Fight0(&TestPlayer, &TestMonster);
        //Fight1(&TestMonster, &TestPlayer);
    }
}