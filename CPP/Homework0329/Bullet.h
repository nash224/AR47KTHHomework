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

	// ��ũ�� ��� ������ұ�
	// ��ũ�� �� ������ұ�
	// Ʈ��ŷ�� Ǯ���� ���������� �����ϼ� ����
	// 
	// �ѹ��� ��ǥ�� �ް� �ϸ� �� �Ͱ�����..
	// �ӽ� �Ѿ� ��ǥ�� ����� �ɱ�?
	// �׸��� �ִ� ��ǥ�Լ� ���� �ٲ��ʿ䰡 �ִ°�
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
