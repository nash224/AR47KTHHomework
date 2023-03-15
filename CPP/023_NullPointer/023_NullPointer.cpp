

int main()
{

    int value = 10;
    //  nullptr은 0이라고 부른다.
    //  선언하게되면 아직 아무도 가르키지 않는다는 의마이다.
    //  따라서 nullptr는 보통 포인터를 초기화하는데 사용한다.

    int* Ptr = nullptr;

    Ptr = &value;

    *Ptr = 123;

    int a = 0;
}