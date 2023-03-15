
#include <iostream>

//  코드가 쳐지면 램의 어딘가에
//  위치와 크기가 있어야한다.

int main()
{
    //  포인터는 자료형 뒤에 *을 붙여서 선언한다.

    {   //  2진수와 16진수 그리고 포인터의 자료형의 관계

        int result = 0;
        //  일반적인 자료형이 가능하고 
        bool* PtrB;
        int* PtrI;

        //  포인트의 자료형의 주소값은 16진수의 주소값으로 되어 있기 때문에 그 숫자를 표현하기 위해 8byte로 동일하다.
        //  즉 주소값의 크기는 다르지 않다.

        result = sizeof(PtrB);
        result = sizeof(PtrI);

        //  2진수와 16진수의 표현법
        int BNumber = 0b00000000000000000000000000000000;
        int Hex = 0xffffffff;
        //                    101112131415
        // 0 1 2 3 4 5 6 7 8 9 a b c d e f

        //                                8421
        // 0b0000000000000000000000000000 0101;
        // 0x   f   f   f   f   f   f   f    5;

        //  형변환은 어떤 자료형을 다른 자료형으로 변경하는 것이다.
        //  이를 가상 주소 공간이라고 한다.

        int TestDataType = 10;

        __int64 Address01 = 0;
        Address01 = (__int64)TestDataType;
        result = sizeof((__int64)TestDataType);
       

        

        int a = 0;
    }

    {   //  포인터의 사용법
        
        int value = 10;
        //  value는 value의 주소값과 내용값이 존재한다.

        //  *는 참조연산자이며, &은 주소 연산자라고 한다.
        int* Pvalue = &value;
        // 참조연산자는 주소에 가리키는 값을 의미한다.



        //  예) &value는 0x0053라면, Pvalue는 
        
        int a = 0;
    }
}

//  === 핵심요약 ===

//  이름에는 2가지의 의미가 있다.
//  그것은 주소와 값이다.

//  자료형은 변경이 가능하다.

