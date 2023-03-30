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

	Bullet OneBullet;

	// NewPlayer 객체는 스크린의 반만큼의 인자를 SetPos함수로 전달한다.
	NewPlayer.SetPos(ScreenSize.Half());


	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');




		bool istriggerpulled = NewPlayer.IsTriggerPulled();

		// 이 플레이어가 방아쇠를 당겼으면
		if (NewPlayer.IsTriggerPulled() == true)
		{	// 총알의 위치에 플레이어 위치를 대입한다.
			OneBullet.SetBulletPos(NewPlayer.GetBulletPos());
		}

		// 플레이어가 방아쇠를 다겼으면 총알은 나갈준비가 되어있다.
		OneBullet.SetBulletFire(NewPlayer.IsTriggerPulled());

		// 총알이 나갈준비가 되어있으면 화면에 총알을 출력할 준비가 되어있다.
		ConsoleGameScreen::GetMainScreen().SetPlayerIsFire(OneBullet.GetBulletFire());

		// 총알의 위치를 알면 ConsoleGmaeScreen클래스의 내부에서 총알의 발사유무를 확인하고, 
		// 총알을 화면에 출력한다.
		ConsoleGameScreen::GetMainScreen().SetScreenBullet(OneBullet.GetBulletPos(), '>');



		ConsoleGameScreen::GetMainScreen().ScreenPrint();


		NewPlayer.Input();
	}

	std::cout << "Hello World!\n";
}