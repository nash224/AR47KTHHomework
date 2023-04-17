// 078_BitTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int value = 0b00000000000000000000000000000001;

    int* Ptr = &value;

    char* ChPtr = reinterpret_cast<char*>(Ptr);

    char Test0 = ChPtr[0];  // 1
    char Test1 = ChPtr[1];  // 0
    char Test2 = ChPtr[2];  // 0
    char Test3 = ChPtr[3];  // 0

    // 리틀 엔디안 방식
    // 낮은 주소에 낮은 데이터가 저장된다. => 이 방식을 채택하는 프로세서는 인텔이 있다.

    // 엔디안 방식은 시스템이 정수를 저장하는 방식을 가르킨다. => 예를 들어, 왼쪽에서 오른쪽으로 또는 오른쪽에서 왼쪽으로)
}