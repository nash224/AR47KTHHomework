#pragma once

// 헤더에만 다 만든다.
class int2
{
public:
	// 외부에 쓸 수 있는 변수가 있다.
	int X = 0;
	int Y = 0;

	inline int2()
	{

	}

	// 매개변수가 2개인 생성자가 호출되면 멤버변수에 대입하겠다.
	inline int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}

	inline int2 Half()
	{
		return { X / 2, Y / 2 };
	}

	bool Check(const int2& _Other)
	{
		return X == _Other.X && Y == _Other.Y;
	}

	// int2인척하는 값이 변하지 않는 매개변수를 받아
	// int2의 변수와 비교하여 참 거짓 값을 반환하겠다는 로직
	bool operator==(const int2& _Other) 
	{
		return X == _Other.X && Y == _Other.Y;
	}


};