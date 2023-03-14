
int main()
{
    //  특정 자료형 앞에 const를 붙이게 되면 그 메모리의  비트적 상수화를 시킨다.
    const char cc = 10;

    const bool cb = 20;


    //  일반적으로 랜덤인덱스에 변수는 집어 넣지 못하지만,
    //  비트적으로 상수화되면 넣을수 있게 된다.
    int ArrValue[cc] = {};
}