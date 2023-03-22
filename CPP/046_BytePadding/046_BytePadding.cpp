// 046_BytePadding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// short 2바이트 정수형;

class Player
{
public:
    int Hp;          // 4
    short Value3;    // 4
    int Value4;      // 4
    short Value9;    // 4
    char TTT;

    // 8바이트 이하 가장큰 바이트의 자료형을 찾아요.
    // 4바이트
    // 먼저 4바이트를 할당했다고 쳐보자
    // 딱맞거나 들어갈수 있으면 그대로 픽스
    // 4바이트 할당한다.
    // char
    // 8바이트
};

class Monster
{
public:
    int Hp = 10;
    int Value1 = 2;
    //short Value2 = 6;
    int A = 70;
    __int64 Address555;
};

int main()
{
    Player NewPlayer;

    int* Ptr = &NewPlayer.Hp;

    int Size = sizeof(Player);

    printf_s("%d\n", Size);

    Monster NewMonster;
    int Size2 = sizeof(Monster);

    printf_s("%d\n", Size2);

    int value04 = 0;

    int* Ptr1 = &NewMonster.Hp;
    __int64 Address1 = (__int64)Ptr1;
    
    int* Ptr2 = &NewMonster.Value1;
    __int64 Address2 = (__int64)Ptr2;
   
    int* Ptr3 = &NewMonster.A;
    __int64 Address3 = (__int64)Ptr3;


    int a = 0;

}