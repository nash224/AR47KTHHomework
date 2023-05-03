// 085_Float.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // int로 바꾸면? 0
    int Value = 1.1f;
    float Valuef = 1.00001f;
    Valuef += 1.00001f;

    if (Valuef == 2.00002f)
    {
        int a = 0;
    }

    for (size_t i = 0; true; i++)
    {
        static int count = 0;

        if (count%10000000 == 0)
        {
            std::cout << "fashdjklfashdjklfasdhjklfhasdjklfhajsdklfhjkladsfhjklasdhfjklads" << std::endl;
        }
        count++;
    }


}
