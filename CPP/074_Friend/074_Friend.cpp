// 074_Friend.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class B;
class A
{
    // 특정 클래스에서 자신의 접근제한 지정자를
    // 취소시키는 문법
    // 내 속에있는걸 알려주고 싶을때
    friend B;

private:
    int Value = 0;
};

class C;
class B
{
public:
    // 객체지향을 정면에서 깨는 문법이니까.
    // 이런 문법을 사용하면 객체지향을 깨기 때문이다.
    // 애초에 c++ 객체지향 언어가 아니야.
    // 이종격투기 같은 애에요.
    // 발리투도 무기 무기칙 격투기 
    void Function(A& _Other)
    {
        _Other.Value = 20;
    }
    friend C;

private:
    int Peperoni = 5;
};

class C
{
public:
    void PizzaMake(B& _Other)
    {
        std::cout << _Other.Peperoni << std::endl;
    }
};

int main()
{
    A NewA;
    B NewB;
    C NewC;

    NewB.Function(NewA);

    NewC.PizzaMake(NewB);

    std::cout << "Hello World!\n";
}
