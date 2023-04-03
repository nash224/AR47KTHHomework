#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

Player::Player()
{
	RenderChar = '*';
}
// 화면바깥으로 못나가게 하세요. 
void Player::Input()
{
	// 눌렀을 때
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
		// 새로운 위치에 현재 위치를 담는다.
		NextPos = Pos;
		// 새로운 위치에 왼쪽으로 가게 한다.
		NextPos.X -= 1;
		// 다음위치가 넘지 않았다면
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{// 플레이어의 좌표를 왼쪽으로 한칸 보낸다.
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
	{
		// 총알에 대한 로직을  불러온다
		ShotUpdate();
		break;
	}
	default:
		break;
	}

	Sleep(InterFrame);
}

void Player::ShotUpdate()
{
	// 총알들의 정보를 받아온다.
	Bullet& NewBullet = BulletPtr[BulletCount];
	// 총알 객체의 위치를 가져온다.
	NewBullet.SetPos(Pos);
	// 총알을 존재하게 한다.
	NewBullet.On();

	// 발사한 총알의 수를 센다
	++BulletCount;
	// 발사한 총알이 전체 총알보다 많으면 발사한 총알을 0으로 초기화한다.
	if (BulletCount >= Bullet::ArrBulletCount)
	{
		BulletCount = 0;
	}
}
