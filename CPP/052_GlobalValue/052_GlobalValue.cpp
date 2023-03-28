
#include <iostream>

//  c++은 전역을 선언할 수 있어 절차지향도 쓰기 떄문에 완전 객체지향 언어가 아니다.

//  이런 전역변수는 기억을 못할 가능성이 높음

class int2
{
private:
    int level;
    int Exp;

public:
    int2(int _level, int _Exp)
        : level(_level)
        , Exp(_Exp)
    {

    }
};

class Player 
{
private:
    //  클래스에서 전역변수로 사용할 수 있다.
    //  메모리 위치는 데이터 영역에 있다.

    //  현재까지 모든 플레이어 수

public:
    //  Player 클래스에 속한 전역변수, 플레이어 클래스에서만 사용할 수 있음
    static int Playercount;

    int Exp = 0;

    int2 LevelAndExp = int2(3, 260);

    static const int PlayerSize = 3;
    int value = 0;
    //int Print();

    int Arr[Player::PlayerSize][Player::PlayerSize] = { 0, };

    Player()
    {

        Playercount++;

    }

    int GetALLPlayercount()
    {

        return Playercount;
    }


    
    //void print();
};

//  실체를 둔다.
int Player::Playercount = 0;


int main()
{
    

    Player NewPlayer0;
    Player NewPlayer1;
    Player NewPlayer2;
    Player NewPlayer3;




    //  클래스::플레이어의 전역변수이다.
    //  플레이어의 속성에 속한 전역변수
    //Player::Playercount = 20;


    int count = NewPlayer3.GetALLPlayercount();

    //Player::value = 10;

    //print();

    std::cout << "Hello World!\n";
}