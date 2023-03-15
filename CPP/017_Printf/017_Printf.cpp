
#include <iostream>

int main()
{
    //  콘솔창에 글자를 출력한다.
    //printf_s("printtest");

    char Arr[5] = { '1','2','3','4',0 };

    //  long long value01 = Arr;
    //  char value02 = Arr;
    //  자료형이 다르기 때문에 대입이 안된다.

    int value0 = Arr[0];
    int value1 = Arr[1];
    int value2 = Arr[2];
    int value3 = Arr[3];
    int value4 = Arr[4];
    int value5 = Arr[5];    // 배열의 끝에 0 대신 Arr[5]를 집적 넣어주었다.

    printf_s(Arr);
}

//  === 핵심요약 ===

//  printf는 콘솔창에 글자를 출력한다.