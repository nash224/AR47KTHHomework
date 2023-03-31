#include "ShootingGame.h"
#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "ConsoleGameScreen.h"


void ShootingGame::GameProcess()
{

	Player NewPlayer = Player();

	NewPlayer.SetBullet(Bullet::GetArrBullet());

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		NewPlayer.Render();
		Bullet::AllRender();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();

		Bullet::AllUpdata();

	}
}