

#include <iostream>

//  namespace는 개체를 구분하는 이름 식별자이다.
//  프로그램이 복잡해질때 여러 라이브러리 상에서 내부 식별자 간에 충돌이 일어날 가능성이 커진다.

//  using은 namespace의 전미에 붙이며 namespace를 쓸때마다 namespace를 생략할 수 있다.
//  하지만 일반적으로 사용하지 않는것이 좋다.

namespace AProgramer
{
    class Character
    {
    public:
        int Att = 50;
        int Def = 20;
    };
}

namespace BProgramer
{
    class Character
    {
    public:
        int Att = 90;
        int Def = 10;
    };
}


int main()
{


    AProgramer::Character NewChracterA;
    BProgramer::Character NewChracterB;

    //  std는 c++의 표준 라이브러리이다.

}