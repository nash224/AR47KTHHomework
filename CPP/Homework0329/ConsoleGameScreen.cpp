#include "ConsoleGameScreen.h"
#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;
class Player;

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			// Arr[y][x] = 'b';
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenXSize <= _Pos.X)
	{
		return true;
	}

	if (ScreenYSize <= _Pos.Y)
	{
		return true;
	}

	return false;
}



//bool ConsoleGameScreen::IsBulletScreenOver()

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	// 만약 나갔으면 함수에서 빠져나온다
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	// 나가지 않았으면 위치에 플레이어를 배치한다
	Arr[_Pos.Y][_Pos.X] = _Ch;
}



void ConsoleGameScreen::SetScreenBullet(const int2& _BulletPos, char _Bull)

{
	if (true == IsScreenOver(_BulletPos))
	{
		return;
	}

	if (true == PlayerIsFire)
	{
		Arr[_BulletPos.Y][_BulletPos.X] = _Bull;
	}
	
}




ConsoleGameScreen::ConsoleGameScreen()
{
}

int2 ConsoleGameScreen::GetScreenSize()
{
	return int2{ ScreenXSize, ScreenYSize };
}
