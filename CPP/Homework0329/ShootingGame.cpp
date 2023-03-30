#include "ShootingGame.h"
#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "ConsoleGameScreen.h"


void ShootingGame::GameProcess()
{

	Player NewPlayer = Player();
	Bullet NewBullet = Bullet();

	NewBullet.SetPlayer(&NewPlayer);



	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		NewPlayer.Render();

		NewBullet.BulletRender();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		
		NewBullet.Update();

	}

}