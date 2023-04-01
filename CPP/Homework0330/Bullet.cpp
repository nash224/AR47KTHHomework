#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];


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

		ArrBullet[i].Update();
	}
}

Bullet::Bullet()
{

}

void Bullet::Render()
{
	if (true == UpdateValue)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

void Bullet::Update()
{
	if (true == UpdateValue)
	{
		--Pos.Y;
	}
}