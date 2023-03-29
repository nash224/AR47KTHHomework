
#include <iostream>

void Function() //  Function
{
    printf_s("void Function()\n");
}

void Function(int _value)   //  Function int
{
    printf_s("void FUnction(int _value)\n");
}

void Function(int _value, int _Test)   //  Function int int
{
    printf_s("void FUnction(int _value, int _Test)\n");
}

void Function(short _value, int _Test)   //  Function int int
{
    printf_s("void FUnction(short _value, int _Test)\n");
}

//  함수라고 불리는 것은 모두 적용할 수 있다.

class Player
{
public:
    Player()
    {

    }
    Player(int _value)
    {

    }
    Player(int _value1, int _value2)
    {

    }
    /*Player(int _value1, int _value2)
    {

    }*/ //  이미 선언되어 있음


    void Function() //  Function
    {
        printf_s("void Function()\n");
    }

    void Function(int _value)   //  Function int
    {
        printf_s("void FUnction(int _value)\n");
    }

    void Function(int _value, int _Test)   //  Function int int
    {
        printf_s("void FUnction(int _value, int _Test)\n");
    }

    void Function(short _value, int _Test)   //  Function int int
    {
        printf_s("void FUnction(short _value, int _Test)\n");
    }

    //  함수라고 불리는 것은 모두 적용할 수 있다.



};


//  리턴값은 함수 오버로드에 영향을 주지 않느다.


int main()
{
    Function();
    Function(30);
    Function(20, 40);
    Function((short)20, 40);

    Player New0 = Player(10, 20);
    Player New1 = Player();
    Player New2 = Player(20);

    New0.Function();
    New0.Function((short)5, 6);
}
