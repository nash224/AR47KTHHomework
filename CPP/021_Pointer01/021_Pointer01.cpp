
#include <iostream>

//  파라미터가 int이기 때문에 주소값은 초기 주소값 + 4byte씩 올라간다.
void Test(int _A, int _B, int _C)
{
    int* valueP0 = &_A;
    int* valueP1 = &_B;
    int* valueP2 = &_C;

    __int64 Address0 = 0;
    __int64 Address1 = 0;
    __int64 Address2 = 0;

    Address0 = (__int64)valueP0;
    Address1 = (__int64)valueP1;
    Address2 = (__int64)valueP2;

    //  연속된 변수 이름은 메모리에서 봤을때 주소값이 붙어있지 않고 일정한 간격으로 띄워져있다.
    //  연속된 이름의 변수 사이에는 다른 주소의 메모리가 존재한다.
}

int main()
{

    {// 배열포인터
        
        int Arr[5] = {};

        int* ArrP0 = &Arr[0];
        int* ArrP1 = &Arr[1];
        int* ArrP2 = &Arr[2];
        int* ArrP3 = &Arr[3];
        int* ArrP4 = &Arr[4];

        __int64 Address0 = 0;
        __int64 Address1 = 0;
        __int64 Address2 = 0;
        __int64 Address3 = 0;
        __int64 Address4 = 0;

        Address0 = (__int64)ArrP0;  //  0x0536  주소값이 4byte씩 증가된다.
        Address1 = (__int64)ArrP1;  //  0x053a
        Address2 = (__int64)ArrP2;  //  0x053e
        Address3 = (__int64)ArrP3;  //  0x0532
        Address4 = (__int64)ArrP4;  //  0x0536


        int a = 0;
    }
    



    {   //  인자를 전달받은 함수안에서의 포인트 구조

        int FuncP01 = 333;
        int FuncP02 = 333;
        int FuncP03 = 333;

        Test(FuncP01, FuncP02, FuncP03);


        
    }
}

//  === 핵심요약 ===
//
// 