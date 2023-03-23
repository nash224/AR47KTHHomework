
#include <iostream>

//  클래스 연산자는 사용자 정의 연산자라고 하며, 
//  클래스에서 연산자를 지정할 수 있다.

class Test
{
private:
    int value;

public:
    Test(int _value)
        : value(_value)
    {

    }

    int operator+(int _value)
    {
        return value + _value;
    }

    bool operator==(int _value)
    {
        return value == _value;
    }

    int operator[](size_t _value)
    {
        return value;
    }
    
};

int main()
{
    Test value = 10;
    value + 10;

    if (value == 10)
    {
        printf_s("Hello,World!!");
    }

    int Member = value[2000];
    
}