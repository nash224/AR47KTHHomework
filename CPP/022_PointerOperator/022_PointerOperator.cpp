
void PointerTest1(int A)
{
    A = 50;
}

void PointerTest2(int *B)
{
    *B = 0;
}

void PointerTest3(int *C)
{
    C = 0;
}

void Damage(int* HP, int* ATT)
{
    *HP = *HP - *ATT;
}



int main()
{
    
    {// 포인터를 이용한 대입법

        int result = 0;
        int value = 10;
        __int64 Address0 = 0;

        int* Ptr0 = &value; //  포인터 Ptr0에 value의 주소를 받겠다.

        //  이중 포인터

        int** PPtr0 = &Ptr0;
        **PPtr0 = 2;    //  PPtr0의 값(Ptr0의 주소)의 값(value의 주소)을 사용하겠다.

        Address0 = (__int64)Ptr0;
        result = value;

        PointerTest1(value);
        result = value;

        *Ptr0 = 5;  //  Ptr0의 값을 사용하겠다.


        //PointerTest2(value);  //  주소값의 인자는 변수로 받을 수 없다. 0x0564를 10으로 받은 것과 같은 것이다.
        PointerTest2(&value);
        result = value;

        PointerTest2(Ptr0);
        result = value;

        

        int a = 0;

    }

    {
        int result = 0;

        int User01HP = 100;
        int* P_User01HP = &User01HP;
        int User01ATT = 20;
        int* P_User01ATT = &User01ATT;

        int Monster01HP = 60;
        int* P_Monster01HP = &Monster01HP;
        int Monster01ATT = 10;
        int* P_Monster01ATT = &Monster01ATT;

        Damage(P_User01HP, P_Monster01ATT);
        User01HP;

        Damage(P_Monster01HP, P_User01ATT);
        Monster01HP;

        int a = 0;
        
    }

}

//  ===  핵심요약 ===

//  int* value 선언, int *value는 파라미터의 value 역참조
//  주소값(16진수)의 인자는 포인터 변수로 받을수 있다.