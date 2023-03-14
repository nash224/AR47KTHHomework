
#include <iostream>
// 컴파일에 따라 안될수도 있다.
inline void Test()
{
    printf_s("Hello, World!!!");
}

//  함수의 실행시간이 매우 짧다면, 함수 호출에 걸리는 시간이 부담이 될 수 있다.
//  함수의 호출 시간을 줄이기 위한 함수이다.

int main()
{
    //  함수의 내용을 복붙하는 함수이다.
    Test();
    //  printf_s("Hello, World!!!"); 
}