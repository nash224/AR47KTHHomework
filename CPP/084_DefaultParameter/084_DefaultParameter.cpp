// 084_DefaultParameter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Function(int _Value = 50)
{
    std::cout << _Value << std::endl;
}


void Function(int _Value, int _Test = 50)
{
    std::cout << _Value << std::endl;
}



// 디폴트 인자는 무조건 인자의 가장 오른쪽부터 만들수 있다.
//void Function0(int _Value = 50, int _Test)
//{
//    std::cout << _Value << std::endl;
//}
int main()
{
    Function(10, 20);

    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();

    // 함수 오버로딩은 같은 이름을 가진 함수를 매개변수의 개수, 타입, 순서 등을 조합하여 
    // 다른 기능을 수행하도록 하는 기술이다.
    // 오버로드된 함수의 인수목록이 같은 함수가 있어 무엇을 호출해야될지 모르는 상황
    // 해결책은 명확히 지정해주면 형식에 맞춰 오버로드 함수를 호출할 수 있다.
    // 

    std::cout << "Hello World!\n";
}
