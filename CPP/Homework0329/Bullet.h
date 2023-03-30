#pragma once
#include "ConsoleGameScreen.h"

class Bullet
{
public:
	Bullet()
		: BulletFire(false)
	{

	}

	int2 GetBulletPos() const
	{
		return BulletPos;
	}

	inline void SetBulletPos(const int2& _Value)
	{
		BulletPos = _Value;
	}

	inline void SetBulletFire(bool _triggerpulled)
	{
		BulletFire = _triggerpulled;
	}

	inline bool GetBulletFire() const
	{
		return BulletFire;
	}

	inline void MoveBulletPos()
	{
		BulletPos.X = (BulletPos.X)++;
		// ¿¹¿Ü°¡ throwµÊ
	}


private:
	int2 BulletPos = int2(0, 0);

	bool BulletFire = false;
};
