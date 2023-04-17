// 077_Cast.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A
{
    virtual void Test() {}
};

class B : public A
{
    int Hp;
    int Att;
    // virtual void Test() {}
};

class C : public A
{
    int Hp;
    int Def;
    // virtual void Test() {}
};


int main()
{
    // static_cast 메모리 크기만 다른 값대 값형식의 형변환에 사용된다.
    {
        short Test = 20;
        // c스타일 형변환
        int Value = (int)Test;
        // c++에서는 별로 권장하지 않는 방식이다.

        // 메모리 크기만 다를뿐 서로 값형태

        Value = static_cast<int>(Test);
        Value = /*static_cast<int>(*/Test/*)*/;
        Value = (int)Test; // <= static_cast<int>로 바꿉니다.

        // 부동소수점의 값을 정수형으로 변환할 때, 소수점 이하의 정보가 손실된다.
        // 상속관계에서는 실제로 가리키는 객체가 부모 클래스가 아닌 경우 문제가 발생할 수 있다.
        // => Down casting이면 문제가 발생한다.
        // 포인터와 참조형에서 쓸 수는 있지만, 역시 데이터 값이 바뀔 수 있으므로, 
        // dynamic_cast와 reinterpret_cast를 쓰는 것을 추천한다

        char Ch1 = 'a';
        int TestValue = static_cast<int>(Ch1); // 타입캐스트 연산자
        int a = 0;
    }

    // reinterpret_cast는
    // 정수를 포인터로 포인터를 정수로 변경할때 사용한다.
    {
        int Value = 3;

        int* Ptr = &Value;

        __int64 Address = reinterpret_cast<__int64>(Ptr);

        __int64 Address3 = (__int64)Ptr;

        int* Ptr2 = reinterpret_cast<int*>(Address);
        
        // 포인터나 참조타입을 다른 포인터나 참조타입으로 캐스티할 때 사용한다.
        // reinterpret_cast는 컴파일러가 타입간 변환이 안전한지 검사를 하지 않는다.
        // => 안전성을 보장받지 못함

        // 주의사항은 객체의 크기를 바꿀려고 할 때,
        // const 한정자를 제거하려고 할 때,
        // 가상함수 포인터를 사용하려고 할 때이다.
        // 때문에 reinterpret_cast는 안전하지 않는 형변환이기 때문에 다른 캐스팅을 이용하는 것이 좋다.
    }

    // dynamic_cast
    // 부모자식구조에서 사용됩니다. 다운캐스팅에 이용됩니다.
    {
        // 가상함수 테이블을 참조해서 다운캐스팅이 가능한지를 알아봐준다.
        //A NewA;
        //B NewB;

        //A* PtrA = &NewA;
        //B* PtrB = &NewB;

        {
            A* PtrB = new B();
            B* Test = dynamic_cast<B*>(PtrB);
            int a = 0;

            //A* PtrBTest = new B();
            //B* TestTest = PtrB;
        }

        {
            // 다운캐스팅을 안전하게 할수 있게 도와준다.
            A* PtrC = new C();
            B* Test = dynamic_cast<B*>(PtrC);

            // 이러면 심각한 오류가 생길수 있다.
            B* Test1 = (B*)PtrC;
            int a = 0;

            // dynamic_cast는 보완성이 높은 캐스트이며, 기본적으로 코스트가 높다.
            // dynamic_cast는 클래스의 가상 함수 테이블을 사용하여 타입변환을 하기 때문에 가상함수를 가지고 있어야한다.
            // dynamic_cast는 참조나 포인터 타입에만 쓸 수 있다. => 즉, int나 float와 같은 기본연산자에는 쓸 수 없다
            // 그리고 반환된 포인터가 nullptr인 경우 유효하지 않는다.
        }

    }

    // const_cast 존재만 한다.
    {
        //const int value = 3;
        //int constcast_value = const_cast<int>(value);

        //int value1 = 5;
        //const int* Ptrvalue1 = &value1;
        //Ptrvalue1 = 4;

        //const int value2 = 5;
        //int* Ptrvalue2 = const_cast<int*>(&value2);

        //*Ptrvalue2 = 3;

        //int a = 0;
        //

        const int num = 10;
        int* p = const_cast<int*>(&num);
        int i = 100;
        *p = 20;

        printf("&num = %x, p = %x, &i = %x\n", &num, p, &i);
        printf("num = %d, *p = %d, i = %d\n", num, *p, i);
    }



    std::cout << "Hello World!\n";
}
