// 060_FunctionPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test1()
{
	std::cout << "Test1() 함수 호출!!" << std::endl;
}


// 함수 포인터는 함수의 주소를 저장하는 변수이다.
// 함수를 반환값으로 사용할 수 있다.
// 함수 포인터는 행동을 변수로 만드는 것이다.


void Print()
{
	return;
}

void NoticeMonsterisCome()
{
	std::cout << "몬스터들의 공세가 시작됩니다." << std::endl;
}

void PlayerDetectTheMonster()
{
	std::cout << "플레이어가 몬스터의 공세를 알아차렸습니다." << std::endl;
}

void PlayerAttack()
{
	std::cout << "플레이어가 공격합니다." << std::endl;
}

void PlayerMove()
{
	std::cout << "플레이어가 이동합니다." << std::endl;
}

class MonsterActtackButton
{
public:
	
	void Click()
	{
		PlayerAttack();
	}
};


class UIButton
{
public:
	void(*ButtonPtr)();

	void Click()
	{
		if (nullptr == ButtonPtr)
		{
			return;
		}

		ButtonPtr();
	}
};


int main()
{
	{
		// 리턴값 (* 함수포인터명 ) (매개변수)

		// 함수 포인터 'Ptr'을 사용하여 호출할 수 있다.
		void(*Ptr)();
		// 함수 포인터에 함수Test1의 주소 저장
		Ptr = &Test1;
		// 함수 포인터를 사용하여 Test1()함수의 주소를 호출
		// Test1();
		(*Ptr)();
		
		// void(*)() == void PlayerDetectTheMonster();


		void(*PtrPlayer)();
		// 포인터 변수에 받음 = 함수의 주소를 받음
		PtrPlayer = &PlayerDetectTheMonster;
		(*PtrPlayer)();


		void(*PtrMonster)();
		// 포인터 변수에 받음 = 함수를 받음 
		PtrMonster = NoticeMonsterisCome;
		(PtrMonster)();

		int PtrMonstervalue = sizeof(PtrMonster);
		int a = 0;
	}

	{
		// 일일이 버튼 클래스를 만들지 않고, 하나의 클래스에 함수포인터로 호출이 가능함.
		UIButton PlayerAttackButton;
		UIButton PlayerMoveButton;

		PlayerAttackButton.ButtonPtr = PlayerAttack;
		PlayerMoveButton.ButtonPtr = PlayerMove;

		PlayerAttackButton.Click();
		PlayerMoveButton.Click();


	}

	{
		system("cls");
		void(*ArrPtr[20])();

		ArrPtr[0] = NoticeMonsterisCome;
		ArrPtr[1] = PlayerDetectTheMonster; 
		ArrPtr[0]();
		ArrPtr[1]();

		
 

		int ptrvalue = 0; 

		int Arr[20] = { 1, 2, 3, 4, 5 };
		int* ptr = Arr;
		void(**ArrFuncPtrPtr)();
		ArrFuncPtrPtr = ArrPtr;
		ArrFuncPtrPtr[1]();
		ptrvalue = ptr[0];

		// Arr[0] = int
		// Arr = { int, int, int, int, int, int, ... }
		// Arr = *int
		// *ptr = *int
		// ptr = **int
		// **ptr = int
		// ptr[0] = *int
		// ptr = { *int, *int, *int, *int, *int, ... }
		


		int a = 0;
	}



	int intvalue = sizeof(int);
}