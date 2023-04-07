#include "ConsoleGameScreen.h"
#include <iostream>
#include <Windows.h>
#include "GameEngineArray.h"

// 싱글톤 패턴 : 3번째
// 게임 스크린의 객체를 생성한다.
ConsoleGameScreen ConsoleGameScreen::MainScreen;

// 스크린을 전부 초기화 하겠다.
void ConsoleGameScreen::ScreenClear()
{
	system("cls");

	// y축을 위한 반복문
	for (size_t y = 0; y < ScreenYSize; y++)
	{	// x축을 위한 반복문
		for (size_t x = 0; x < ScreenXSize; x++)
		{	// (x,y)를 전부 a로 초기화한다.
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

// 반환값이 bool이고, 멤버 변수의 값을 변경 하지 못하게 하며,
// int2 참조 타입의 상수 매개변수를 받는 IsScreenOver() 상수함수를 선언한다.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	// x가 0보다 작으면 참을 반환한다.
	if (0 > _Pos.X)
	{
		return true;
	}
	// y가 0보다 작으면 참을 반환한다.
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
	// 다 아니라면 false를 반환한다.
	return false;
}

// 반환 타입이 없고, 두 매개변수를 받아 수행하겠다.
void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	// 위치가 화면을 넘어가면 반환한다.
	if (true == IsScreenOver(_Pos))
	{
		return;
	}
	// 지정위치에 _Ch를 넣는다
	Arr[_Pos.Y][_Pos.X] = _Ch;
}


// 게임 스크린의 생성자
// 특별한 멤버 함수로서 자동으로 가장 먼저 호출되고, 
// 주요 역할은 멤버 변수의 초기화이다.
ConsoleGameScreen::ConsoleGameScreen()
{
}

// 좌표 타입의 함수를 반환한다.
//
int2 ConsoleGameScreen::GetScreenSize()
{
	return int2{ ScreenXSize, ScreenYSize };
}