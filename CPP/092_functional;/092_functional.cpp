﻿// 092_functional.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

// template<typename ButtonCallType>
class Button
{
public:
	// 맴버변수도 쓰고 싶은데.

	// 
	// 변수는 1개인데 맴버변수도 

	void(*ClickEventPtr)() = nullptr;

	// void(ButtonCallType::*ClickEventPtr)() = nullptr;

	// 상속
	virtual void Click()
	{
		if (nullptr != ClickEventPtr)
		{
			ClickEventPtr();
		}
	}
};
//
//class PlayerAttackButton : public Button
//{
//
//};


class Player
{
public:
	static Player* MainPlayer;

	Player()
	{
		MainPlayer = this;
	}

public:
	void Attack()
	{
		std::cout << "플레이어가 공격합니다" << std::endl;
	}

	void CriAttack(float* _CriPercent)
	{
		std::cout << "플레이어가 치명타 공격을 합니다." << std::endl;
	}

	void TestAttack(int _Test)
	{
		std::cout << "테스트 용 함수입니다." << std::endl;
	}

	void TestAttack2(int _Test, int _Test0)
	{
		std::cout << "테스트 용 함수입니다." << std::endl;
	}


	void PlayerDeffense(int _Value)
	{
		std::cout << "플레이어가 방어합니다." << std::endl;
	}
};

Player* Player::MainPlayer = nullptr;


// 객체지향의 첫번째 특징은 전역이 없어야 한다.
void PlayerAttack()
{
	Player::MainPlayer->Attack();
}


void PlayerCriAttack(float* _Value)
{
	Player::MainPlayer->CriAttack(_Value);
}


void RamdaFunction(int _Value)
{
	std::cout << "람다 함수 입니다" << std::endl;
};



int main()
{
	// 그중에서 제일 까다로운 것들이 함수포인터인데
	// 함수포인터는 정말정말정말 많이 사용됩니다.
	// 엔진들에서 정말로 많이 사용됩니다.

	// 함수포인터이긴 함수포인터인데.
	// 1. 전역도 받을수 있고
	// 2. 맴버도 받을수 있고 <= 클래스제한없이
	// 3. 인자의 제한도없는 함수포인터가 있었으면 좋겠다.
	// 4. 그러면서도 그 넣어준 인자가 삭제되지 않았으면 함수의 스택이 파괴되어서
	// 인자가 사라지는 경우도 없었으면 좋겠다.
	// 그냥 거의 양심이 없다.


	Player NewPlayer;

	Button PlayerAtt;

	PlayerAtt.ClickEventPtr = PlayerAttack;

	PlayerAtt.Click();

	// void(*Ptr)(int) = PlayerAttack;



	// 전역함수 통과
	{
		std::function<void()> Func;
		Func = std::bind(PlayerAttack);
		Func();
	}

	// 맴버함수 통과
	{
		std::function<void()> Func;
		Func = std::bind(&Player::Attack, &NewPlayer);
		Func();
	}

	float Value = 50.0f;

	// 인자는 같이 넣어주면 상관없이 호출 가능.
	{
		// 인자의 처리와 상관없이  bind가 가능하다.
		std::function<void()> Func;
		Func = std::bind(&Player::CriAttack, &NewPlayer, &Value);
		Value = 30.0f;
		Func();
	}

	{
		// 인자의 처리와 상관없이  bind가 가능하다.
		std::function<void(int)> Func;
		Func = std::bind(&Player::TestAttack, &NewPlayer, std::placeholders::_1);
		Func(10);
	}


	{
		// 인자의 처리와 상관없이  bind가 가능하다.
		std::function<void(int, int)> Func;
		Func = std::bind(&Player::TestAttack2, &NewPlayer, std::placeholders::_1, std::placeholders::_2);
		Func(10, 20);
	}

	{
		std::function<void()> Func
			= []()
		{
			std::cout << "람다 함수 입니다" << std::endl;
		};


		Func();
	}

	{
		std::function<void(int)> Func
			= [](int _Value)
		{
			std::cout << "람다 함수 입니다" << std::endl;
		};

		Func(10);
	}

	{
		// 1000번지
		Player* NewPlayerPtr = &NewPlayer;
		int A = 2000;

		std::function<void(int)> Func
			= [= /*const Player* NewPlayerPtr = NewPlayerPtr*/](int _Value)
		{
			// 2000번지
			NewPlayerPtr->Attack();

			// NewPlayerPtr = nullptr;

			A;
			// std::cout << "람다 함수 입니다" << std::endl;
		};

		Func(10);
	}


	{
		int Value = 5;


		std::function<void(int)> func
			= [](int _Value)
		{
			for (size_t i = 0; i < _Value; i++)
			{
				std::cout << i << ": 번째 람다 함수입니다." << std::endl;
			}
		};

		func(Value);
	}


	{
		float PlayerXPos = 0.0f;
		const float PlayerMovePower = 500.0f;
		const float DeltaTime = 1.0f / 60.0f;

		std::function<void(float, float, float)> func = [](float _floatValue, float _Delta, float _PlayerXPos)
		{
			_PlayerXPos += _floatValue * _Delta;

			std::cout << "플레이어는 " << _PlayerXPos << "만큼 움직였습니다." << std::endl;
		};

		func(PlayerMovePower, DeltaTime, PlayerXPos);
	}

	{
		float CriValue = 30.0f;

		std::function<void()> func;
		func = std::bind(PlayerCriAttack, &CriValue);

		func();
	}

	{
		std::function<void()> func;
		func = std::bind(&Player::Attack, &NewPlayer);
		func();
	}


	{
		std::function<void(int, int)> func;
		func = std::bind(&Player::TestAttack2, &NewPlayer, std::placeholders::_1, std::placeholders::_2);
		func(10, 30);
	}


	{
		int Count = 56;

		std::function<void(int)> func;
		func = std::bind(&Player::PlayerDeffense, &NewPlayer, std::placeholders::_1);
		func(Count);
	}

	{

		std::function<void()> Func = []()
		{
			std::cout << "플레이어가 존재합니다." << std::endl;
		};

		Func();
	}


	{

		std::function<void(int)> Func = [](int _value)
		{
			std::cout << "플레이어가 움직입니다." << std::endl;
		};

		Func(50);
	}



	{
		Player* PlayerPtr = &NewPlayer;


		std::function<void(int)> Func = [= ](int _Value)
		{
			for (size_t i = 0; i < _Value; i++)
			{
				PlayerPtr->PlayerDeffense(_Value);
			}

		};

		Func(3);

	}
}
