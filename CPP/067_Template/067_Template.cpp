// 067_Template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Bullet
{
public:
	void Update()
	{

	}
};

typedef Bullet DataType;

class GameEngine
{
public:
	// delete Function
	GameEngine(const GameEngine& _Other) = delete;
	GameEngine(GameEngine&& _Other) noexcept = delete;


	// 복사 대입 연산자는 일반적으로 얕은 복사를 수행하게 된다.
	// => 기존 객체의 멤버변수를 그대로 복사하여 새로운 객체에 할당하는 것
	// 정적 메모리를 사용할 때는 메모리 누수가 나지 않음

	// But 클래스가 동적으로 할당된 메모리를 가지고 있고, 얕은 복사를 새로운 객체에 할당한 경우
	// 메모리 누수가 날 수 있음.
	//GameEngine& operator=(const GameEngine& _Other) = delete; // 이 복사, 대입 연산자 함수는 실행되지 않음

	// noexcept는 예외가 발생하지 않는 함수의 실행속도를 높임 => 예외처리 검사를 하지 않겠다.
	GameEngine& operator=(GameEngine&& _Other) noexcept = delete; // delete를 하면 이동 대입 연산이 불가능해짐


	// constructor desstructor
	GameEngine(size_t _value)
		: ArrPtr(new DataType[_value])
		, ArrCount(_value)
	{

	}
	~GameEngine()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	// 일반적으로 클래스타입 참조형 반환은 내부에서 사용되고
	// 클래스타입 포인터형 반환은 외부에서 다른 객체의 값을 불러올 때 사용된다.
	GameEngine& operator=(const GameEngine& _Other) // 사용할 수 있게 delete를 제거해줌
	{
		ArrCount = _Other.ArrCount;
		ArrPtr = _Other.ArrPtr;

		// this 와 this*는 둘 다 객체 자신을 가리키는 포인터다.
		// 단, this는 객체 자체는 참조형으로 반환하는 것이고, (즉, GameEngine의 객체를 반환하게 된다.)
		// => 값을 변경하거나 함수를 
		// *this는 객체 포인터가 가리키는 포인터를 반환하는 것이다. 
		return *this;
	}



	// return값을 DataType으로 넣은 이유
	// -> ArrPtr의 자료형을 Datatype으로 변환해줬기 때문
	// => 자료형을 동일하게 해줘야 대입이 된다.

	// 왜 레퍼런스를 사용했는가? 참조형외로도 포인터를 써도 되지않은가
	// 참조형은 반환값이 위치한 메모리 주소를 참조하는 방식이다.  // 리턴 : 주소를 참조하여 값으로 반환
	// => 원래 값의 참조를 반환하는 것이므로 메모리 사용량을 줄일 수 잇다.

	// 포인터형은 반환값이 위치한 메모리 주소를 가리키는 포인터를 반환한다. // 리턴 : 반환 값의 주소를 포인터로 반환
	// => 반환 값을 복사하는게 아닌, 반환값의 주소를 가리키는 포인터를 반환하므로 메모리 사용량을 줄일 수 있다.
	// 일반적으로 매개변수의 값을 반환하거나, 값을 비교하고 나서 바로 사용할 때 쓴다 
	DataType& operator[](size_t _index)
	{
		return ArrPtr[_index];
	}


	// ArrCount 변수의 값을 리턴해주기 위해 자료형을 ArrCount형으로 반환 
	size_t Count()
	{
		return ArrCount;
	}


protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};


class Player
{

};


class Monster
{

};

int main()
{
	Player NewPlayer;
	Monster NewMonster;

	//NewPlayer = NewMonster;

	GameEngine NewArr(20);

	for (size_t i = 0; i < NewArr.Count(); i++)
	{
		// 에러가 나는 이유 NewArr의 클래스를 사용하는데, 연산자[]를 정해주지 않았다.
		// 클래스가 생성자로부터 동적할당 객체를 생성하고
		NewArr[i].Update();

		
	}

	// 객체의 사용이 끝날 때, delete로 동적 메모리를 해제 해준다. 
	// => 소멸자에 정의되어 있다.
}