// GameEngineVector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
// stl자료구조 입니다.
#include <vector>
#include <GameEngineBase/GameEngineDebug.h>

// vector는 배열을 대체합니다. 
// 조금 특징이 다릅니다.

// 일반적인 배열 바로 접근이 가능하다.
// [][][][][][][][][][접근]

// 벡터 10개를 만들고도
// [][][][][][][][][][]

typedef int DataType;

class MyVector
{

public:
    MyVector()
    {

    }

    void push_back(const DataType& _Value)
    {
        //  0           0
        // 배열크기가 감당할수 있나?
        if (Size + 1 > Capacity)
        {
            // 더 크게 할당하자.
            reserve((Capacity + 1) * 1.5);
            // 확장해야 합니다.
        }

        ArrData[Size] = _Value;
        ++Size;
    }

    void reserve(const size_t _Value)
    {
        DataType* NewPtr = new DataType[_Value];
        size_t CopySize = _Value < Capacity ? _Value : Capacity;

        for (size_t i = 0; i < CopySize; i++)
        {
            NewPtr[i] = ArrData[i];
        }

        if (nullptr != ArrData)
        {
            delete[] ArrData;
            ArrData = nullptr;
        }

        ArrData = NewPtr;
        Capacity = _Value;
    }

    void resize(const size_t _Value)
    {
        reserve(_Value);

        for (size_t i = Size; i < _Value; i++)
        {
            ArrData[i] = 0;
        }

        Size = _Value;
    }

    void PrintTest(size_t _value)
    {
        printf_s("Test %d번째 요소의 값 : %d\n", _value , this->ArrData[_value]);
    }

    size_t size()
    {
        return Size;
    }

    size_t capacity()
    {
        return Capacity;
    }

    DataType& operator[](size_t _Index) const
    {
        if (Size <= _Index)
        {
            MsgBoxAssert("인덱스를 오버하여 벡터를 사용하려고 했습니다.");
        }

        return ArrData[_Index];
    }

private:
    // 배열의 크기
    size_t Capacity = 0;
    // 넣어준 원소의 크기
    size_t Size = 0;

    DataType* ArrData = nullptr;
};

//class PArray 
//{
//    std::vector<>
//};

int main()
{

    {
        MyVector Test;

        /*Test.reserve(10);*/


        //for (size_t i = 0; i < Test.size(); i++)
        //{
        //    printf("Value %d\n", Test[i]);
        //}

        Test.resize(20);


        for (size_t i = 0; i < 13; i++)
        {
            Test.push_back(i);
            printf("Capacity %d\n", Test.capacity());
            printf("Size %d\n", Test.size());
        }

        for (size_t i = 0; i < Test.capacity(); i++)
        {
            Test.PrintTest(i);
        }



        printf_s("size : %d", (int)Test.size());
    }

    return 1;

    {
        std::vector<int> Test;

        //{
        //    // 배열 크기를 10개 할당함
        //    /*Test.reserve(10);*/

        //    for (size_t i = 0; i < 10; i++)
        //    {
        //        // 요소를 추가하고 값을 넣음
        //        Test.push_back(i);
        //        // Test의 용량을 출력
        //        printf("Capacity %d\n", Test.capacity());
        //        // Test의 요소의 수를 출력
        //        printf("Size %d\n", Test.size());
        //    }

        //    //for (size_t i = 0; i < Test.size(); i++)
        //    //{
        //    //    printf("%d\n", Test[i]);
        //    //}

        //    // printf_s("size : %d", (int)Test.size());

        //    return 1;
        //}


        {
            // push_back 10번을 한것과 똑같은 크기로 만들어준다.
            // 벡터에서는 이미 10개의 int를 공간을 확장하면서
            // 원소 자체도 넣어주는걸 resize라고 합니다.
            Test.resize(10);

            // 벡터는 넣는다는 개념이고. 
            // 최초 아무것도 없다.
            // Test
            // 내부에서 벌어지고 있으니까.
            // 이런 사용법은 vector를 사용하는 최악의 사용법으로 불린다.
            Test.push_back(0);
            // [0]
            Test.push_back(0);
            // [0][0]
            Test.push_back(0);
            // [0][0][0]
            Test.push_back(0);
            // [0][0][0][0]

            printf_s("size : %d", (int)Test.size());
        }
    }

    // Test.reserve(10);

    // Test.resize(10);
}
