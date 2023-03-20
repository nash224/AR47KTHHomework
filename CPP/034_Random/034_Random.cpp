
#include <iostream>
#include <conio.h>

int Seed = 0;   //  전역변수

void SeedChange(int _seed)  //  시드값 설정
{
    Seed = _seed;
}

int Randomint() //  랜덤하게 보이는 수를 뽑아내주는 로직
{
    return Seed++;
}

int main()
{
    SeedChange(3);  //  3으로 초기화

    //  시간은 일반적으로 8바이트 정수로 줌
    unsigned int Test = time(0);

    srand(Test);
    //  1초간 같은 숫자가 랜덤하게 등장함


    while (Seed != 5000)
    {
        //printf_s("%d\n", Randomint());
        printf_s("%d\n", rand());

        _getch();   //  키를 누를때만 실행

    }

    int a = 0;
}