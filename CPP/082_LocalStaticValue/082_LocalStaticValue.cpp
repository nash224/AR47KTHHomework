// 082_LocalStaticValue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>



void TestFunction()
{
	// 함수 안에 정적 변수를 선언함으로 데이터 영역에 상주하는 변수지만,
	// 이 함수 내에서만 사용이 가능하다.
	static int Value = 0;
	std::cout << Value << std::endl;
	++Value;
}

int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		TestFunction();
	}

	std::cout << "Hello World!\n";
}
