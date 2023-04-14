// 073_InnerClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

template<typename DataType>
class Test
{
public:
    // 이걸 이너클래스 문법이라고 하고.
    class publicInner
    {
    public:
        DataType InnerValue;

    public:
        publicInner()
        {
        }
    };

    //void Function() 
    //{
    //    InnerValue = 20;
    //}

private:
    // 이걸 이너클래스 문법이라고 하고.
    class privateInner
    {

    };

public:
    int Value = 0;
};

int main()
{
    Test<int>::publicInner Innter;
    // Test::publicInner

    std::cout << "Hello World!\n";
}
