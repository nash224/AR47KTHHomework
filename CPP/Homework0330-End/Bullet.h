#pragma once
#include "ConsoleGameObject.h"
#include "ShootingGame.h"

class Player;
class ConsoleGameScreen;
class Bullet : public ConsoleGameObject
{
public:
	static const int ArrBulletCount = 10;

	// Ŭ������ �������� �Ѿ��� ���� ���� �Ѿ����� ��ȯ�Ѵ�.
	// �Ѿ����� ������ �ְ� ������
	static Bullet* GetArrBullet() 
	{
		return ArrBullet;
	}

	static void AllOff();
	static void AllRender();
	static void AllUpdate();

	void Update();

protected:

private:
	// ���� �迭 ���� ����
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();
};

