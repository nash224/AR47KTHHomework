#include <iostream>
#include <windows.h>
#include <conio.h>

class ConsoleGameScreen
{
public:

	static const int ScreenYSize = 10;
	static const int ScreenXSize = 10;
	char Arr[ScreenYSize][ScreenXSize] = { 0 , }; 

	void ScreenClear()
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}
	}

	void ScreenPrint()
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");

		}
	}

private:

};


int main()
{
	ConsoleGameScreen Game;

	for (size_t y = 0; y < Game.ScreenYSize; y++)
	{
		for (size_t x = 0; x < Game.ScreenXSize; x++)
		{
			Game.Arr[y][x] = 'a';
		}
	}

	int PlayerX = Game.ScreenXSize / 2;
	int PlayerY = Game.ScreenYSize / 2;


	while (true)
	{
		system("cls");

		Game.ScreenClear();

		Game.Arr[PlayerY][PlayerX] = '*';

		Game.ScreenPrint();

		if (0 == _kbhit())
		{
			Sleep(200);
		}
		
		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
		{
			PlayerX -= 1;
		}
			break;
		case 'd':
		case 'D':
		{
			PlayerX += 1;
		}
		break;
		case 'w':
		case 'W':
		{
			PlayerY -= 1;
		}
		break;
		case 's':
		case 'S':
		{
			PlayerY += 1;
		}
		break;

		default:
			break;
		}

	}
	Sleep(200);
}