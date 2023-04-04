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

	void Update();
	void Render();

protected:

private:
	// �����ϴ��� ���ϴ���
	bool UpdateValue = true;
	// �޸������� 
	bool DeathValue = false;


	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();

	bool Fire = false;

	int2 Pos = int2(0, 0);
};