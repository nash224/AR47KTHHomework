
#include <iostream>
//  이름이 있는 함수나 그 외부에 있는 변수들은 지역변수라고 부른다.

int GlobalValue = 0;

int main()
{
    {
        //  특정 스코프에 속하는 것을 지역이라고 한다.
    }

    for(int i = 0; i <5; i++)
    {
        GlobalValue++;
    }

    int a = 0;
}

//  여기도 전역변수를 선언할 수 있지만, 메인함수보다 밑에 있으므로 메인함수가 읽지 못해 의미가 없다.