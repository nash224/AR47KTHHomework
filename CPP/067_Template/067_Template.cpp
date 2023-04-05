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

	//GameEngine& operator=(const GameEngine& _Other) = delete;

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


}