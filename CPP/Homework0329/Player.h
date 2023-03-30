#pragma once
#include "ConsoleGameMath.h"

class Player
{
public:
	Player();


	// �÷��̾��� ��ġ�� ��ǥ���� ��������� 
	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline int2 GetBulletPos() const
	{
		return currentBullPos;
	}


	void Input();

	// �̻����� ����� ���� �̰� ��õ�Ѵ�.
	// 
	inline bool IsTriggerPulled() const
	{
		return Trigger;
	}

	void SetBulletFire(bool isFire)
	{
		Trigger = isFire;
	}

	//void Test(Bullet Test) 
	//{

	//}

protected:

private:
	static const int InterFrame = 200;

	bool Trigger = false;


	int2 currentBullPos = int2{ 0,0 };
	int2 Pos = int2(0, 0);

	// �̷� ������ Has a��� �Ѵ�. Player Has a Bullet
	//Bullet NewBullet; // �÷��̾��� ��ü ���ο� �Ѿ� �ѹ��� �ִ�.
	//Bullet* NewBullet; // �ٱ��� �ִ� �Ѿ��� �����Ҽ� �ִ�.
};