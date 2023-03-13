

//  함수는 일부 작업을 수행하는 코드 블록이다.
//  함수의 내부에서 함수선언은 불가능하다.
//  함수는 리턴값이 반드시 존재한다.

//  함수의 이름의 의미는 변수와 같이 데이터의 주소값과 메모리공간이 있다.
//  메모리가 존재한다면 그 메모리의 주소 또한 존재한다.

void function1(int valueTest)
{
    valueTest = 10;
    valueTest += 10;

    return;
}

int function2(int arg1, int arg2)
{
    return arg1 + arg2;
}


int main()
{
    int valueTest = 5;
    function1(valueTest);

    int result;

    result = function2(10, 20);

    result = sizeof(function2(10,20));
}