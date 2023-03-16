
#include <iostream>

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

    VarFunc(5, 1, 2, 3, 4, 5);
}