#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

void Bullet::AllOff()
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		ArrBullet[i].Off();
	}
}

// 총알이 존재하는 값만 랜더링하겠다.
void Bullet::AllRender() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsUpdate())
		{
			continue;
		}

		ArrBullet[i].Render();
	}

}

void Bullet::AllUpdate() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsUpdate())
		{
			continue;
		}
		// 총알이 존재하면 위로 올려보낸다
		ArrBullet[i].Update();
	}
}

Bullet::Bullet()
{
	RenderChar = '^';
}


void Bullet::Update() 
{
	if (true == IsUpdate())
	{
		--Pos.Y;
	}
}