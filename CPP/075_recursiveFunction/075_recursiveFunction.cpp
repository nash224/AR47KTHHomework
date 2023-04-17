// 075_recursiveFunction.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Count = 0;

void Test()
{
    int ArrValue[100] = { Count };

    printf_s("%d %d\n", Count, ArrValue[0]);
    ++Count;


    // 스택오버플로우를 주의해야 한다.
    if (10000000 <= Count)
    {
        return;
    }

    return Test();
}

int Test2()
{
    // 리턴에다가 재귀를 거는 경우에는
    // 꼬리재귀라는 것이 될 가능성이 생기고
    // 꼬리재귀를 할줄안다 모른다는 별로 중요한 내용은 아니야.
    // 그냥 던지는거지 
    if (true)
    {
        return 20;
    }


    // 리턴과 동시에 
    return Test2();
}

int main()
{
    // Test();
}
