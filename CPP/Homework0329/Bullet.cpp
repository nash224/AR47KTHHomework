#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet::Bullet()
{

}


void Bullet::BulletRender()
{
	if (nullptr == m_Player)
	{
		return;
	}

	if (true == m_Player->IsFire())
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

void Bullet::Update()
{
	if (nullptr == m_Player)
	{
		return;
	}

	if (false == m_Player->IsFire())
	{
		SetPos(m_Player->GetPos());
	}
	else
	{
		--Pos.Y;
	}

}
