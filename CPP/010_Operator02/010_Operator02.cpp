
int main()
{
    //  비트단위 연산자

    //  비트 단위 연산자는 &(and), |(or), ~(not), ^(xor)이 있음
    int MonsterATT = 10;
    int MonsterDEX = 4;
    int result;

    //  2진수 비트로 봤을 때 둘 다 1이면 1, 하나라도 0이 있으면 거짓이 된다
    result = MonsterATT & MonsterDEX;

    //  하나라도 1이 포함되면 1
    result = MonsterATT | MonsterDEX;

    //  서로 다른 값이면 1
    result = MonsterATT ^ MonsterDEX;

    //  비트를 반저시킨다
    result = ~MonsterATT;

    //  쉬프트 연산자

    //  왼쪽으로 특정 정수만큼 이동시킨다. 
    result = MonsterATT << 2;
    
    //  오른쪽으로 특정 정수만큼 이동시킨다.
    result = MonsterDEX >> 2;

    //  복합 할당 연산자
    //  복합 할당 연산자는 원래 값에서 특정양을 더하거나 빼고,곱하는 등..간소화 시킨 연산자이다.

    MonsterATT += 4;
    //  MonsterATT = MonsterATT + 4;
    
    

}