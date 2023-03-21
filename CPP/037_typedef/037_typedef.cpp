
#include <iostream>

//  유저가 정의한 자료형이라고 한다.

int main()
{
    typedef __int64 __time64;

    typedef __time64 time_t;

    typedef int myint;

    typedef myint mymyint;

    using time_t = int;

    {
        time_t ttt = 30;

        int value = 100;

        time_t DayTime = time(0);


    }
}