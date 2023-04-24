// 080_TypeDefEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

typedef int MYINT, * MYTEST;

typedef wchar_t WCHAR, * HAMBERGER, * PIZZA, ** CHICKEN;

int main()
{
    int* Ptr0 = nullptr;
    MYTEST Ptr1 = nullptr;

    HAMBERGER Ptr2 = nullptr;

    HAMBERGER Arr[5] = {};

    CHICKEN PPtr = Arr;

    

    // wchar_t* LPWSTR;

    std::cout << "Hello World!\n";
}