// Test4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <list>
#include <string>



union DynamicA
{
    struct
    {
        int A;
        int B;
    }u;

    struct
    {
        __int64 A;
        __int64 B;
    }u2;
};

int main()
{
    DynamicA NewA;

    int size = sizeof(NewA);

    std::cout << size << std::endl;

    NewA.u.A = 50;


    int a = 0;
}