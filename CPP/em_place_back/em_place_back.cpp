// em_place_back.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>


class float4
{
public:
    float4() 
    {
        
    }
    ~float4() {}

    float4(float _x, float _y, float _z, float _w)
        : x(_x), y(_y), z(_z), w(_w)
    {

    };

    float x;
    float y;
    float z;
    float w;
};


class MyClass
{
public:
    MyClass()
    {
        std::cout << "기본생성자 호출\n";
    }

    ~MyClass()
    {
        std::cout << "소멸자 호출\n";
    }

    MyClass(float4 _Scale, float4 _Position, float4 _Rotation)
        : Scale(_Scale), Position(_Position), Rotation(_Rotation)
    {
        std::cout << "복사생성자 호출\n";
    }

public:
    float4 Scale{2.0f,3.0f,4.0f,1.0f};
    float4 Rotation = float4();
    float4 Position;
    
};


int main()
{
    const int vecPushbackSize = 10;
    std::vector<MyClass> vecMyclass;
    vecMyclass.reserve(vecPushbackSize);

    for (int i = 0; i < vecPushbackSize; i++)
    {
        MyClass Monster = MyClass{ float4{ 5.0f,5.0f,5.0f,1.0f }, float4{5.0f, 3.0f, 2.0f, 1.0f},float4{ 5.0f,5.0f,5.0f,1.0f } };

        vecMyclass.push_back(Monster);
    }

    std::cout << "===============================================================\n";


    std::vector<MyClass> vecMy_emplace_back_class;
    vecMy_emplace_back_class.reserve(vecPushbackSize);
    for (int i = 0; i < vecPushbackSize; i++)
    {
        vecMy_emplace_back_class.emplace_back();
    }

    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
