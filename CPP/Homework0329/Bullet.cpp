#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include "Player.h"
#include <Windows.h>

// ccp ���Ͽ��� ��ü�� �������.
// �ڷ���Ÿ�� ����::��ü�̸�[��ü��]
Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

Bullet::Bullet()
{

}

void Bullet::AllRender()
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (true == ArrBullet[i].GetIsBulletFire())
		{
			ArrBullet[i].BulletRender();
		}
	}
}

void Bullet::AllUpdata()
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (true == ArrBullet[i].GetIsBulletFire())
		{
			ArrBullet[i].Update();
		}
	}
}

void Bullet::BulletRender()
{
	if (true == Fire)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

void Bullet::Update()
{
	if (true == Fire)
	{
		--Pos.Y;
	}
}
