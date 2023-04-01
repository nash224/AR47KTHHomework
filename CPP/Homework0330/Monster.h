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

	// �׾����� Ȯ���Ϸ��� �뵵
	bool IsDeath()
	{
		return DeathValue;
	}

	// ���� ���� ����
	void Death()
	{
		DeathValue = true;
	}

	// �׾����� Ȯ���Ϸ��� �뵵
	bool IsUpdate()
	{
		return UpdateValue;
	}

	// ���� ���� ����
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

