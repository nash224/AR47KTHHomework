
#include <iostream>

//  어느 영역에도 속하지 않으면 전역이라고 한다.
//  전역에는 변수와 함수를 선언할 수 있다.
int GlobalValue = 20;

//  사용자 정의 자료형(클래스) 내부의 공간을 맴버 공간이라고 한다.
class Player
{
private:    //  클래스의 접근 제한 지정자는 명확하게 선언하는 것이 좋다.
    //  맴버공간에서 변수를 선언하면 맴버변수라고 한다.
    int Hp = 105;

public:
    //  맴버공간에서 함수를 선언하면 맴버함수라고 한다.
    void Damage(int _Att)
    {
        int value = 20;
    }
};

void Test()
{

}

int main()
{
    int Att = 5;

    Player NewPlayer;
    NewPlayer.Damage(Att);
}