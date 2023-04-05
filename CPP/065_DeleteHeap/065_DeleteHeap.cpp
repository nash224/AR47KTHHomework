// 065_DeleteHeap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void MyValueTest(int& _value)
{
	_value = 0;
}

int main()
{
	// 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{/*
		int Test = 1000;

		int* Newint = nullptr;



		int funcvalue = *newint;

		if (nullptr == newint)
		{
			return 1;
		}

		MyValueTest(*Newint);*/
	}


	// 중복할당
	{
		int* Newint = new int(); // 할당
		Newint = new int(); // 할당
		delete Newint; // 4바이트 Leak
	}

	// 대안법
	{
		int* Newint = new int(); // 할당
		delete Newint; // 해제
		Newint = new int(); // 할당
		delete Newint; // 해제
	}

	{
		// 동적메모리를 사용할땐, 무조건 확인해보는게 메모리 누수 예방에 좋다
		int* Newint = new int();

		if (nullptr == Newint)
		{
			return 1;
		}

		*Newint = 20;

		delete Newint;
		Newint = nullptr;
	}

	
	{
		// 동적 메모리를 기존에 할당했던 것보다 더 지우게 된다면
		// 메모리 크러쉬가 나면서 예상치 못한 동작이 발생할 수 있다.
		// 이를 더블해제(double-free) 라고 한다.

		int* Newint = new int();

		delete Newint;
		//delete Newint;
	}

	{
		int Value = int(10);
		int* Newint = new int(10);

		// 안전한 삭제
		if (nullptr != Newint)
		{
			delete Newint;
			// 해제를 해줬으나 Newint의 값에 들어있는 특정 번지수가 삭제되고 남아있다.
			// 이를 댕글링 포인터라고 한다.
			// 예기치 못한 동작을 초래할 수 있으므로 널포인터로 초기화해줘야한다.

			Newint = nullptr;
		}

		{
			int* NewPtr = new int();

			if (nullptr != NewPtr)
			{
				operator delete(NewPtr);
				// delete()를 수행할 때, operator delete()가 암시적으로 실행된다.
				NewPtr = nullptr;
			}
		}
	}







}