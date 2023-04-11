#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>

bool Player::IsGameUpdate = true;


Player::Player()
{
	RenderChar = '*';
}
// 화면바깥으로 못나가게 하세요. 
void Player::Update()
{
	if (0 == _kbhit())
	{
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
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	case 'f':
	case 'F':
	{
		// 총알에 대한 로직을  불러온다
		break;
	}
	default:
		break;
	}
}
