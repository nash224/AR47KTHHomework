
#include <iostream>

int main()
{
    for (int i = 10; i != 0; i--)
    {
        printf_s("%d번째 실행\n", i);
        if (i == 5)
        {
            continue;
        }
        else if (i == 2)
        {
            break;
        }
    }
}