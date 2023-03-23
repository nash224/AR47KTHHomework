
#include <iostream>

class Weapon
{
public:
    int Att = 200;
public:
    //  클래스가 멤버를 초기화하는 방법을 사용자가 지정하거나
    //  클래스의 개체를 만들 때 생성자를 정의한다.
    Weapon()       
    {
        int a = 0;
    }
};

class Potion
{
public:
    int Heal = 100;
public:
    Potion()
    {
        int a = 0;
    }
};

class Player
{
public: 
    //  리터널초기화(1순위)
    int Hp = 20;
    int MaxAtt = 20;
    int MinAtt = 20;
    int Def = 20;
    int Crit = 20;
    int avoid = 20;

    Weapon Ak47 = Weapon();
    Potion HealingPotion = Potion();

    void TestFunction()
    {

    }
public:
    //  클래스 생성자는 클래스 이름과 동일해야한다
    //  클래스의 생성자는 리턴값이 클래스의 객체이기 때문에 리턴값이 없다.
    //  객체없이 호출이 가능하다. 일반적인 클래스의 함수는 무조건 객체가 필요하다.
    //  즉 객체를 만들어야하는 함수가 객체를 필요로 하면 모순이기 때문에 예외로 둔다.

//  멤버이니셜라이저(2순위)
    Player()
        : Hp(30)
        , MaxAtt(30)
        , MinAtt(30)
        , Def(30)
        , Crit(30)
        , avoid(30)
    {
        Hp = 0;
    }
};

class Magition
{
public:
    int Hp;
    int Mp;
    int DEF;
    int INT;

public:
    Magition(int _Value1, int _Value2)
    {

    }
};

int main()
{
    //  생성자는 기본적으로 함수로 인식된다.
    //  클래스를 만들었지만 정의되지 않는 행동을 할 수 있다면,
    //  컴파일러가 행동을 추가했고, 이를 생략했다.

    //  멤버 이니셜라이저 리스트
    Magition Cleric = { 2, 30 };

    //  클래스의 멤버함수는 무조건 객체가 필요하다
    Player NewPlayer = Player();
    NewPlayer.TestFunction();
}