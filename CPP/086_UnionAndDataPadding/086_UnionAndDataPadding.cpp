// 086_UnionAndDataPadding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//typedef union _MyClass {
//} MyClass;


//typedef union _LARGE_INTEGER {
//    struct {
//        int LowPart;
//        int HighPart;
//    };
//    struct {
//        DWORD LowPart;
//        LONG HighPart;
//    } u;
//    LONGLONG QuadPart;
//} LARGE_INTEGER;

union LARGE_INTEGER
{
    // 곧바로 변수화 시켜서 내부에서 사용하는 문법.
    struct {
        int LowPart;
        int HighPart;
    } u;
    __int64 QuadPart;
};

class Player
{
public:
    struct MyCalss
    {
        int LowPart;
        int HighPart;
    };

    MyCalss u;
    __int64 QuadPart;
};

class tPlayer
{
public:
    // 300 번지부터 304
    int LowPart;
    // 304 번지부터 308
    int HighPart;
    // 308 번지부터 316
    __int64 QuadPart;
};

// 메모리의 구성을 변수가 존재한다면
union UPlayer
{
public:
    // 내부에 의미있는 변수가 있다면
    // 그중 가장 큰 변수를 중심으로 같은 위치에 다른 이름을 준다.
    // [][][][]

    // 300번지 308
    __int64 C = 0;
    // 300번지 304
    int A;
    // 300번지 304
    int B;
};

class MyUniCalss
{
public:
    union
    {
        int a;
        int b;
    };

    class
    {
    public:
        int x;
        int y;
    };
};

struct TestStruct
{
    int a;
    int b;
};


union LastUnion
{
    // 300번지 8바이트
    TestStruct ValueAB;

    // 300번지 8바이트
    __int64 Test;
};



int main()
{
    {
        LastUnion New;

        New.ValueAB.a = 10;

        int size = sizeof(LastUnion);


        int a = 0;
    }



    {
        MyUniCalss New;

        New.a = 10;

        int size = sizeof(MyUniCalss);


        int a = 0;
    }

    {
        // 200번지에 만들어졌다고 칠께요.
        Player NewPlayer;

        // 200번지 부터 204번지 까지 사용하겠다.
        NewPlayer.u.LowPart;

        // 204번지 부터 208번지 까지 사용하겠다.
        NewPlayer.u.HighPart;

        // 208번지 부터 216번지 까지 사용하겠다.
        NewPlayer.QuadPart;

        int Value = sizeof(Player);

        int a = 0;
    }

    {
        // 300번지.
        UPlayer NewPlayer;

        // 00000001 00000000 00000000 00000000 00000000 00000000 00000000 00000000

        // 300번지 304번지를 사용하겠다.
        NewPlayer.A = 1;

        // 300번지 304번지를 사용하겠다.
        NewPlayer.B;

        NewPlayer.C;

        int Value = sizeof(UPlayer);

        int a = 0;
    }


    std::cout << "Hello World!\n";
}