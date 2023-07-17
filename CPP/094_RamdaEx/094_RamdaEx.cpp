// 094_Ramda2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

class Test
{
public:
	int A = 10;

	void TestFunction()
	{
		// this;

		std::function<void()> Ptr = [this /*Test* const this = this*/]()
		{
			// this = nullptr;
			this->A = 20;
		};
	}
};


// 클래스 멤버 함수 내에서 람다를 사용할 수 있을까?


class TestRamdaEx
{
public:
	int B = 50;

	void testRamdaFunction()
	{

		std::function<void()> r_Ptr = [this /*const TestRamdaEx* this*/]()
		{
			// 멤버 함수의 첫번째 인자 this를 넣어주었다
			this /*= nullptr*/;
			// 자신을 NULL로 바꿔줄수 없는 걸 보니 const 선언이 되있는것같다

			this->B = 60;

		};

		r_Ptr();
	};
};


int main()
{
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
