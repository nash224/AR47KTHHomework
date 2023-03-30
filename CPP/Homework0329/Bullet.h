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

	void SetBulletPos(const int2& _Value)
	{
		BulletPos = _Value;
	}

	void SetBulletFire(bool _triggerpulled)
	{
		BulletFire = _triggerpulled;
	}

	bool GetBulletFire() const
	{
		return BulletFire;
	}


private:
	int2 BulletPos = int2(0, 0);

	bool BulletFire = false;
};
