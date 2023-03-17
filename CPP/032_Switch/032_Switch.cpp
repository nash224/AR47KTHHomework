
#include <iostream>

int main()
{
	//	자동완성 기능 : swi 치고 Tap

	//	Switch case는 메모리 영역과 같은 상수 메모리가 있는지 비교하는 조건문이다.

	//	case는 상수 메모리만 올 수 있다.

	int value = 0;
	const int checkpoint = 0;

	switch (value)
	{
	case checkpoint:
	{
		int a = 0;
		printf_s(" 0 번째 체크 포인트에 도달하였습니다");
	}
	case 1:
		printf("value1");
	case 2:
		printf("value2");
	case 3:
		printf("value3");
	case 4:
		printf("value4");
		break;
	case 5:
		printf("value5");
		

	default:
		break;
	}
}

//	=== 핵심요약 ===

//	If와 switch는 흡사해보이지만, 조건문 판별방식이 다르다.