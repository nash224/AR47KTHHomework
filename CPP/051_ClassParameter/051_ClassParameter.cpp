
#include <iostream>
#include <conio.h>

class Player
{
public:
    int Value0;
    int Value1;
    int Value2;
    int Value3;
    int Value4;
    int Value5;
    int Value6;
    int Value7;

};

// 플레이어가 1마리도 없을 가능성이 있다면
void StatusRenderPtr(const Player* _Player)
{
    // 방어코드라고 합니다.
    if (nullptr == _Player)
    {
        return;
    }

    //_Player->Value0 = 20;

}

// 플레이어가 1마리도 없을 가능성이 있다면
void StatusRenderRef(const Player& _Player)
{

}

int Value;

Player NewPlayer;

int ReturnFunction()
{
    return 10;
}

//  함수가 종료되면 변수도 해제되기 때문에 참조를 빈공간에서 하게 된다.
int& ReturnFunctionRef()
{
    int Value = 20;

    return Value;
}

void FunctionTest(int* _Ptr)    //  8바이트의 메모리
{

    NewPlayer.Value0 = 20;

    return;
}

int main()
{
    int TestValue = 20;

    FunctionTest(&TestValue);


    // ReturnFunctionRef() = 20;

    if (ReturnFunction())   //  반환 메모리가 4바이트임으로 가능
    {

    }

    // 접근해서 수정할수 없다.
    int Value = ReturnFunction();   //  
    if (Value)
    {

    }

    Value = sizeof(Player);

    while (true)
    {
        char Ch = _getch();

        printf_s("%d\n", Ch);
    }

    std::cout << "Hello World!\n";
}