// 066_ArrayHeap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시. 
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
    // 정적 바인딩
    // 배열의 수가 정해져있고 코드가 실행되면 배열 메모리영역의 크기가 바뀌지 않음
        int Arr[10];
        int* StaticArr = Arr;
        StaticArr[0];
    }


    {
        // 동적 바인딩
        // 힙을 사용하는 행위가 동적 바인딩을 의미한다.

        int* DynamicPtr = new int[100];

        // 동적 메모리를 해제할 때는 자신만의 방식으로 삭제해야한다.
        
        if (nullptr != DynamicPtr)
        {
           
            delete[] DynamicPtr;
            DynamicPtr = nullptr;
        }

        // 동적 배열 메모리를 delete로 해제할 때 전부 지워지지않을 가능성이 존재한다.
        // => 메모리 누수 초래
        // 따라서 delete[]를 써주는 것이 필수이다.


    }
}