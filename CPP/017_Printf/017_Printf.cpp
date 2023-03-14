
#include <iostream>

int main()
{
    //  콘솔창에 글자를 출력한다.
    //printf_s("printtest");

    char Arr[5] = { '1','2','3','4',0 };

    long long value01 = Arr;
    //  자료형이 다르기 때문에 대입이 안된다.

    int value0 = Arr[0];
    int value1 = Arr[1];
    int value2 = Arr[2];
    int value3 = Arr[3];
    int value4 = Arr[4];
    int value5 = Arr[5];

    printf_s(Arr);
}
