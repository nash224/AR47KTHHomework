
#include <iostream>

int main()
{
    //  2차원으로 표현하지만 사실은 1차원의 메모리에서 표현


    int Arr[3][2] = { {1,2},{3,4}, {5,6}};

    __int64 Address00 = (__int64)&Arr[0][0];
    int value00 = Arr[0][0];
    __int64 Address01 = (__int64)&Arr[0][1];
    int value01 = Arr[0][1];
    __int64 Address10 = (__int64)&Arr[1][0];
    int value10 = Arr[1][0];
    __int64 Address11 = (__int64)&Arr[1][1];
    int value11 = Arr[1][1];
    __int64 Address20 = (__int64)&Arr[2][0];
    int value20 = Arr[2][0];
    __int64 Address21 = (__int64)&Arr[2][1];
    int value21 = Arr[2][1];
    //  주소값은 4바이트씩 증가되는 것을 확인함

    int a = 0;
}