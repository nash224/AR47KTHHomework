// 064_Heap01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 힙은 사용자가 자유롭게 메모리를 할당할 수 있는 영역이지만,
// 정적 메모리일 떄는 컴파일러가 확인했지만, 
// 힙은 사용자가 책임을 져야한다.


class Monster
{

};

int main()
{
	// 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		Monster* PtrMonster = new Monster();

		//Detected memory leaks!
		/* Dumping objects ->
		   {78} normal block at 0x000001FE04A16300, 1 bytes long.
			Data: < > CD */
	}

	{
		//힙의 선언방법
		// 연산자 자료형 생성자
		// new    자료형 ();

		// 힙에서 메모리를 할당하면
		Monster* PtrMonster = new Monster();

		// 힙에서 메모리 해제를 원칙으로 함
		delete PtrMonster;

		// 동적 할당받은 메모리를 해제하지 않으면?
		// Leak 혹은 메모리 누수라고 부르며, 내 게임이 해제하지 않은 메모리만큼 느려진다.
		


		int Value = 20;

		// 동적 메모리를 받지 않으면 메모리를 잃어버리므로
		// 무조건 받아야한다.
		// ex) new int(); <= 잃어버린 메모리


	}

	{
		int* Ptr = /*operator new()*/ new int();


		// 지워진 메모리의 주소값은 nullptr이기 때문에 throw 예외처리가 발생함(널포인트 역참조)
		//PtrValue = *Ptr;

		if (nullptr == Ptr)
		{
			std::cerr << "Error: Failed to allocate memory." << std::endl;
			return 1;
		}

		*Ptr = 20;

		int PtrValue = *Ptr;

		delete Ptr;
		Ptr = nullptr;

	}

}