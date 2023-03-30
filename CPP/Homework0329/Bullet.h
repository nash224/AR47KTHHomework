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

	inline void SetBulletPos(const int2& _Pos)
	{
		BulletPos = _Pos;
	}

	inline void SetBulletFire(bool _triggerpulled)
	{
		BulletFire = _triggerpulled;
	}

	inline bool GetBulletFire() const
	{
		return BulletFire;
	}

	// 링크를 어떻게 끊어야할까
	// 링크를 왜 끊어야할까
	// 트레킹이 풀려서 독립적으로 움직일수 있음
	// 
	// 한번만 좌표를 받게 하면 될 것같은데..
	// 임시 총알 좌표를 만들면 될까?
	// 그리고 주는 좌표함수 또한 바꿀필요가 있는가
	inline void MoveBulletPos()
	{
		BulletPos.X++;
		BulletPos.X++;
		BulletPos.X++;
	}


private:
	int2 BulletPos = int2(0, 0);

	bool BulletFire;
};
