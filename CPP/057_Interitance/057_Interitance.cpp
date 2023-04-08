// 057_Interitance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 캡슐화
// 클래스가 특정 기능을 품고 외부에 가르쳐주지 않는 것
// 캡슐화를 지원하는 문법은 접근제한 지정자
// 


// 상속
// 상속은 특정 개체의 특성을 하위 개념에서 DNA유전자처럼 동일한 가능을 물려받는것
// Is a 관계라고 한다.
// <Player> has a <Item> : 플레이어가 아이템을 갖고 있다.
// <Weapon> Is a <Item>  : 무기는 아이템이다.
// <Potion> Is a <Item>  : 포션은 아이템이다


// 사용 용도는 어디까지나 하위의 같은 코드를 상위 개념에 정의 되어있는 코드를 물려줘 
// 코드를 줄이기 위해서이다.

class Player
{
public:
    int Gold = 30; // 각자가 같은 속성을 갖고 있다.

    void PrintBuy() // 같은 기능을 갖고 있다.
    {
        std::cout << "물건을 구매했습니다." << std::endl;
        std::cout << "남은 잔돈은" << Gold << "남았습니다" << std::endl;
    }

    int GetFame() const
    {
        return 90;
    }

    void SetFame(const int& _Fame)
    {
        Fame = _Fame;
    }

    void Buy()
    {

    }

protected:
    int Fame;


// private 접근 지정자에서는 부모가 자식에게 특성 및 기능 을 상속시켜주지 못하기 때문에
// 외부로 전달하는 것처럼 Set()이나, Get()함수를 써서 특성 또는 기능을 전달해줘야 한다.
private:
    void Sell()
    {

    }

};


// 기본 클래스를 만든다
//           공개 여부는 public으로 설정 Player에서 
// Item으로 Player의 public, protected, private지정자에 있는 특성을 받음
class Item : public Player
{// 자식 코드
// 포인터로 선언함으로 Player를 가르키는 대상을 Master로 지정하고
// Master 사용하여 Player의 특성을 불러오는데 사용된다
// 쉽게 생각하면 int* ArrPtr = Arr; 로 비추어 볼 수 있는데
// Arr의 요소를 사용하기 위해서 ArrPtr을 사용하는 것과 같다.
public: 
    Player* Master;
    //int Gold = 0; // 속성

    //void Buy()
    //{

    //}

protected:
    int NeedFame;
    int NeedGold;

    //void BuyRequest()

    void CanBuyThis()
    {
        if (Fame >= NeedFame)
        {
            Gold -= NeedGold;
            PrintBuy();
        }
    }

    
};

// : public Item의 특성의 상속을 의미하는 문법
class Weapon : public Item
{
public:
    Weapon()
    {// 자식 코드
        Gold = 20; // 자식코드에서도 변수를 지정하지 않아도 부모의 특성과 속성을 사용할 수 있게 된다.
        Buy();
        /*Sell();*/
    }
    //int Gold = 0; // 속성

    //void Buy() // 특성 
    // 
    //{

    //}
private:
    int NeedFame = 40;
    int NeedGold = 5;

};

// 자식 Potion에서 proteced 상속받은 Item의 기능
class Potion : protected Item
{
public:
    Potion()
    {
        Gold;
    }
private: 
    int NeedFame = 70;
    int NeedGold = 20;
};

class TransPotion : public Potion
{
public:
    TransPotion()
    {
        Gold;
    }
};



int main()
{
    Player NewPlayer;
    Potion HealingPotion;

    NewPlayer.Gold = 600;

    //HealingPotion.Gold = 45; // 포션은 부모클래스로부터 proected로 
    // 상속받았기 때문에 부모의 public에 있는 특성을 사용하지 못함
    // 즉, Protected부터 private까지 내려온다.
    // 하지만 private은 자식코드에 공개되지 않으므로 사실상 protected만 상속받게 된다

    int value = NewPlayer.GetFame();
    NewPlayer.SetFame(NewPlayer.GetFame());
    
    
}