#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Bullet;
class Player
{
public:
	Player();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void Input();

	// �̻����� ����� ���� �̰� ��õ�Ѵ�.
	// 
	inline bool IsFire() 
	{
		return Fire;
	}

	void Render();

	void SetBullet(Bullet* _m_ArrBuleltPtr)
	{
		if (nullptr == _m_ArrBuleltPtr)
		{
			return;
		}

		m_ArrBuleltPtr = _m_ArrBuleltPtr;
	}

protected:

private:
	static const int InterFrame = 200;

	bool Fire = false;

	Bullet* m_ArrBuleltPtr;

	int2 Pos = int2(0, 0);

	// �̷� ������ Has a��� �Ѵ�. Player Has a Bullet
	// Bullet NewBullet; // �÷��̾��� ��ü ���ο� �Ѿ� �ѹ��� �ִ�.
	// Bullet* NewBullet; // �ٱ��� �ִ� �Ѿ��� �����Ҽ� �ִ�.
};

