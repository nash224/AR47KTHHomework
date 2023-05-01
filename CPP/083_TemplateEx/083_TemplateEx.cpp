// 083_TemplateEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Temp.h"


template<typename T>
void Print()
{
    std::cout << "<template T>" << std::endl;
}

// 템플릿 특수화 : 묵시적으로 형을 정해주고, 형이 같은 템플릿 함수가 실행될 때
// 특수화된 템플릿 함수가 우선순위로 호출된다.
template<>
void Print<float>()
{
    std::cout << "<float>" << std::endl;
}

int main()
{

    Print<int>();

    Print<float>();

    Print<double>();

    std::cout << "Hello World!\n";
}