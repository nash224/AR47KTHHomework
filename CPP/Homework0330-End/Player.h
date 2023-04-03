#pragma once
#include "ConsoleGameObject.h"


class ConsoleGameScreen;
// �θ� ConsoleGameObject�� ���� ������� ��ӹްڴ�.
class Player : public ConsoleGameObject 
{
public:
	Player();
	void Input();

	// ��ȯ�� ����, �Ѿ��� ������ �Ű������� �����ͼ� 
	// Player Ŭ������ ���ο� �׸��� ���Խ�Ų��.
	// �Ѿ��� ������ ������ ��,
	void SetBulletArr(class Bullet* _BulletPtr)
	{
		BulletPtr = _BulletPtr;
	}

protected:

private:
	void ShotUpdate();
	static const int InterFrame = 200;
	Bullet* BulletPtr;
	int BulletCount = 0;
};

