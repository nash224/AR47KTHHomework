#pragma once
#include "ConsoleGameObject.h"


class ConsoleGameScreen;
// 부모 ConsoleGameObject에 대한 멤버들을 상속받겠다.
class Player : public ConsoleGameObject 
{
public:
	Player();
	void Input();

	// 반환은 없고, 총알의 정보를 매개변수로 가져와서 
	// Player 클래스의 새로운 그릇에 대입시킨다.
	// 총알의 정보를 가져올 때,
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

