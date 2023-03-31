#pragma once
#include "ConsoleGameMath.h"
#include "ShootingGame.h"

class ConsoleGameScreen;
class Player;
class Bullet
{
public:
	static Bullet* GetArrBullet()
	{
		return ArrBullet;
	}

	static void AllRender();

	static void AllUpdata();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline bool GetIsBulletFire() const
	{
		return Fire;
	}

	inline void FireOn()
	{
		Fire = true;
	}
	
	void BulletRender();

	void Update();

protected:

private:
	Bullet();

	static const int ArrBulletCount = 30;

	static Bullet ArrBullet[ArrBulletCount];

	bool Fire = false;

	int2 Pos = int2(0, 0);
};

