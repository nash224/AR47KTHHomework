// 061_VirtualSize.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test
{

};

class FightUnit
{
public:
    int GetAtt()
    {
        return Att;
    }

private:
    int Hp = 100;
    int Att = 10;

};

class Monster : public FightUnit
{
public:
    // GetAtt()

private:
    // Hp
    // Att
};

class Player : public FightUnit
{
private:
    int Lv = 1;
    int Equip = 1;
};

class BossMonster : public FightUnit
{

};

// 다형성은 클래스 상속과 가상 함수와 함깨 구현이 된다. 다형성 = (상속, 가상함수)
// 부모 클래스가 자식 클래스로 상속을 하게 되면 
// 상속받은 멤버 함수 중에서 일부를 재정의할 수 있다.
// 이로써 같은 이름의 함수가 다른 기능을 수행할 수 있다.



void FightScene(FightUnit* _Player, FightUnit* _Monster)
{

}

//// 내 게임에 있는 존재끼리 싸울 때 사용하는 함수
//void FightScene(Player* _Player, Monster* _Monster)
//{
//
//}
//
//
//void FightScene(Player* _Player1, Player* _Player2)
//{
//
//}
//
//void FightScene(Player* _Player, BossMonster* _BossMonster)
//{
//
//}


int main()
{
    {
        int ClassValue = sizeof(Test);

        Test ValueTest;
        Test ValueArrTest[20];

        int Instancevalue = sizeof(ValueTest);
        int instanceArrvalue = sizeof(ValueArrTest);

        int a = 0;
    }

    {
        Player NewPlayer;
    }
}
