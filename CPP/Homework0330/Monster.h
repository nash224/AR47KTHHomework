#pragma once
#include "ConsoleGameMath.h"

class Monster
{
public:
	Monster();
	void Render();
	void Update();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	// 죽었는지 확인하려는 용도
	bool IsDeath()
	{
		return DeathValue;
	}

	// 죽음 값을 변경
	void Death()
	{
		DeathValue = true;
	}

	// 죽었는지 확인하려는 용도
	bool IsUpdate()
	{
		return UpdateValue;
	}

	// 죽음 값을 변경
	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}



private:
	bool UpdateValue = true;
	bool DeathValue = false;

	int2 Pos = int2(0, 0);
};

