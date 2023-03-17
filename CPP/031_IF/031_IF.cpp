
#include <iostream>

int main()
{
    //  if (메모리영역)
    //  {
    // 
    //      실행코드
    // 
    //  }
    //  메모리 영역이 참이면 코드가 실행
    //                거짓이면 코드 실행 x
    // 
    //

    int value = 5;

    if (value == 5)
    {
        printf_s("코드실행:if\n");
    }

    if (value != 5)
    {
        printf_s("코드실행:if\n");
    }
    else if (value > 4)
    {
        printf_s("코드실행:elseif\n");
    }

    if (value != 5)
    {
        printf_s("코드실행:if\n");
    }
    else if (value < 4)
    {
        printf_s("코드실행:elseif\n");
    }
    else if (value != 5)
    {
        printf_s("코드실행:elseif\n");
    }


    if (value != 5)
    {
        printf_s("코드실행:if\n");
    }
    else if (value < 4)
    {
        printf_s("코드실행:elseif\n");
    }
    else if (value != 5)
    {
        printf_s("코드실행:elseif\n");
    }
    else
    {
        printf_s("뭐가 실행된거죠?\n");
    }


}
