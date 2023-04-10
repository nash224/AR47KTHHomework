// Homework0407.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <conio.h>

int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 20 , 10 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	while (true)
	{
		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		char Input = _getch();

		switch (Input)
		{
		case'q':
			return 0;
		default:
			break;
		}

		Sleep(500);
	}
}
