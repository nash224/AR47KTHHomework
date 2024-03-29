#pragma once
#include "ConsoleGameMath.h"
#include "ShootingGame.h"

class Player;
class ConsoleGameScreen;
class Bullet
{
public:
	static const int ArrBulletCount = 10;

	static Bullet* GetArrBullet()
	{
		return ArrBullet;
	}

	static void AllRender();
	static void AllUpdate();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
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

	void Update();
	void Render();

protected:

private:
	// 동작하는지 안하는지
	bool UpdateValue = true;
	// 메모리적으로 
	bool DeathValue = false;


	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();

	bool Fire = false;

	int2 Pos = int2(0, 0);
};