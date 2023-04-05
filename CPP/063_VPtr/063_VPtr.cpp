// 063_VPtr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 가상 함수 테이블은 다형성을 구현하기 위한 방법 중 하나이다.
// virtual이라는 가상 함수가 클래스에 붙고, 이 클래스의 객체가 생성될 때,
// 컴파일러가 void(*__vfptr[???])() 가상 함수 테이블이 생성을 한다.
// virtual을 선언한 가상 함수들의 포인터가 저장된다.

// 가상 함수 포인터의 배열을 만들어내고 함수 포인터들을 포인터로 저장한다.
// void(**__vfptr() == void(*__vfptr[??])()

class FightUnit
{
public:
    FightUnit()
        // [0]FightUnit::Damage
        // [1]FightUnit::FightStatusRender
    {
        this;
        int a = 0;
    }


    virtual void Damage()
    {

    }

    virtual void FightStatusRender()
    {

    }

    void Heal()
    {

    }
};

class Player : public FightUnit
{
public:
    Player()
        // [0]Player::Damage(void)
        // [1]FightUnit::FightStatusRender(void)
    {
        this;
        //int a = 0;
    }

    void Damage() override   // 명시적으로 선언할 것
    {

    }
};

int main()
{
    int value = sizeof(FightUnit);

    Player NewPlayer;

    Player* CurPlayer = &NewPlayer;

    CurPlayer->Heal();

    int a = 0;
}
