
#include <iostream>

void EquipPtrNull(int* _PValue)
{

}
void EquipPtr(int* _PValue)
{
    *_PValue = 200;
}

void EquipRef(int& _Ref)
{
    _Ref = 300;
}

int main()
{

    {// 포인터 복습

        int TypeV = 0;

        int value01 = 10;
        int* PtrV01 = nullptr;
        PtrV01 = &value01;

        TypeV = sizeof(*PtrV01);
        TypeV = sizeof(PtrV01);

        int a = 0;

    }


    {
        //  레퍼런스는 포인터와 마찬가지로, 메모리의 다른 위치에 있는 개체 주소를 참조한다.
        int value01 = 10;
        int* PtrV01 = nullptr;
        PtrV01 = &value01;

        int& RefV01 = value01;
        RefV01;

        RefV01 = 50;

        int TypeRef = 0;

        TypeRef = sizeof(RefV01);
        //  하지만 참조는 포인터와 달리 다시 초기화할 수 없으며, null로 설정할 수 없다.
        //  즉 내용값은 바꿀 수 있어도 주소값은 한번 정하면 다시 대입할 수 없다.


        int a = 0;


    }
    std::cout << "Hello World!\n";


    {
        int value0 = 0;
        int* Ptr01 = &value0;



        EquipPtrNull(nullptr);
        EquipPtr(Ptr01);

        int& Ref = value0;
        EquipRef(Ref);

        value0;

        int a = 0;


    }
}

//  === 핵심요약 ===
//
//  참조는 특정 변수의 주소를 참조의 주소값에 대입할 수 있다.
//  참조는 Null로 지정할 수 없고 주소값은 한번만 정할 수 있다. (내용값은 바꿀 수 있다.)
//  즉 참조한 메모리 영역은 바꿀 수 없다.
// 
// 
//