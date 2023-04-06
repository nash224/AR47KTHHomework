// Homework0405.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "GameEngineArray.h"

int main()
{
    // 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시. 
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    {
        // 컴파일러에서 지원하느 Arr형에서는 
        // operator = 함수를 구현하지 않았다.
        int Arr0[10] = { 0, 1, 1 , 1 , 1 , 1 , 1 };
        int Arr1[10];
         //Arr1 = Arr0; // Error(E0137) >> 식을 수정할 수 있는 lvalue여야 합니다 
    }

    {   
        // ArrPtr에 동적할당 메모리 20개를 담는다.
        int* ArrPtr = new int[20]; // 시작주소 600번지

        delete[] ArrPtr;
        ArrPtr = nullptr;

        // ArrPtr에 다시 동적할당 메모리 10개를 담는다.
        ArrPtr = new int[10]; // 시작주소 700번지
        // 즉 30개의 동적할당된 메모리가 생성했다.

        // 하지만 다시 주소를 지정하면서 이전에 있던 주소의 메모리는 잃어버리게 된다. (댕글링 포인터)

        delete[] ArrPtr;
        ArrPtr = nullptr;
        
    }

    {
        // DynamicArray의 객체를 Heap에 10개 생성
        GameEngineArray DynamicArray(10);

        for (size_t i = 0; i < DynamicArray.GetCount(); i++)
        {
            // 각 객체의 동적 배열에 지정된 수를 넣어주겠다.
            DynamicArray[i] = i;
        }

        int Arrayvalue1 = DynamicArray[1];

        //DynamicArray.ReSize(5);
        DynamicArray.ReSize(5);

        int Arrayvalue2 = DynamicArray[2];

        //for (size_t i = 0; i < DynamicArray.GetCount(); i++)
        //{
        //    printf_s("DynamicArray[%d] : %d \n", i, DynamicArray[i]);
        //}
    }

    {
        GameEngineArray Array0(10);
        GameEngineArray Array1(5);

        Array0.ReSize(5);
        Array1 = Array0;
    }
    
    
}
