#include <iostream>
#include "Player.h"
#include "ConsoleGameScreen.h"
#include "Bullet.h"

int main()
{
	// 오늘의 숙제입니다.
	// 총알 1발을 발사하세요.
	// 방향 상관 없음.
	// 총알 클래스를 만든다.
	// 플레이어가 여러분들이 지정한 키를 누르르면 

	// Bullet NewBullet;

	Player NewPlayer = Player();

	// int2의 스크린 크기 객체는 콘솔영역의 
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();

	// NewPlayer 객체는 스크린의 반만큼의 인자를 SetPos함수로 전달한다.
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');

		if ()
		ConsoleGameScreen::GetMainScreen().SetScreenBullet(NewPlayer.GetPos(), '>');

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();

	}

	std::cout << "Hello World!\n";
}