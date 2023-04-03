#pragma once
#include "ConsoleGameMath.h"

// Screen에서 움직이는 오브젝트들의 기본기능을 제공한다.
class ConsoleGameObject
{
public:
	// 반환값이 없고, 값이 변하지 않는 int2형식의 값을 매개변수로 받아 
	// 멤버 변수에 담는다
	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	bool IsDeath()
	{
		return DeathValue;
	}

	void Death()
	{
		DeathValue = true;
	}

	bool IsUpdate()
	{
		return UpdateValue;
	}

	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}

	void Render();

protected:
	int2 Pos;
	char RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;

};

