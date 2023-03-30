#pragma once
#include "ConsoleGameMath.h"


class ConsoleGameScreen;
class Player;
class Bullet
{
public:
	Bullet();



	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void SetPlayer(Player* _m_Player)
	{
		if (nullptr == _m_Player)
		{
			return;
		}

		m_Player = _m_Player;
	}

	void Update();

	void BulletRender();

protected:

private:
	bool trigger;

	Player* m_Player;

	int2 Pos = int2(0, 0);
};