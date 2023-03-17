
#include <iostream>

void TestFucntion(int _1, ...)  //   인자에 이름을 넣지 않아도 인자로 쓸 수 있다.
{
    int* Ptr = &_1;
    int count = 2;

    while (_1--)
    {
        int value = Ptr[count];

        count += 2;
    }
}



void VarFunc(int _1, ...)
{       //  가변인자
        //  매개변수를 사용자가 입력한 만큼 받겠다.

}

int main()
{
    VarFunc(5, 1, 2, 3, 4, 5);

    VarFunc(5, "5", 253, true, "75242", 5);

    VarFunc(5, 1, 2);

    VarFunc(1);

    TestFucntion(5, 1, 2, 3, 4, 5);
}