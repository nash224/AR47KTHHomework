#pragma once
#include "ConsoleGameObject.h"
#include "ShootingGame.h"

class Player;
class ConsoleGameScreen;
class Bullet : public ConsoleGameObject
{
public:
	static const int ArrBulletCount = 10;

	// 클래스의 전역으로 총알의 정보 중의 총알집을 반환한다.
	// 총알집의 정보를 주고 싶을때
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
	// 전역 배열 변수 선언
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();
};

