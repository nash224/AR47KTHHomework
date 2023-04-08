// 068_DeepCopyAndShollowCopy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A
{
public:
    //int* Newint = new int();
    int* Newint = nullptr;

    void Create()
    {
        Newint = new int();
    }

    void operator=(const A& _Other)
    {

        // 얕은 복사
        //Newint = _Other.Newint;

        if (nullptr == _Other.Newint)
        {
            // 상대가 nullptr일때  나도 메모리를 해제하고 
            // nullptr을 대입받은 후, 리턴 
            if (nullptr != Newint)
            {
                delete Newint;
                Newint = nullptr;
            }

            return;
        }

        if (nullptr == Newint)
        {
            // 딥카피의 준비를 한것
            // 내 그릇을 생성 
            Create();
        }


        // 각 클래스가 자신만의 메모리를 만들어야함.
        // 기존에 객체의 동적할당 받았던 메모리의 내용에 
        // 참조받은 객체의 동적할당 받은 메모리의 내용을 대입받음
        *Newint = *_Other.Newint;

        // 대입받은 상대의 Newint의 값이 nullptr이라면
        if (nullptr == Newint)
        {

            // 리턴
            return;
        }



    }

    ~A()
    {
        if (nullptr != Newint)
        {
            delete Newint;
            Newint = nullptr;
        }
    }
};

int main()
{
        // 윈도우 전용 삭제하지 않은 힙 메모리 출력 표시. 
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    {
        // 0바이트 누수?
        //int* NewInt4 = new int[0];


        A NewInt0; // 0x05 = H0x01
        
        A NewInt1; // 0x10 = H0x02

        NewInt0.Create();
        
        
        NewInt0 = NewInt1; // 얕은 복사일 때, 0x05 = H0x02 => H0x01 ㅇㄷ? => 하나를 잃어버림
    }// 해제할때, 2중 참조된 메모리를 둘 다 해제하게되면 처음으로 해제할 땐 정상적으로 해제가 되지만
    // 한번 더 해제할 때는 프로그램이 터져버리게 됨
    //

    // 2중 참조
    int* NewInt0 = new int();
    int* NewInt1 = NewInt0;

    if (nullptr != NewInt0)
    {
        delete NewInt0;
        NewInt0 = nullptr;
    }

    // NewInt1 = ???????

}
