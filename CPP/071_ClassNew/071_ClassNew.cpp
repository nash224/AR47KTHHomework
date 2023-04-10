// 071_ClassNew.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test
{
    char* ArrChar;

public:
    void Resize(size_t Size)
    {
        ArrChar = new char[Size];
    }
};

int main()
{
    char* ArrChar = new char();

    delete ArrChar;

    Test* ArrTest = new Test[10];

    delete[] ArrTest;
}
