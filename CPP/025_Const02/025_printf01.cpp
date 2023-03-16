
#include <iostream>

int main()
{
    printf_s("asdasd");

    {
        int value0 = 40;
        int value1 = 10;

        int* PtrV = &value0;

        const int* cPtrV = &value1;

        //  포인터 참조연산자

        //  포인터형 변수에서 *의 위치에 따라 자료형이 달라진다.
        //*cPtrV = 20;  //  const int* 포인터 자료형을 선언했기 때문에 초기화가 안된다.


    }

    {
        char ch1 = 'a';

        const char* Pch1 = &ch1;


        char ch2 = 'b';
        char* const Pch2 = &ch2;
        


        const char* const Pch3 = &ch2;




        int AddressCh1 = (__int64)Pch1;
        int AddressCh2 = (__int64)Pch2;
        

        printf_s(Pch1);

        printf_s(Pch2);
        int a = 0;
    }


    std::cout << "Hello World!\n";
}

//  === 핵심요약 ===

//  포인터 변수를 사용할때 *의 위치에 따라 의미가 달라진다.
//  const int* const Num와 같은 자료형이 있을때, Num의 주소값과 내용값은 변경하지 못한다.
//  내용값   | 주소값 Num