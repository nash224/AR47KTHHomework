#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

int Player::Bulletcount = 10;

Player::Player()
{

}

void Player::ShootCount()
{
	Bulletcount++;
}

// 화면바깥으로 못나가게 하세요. 
void Player::Input()
{
	if (0 == _kbhit())
	{
		// 0.5초간 멈춘다.
		Sleep(InterFrame);
		// 일부러 멈추게 만들겁니다.
		// continue; 반복문 내부에서만 사용가능
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
		BulletPtr[Bulletcount].SetPos(Pos);
		BulletPtr[Bulletcount].On();
		ShootCount();
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}


void Player::Render()
{
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '*');
}