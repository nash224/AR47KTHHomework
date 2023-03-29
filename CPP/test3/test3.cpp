#include <iostream>
#include <windows.h>
#include <conio.h>

class int2
{
public:
	int X;
	int Y;

};

class ConsoleGameScreen
{
public:

	static const int ScreenYSize = 3;
	static const int ScreenXSize = 3;


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

	void ScreenPrint() const
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

	void SetScreenCharacter(const int2 _Pos, char _Ch)
	{
		Arr[_Pos.X][_Pos.Y] = _Ch;
	}

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0 , };

};

class Player
{
public:

private:
	int2 Pos;
};


int main()
{
	ConsoleGameScreen Game;

	Player NewPlayer;



	while (true)
	{
		system("cls");

		Game.ScreenClear();



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