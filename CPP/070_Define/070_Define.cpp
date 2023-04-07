// 070_Define.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 그냥 복붙
#define TEN 10


// 함수를 사용할 수도 있다
// 이를 매크로 함수라고 한다.
// 매크로 함수는 무조건 복붙이다 
#define PLUS(Value1, Value2) Value1 + Value2

#define MYTEST(Value1) Value1 = 0


void Test(int Value)
{

}

int main()
{
    int* Ptr;

    MYTEST(Ptr);

    /*PLUS("aaa");*/
    // "aaa" + "aaa"

    // TEN * TEN;
    // 10; * 10;
    TEN * TEN;

    std::cout << "Hello World!\n";
}
