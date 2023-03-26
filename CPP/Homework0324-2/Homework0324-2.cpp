#include <iostream>
#include <conio.h>
#include <Windows.h>

// 숙제 0 << complete!
// 상하좌우로 다 움직이게 해주세요.

// 숙제 1 << complete!
// 잔상 지우기

// 숙제 2 << complete!
// 화면 바깥으로 못나가게 하세요.

// 안해도 되는 숙제 
// 질문했을때 안받아줄겁니다.

// 숙제 3 << complete!
// 장애물 만들고 배치하세요 당연히 플레이어는 거기로 못갑니다.

// 숙제 4 << complete!
// 폭탄 f를 누를면 폭탄이 설치되고 눈에 보여야 합니다. 폭탄 @

// 숙제 5
// 일정시간이 지나고 폭탄이 터지면서
//     @
//     @
//     @
//  @@@@@@@
//     @
//     @
//     @


//	지도 크기
const int ScreenYSize = 11;
const int ScreenXSize = 21;

//	지도 최소치 또는 최대치
const int MinScreenXSize = 0;
const int MinScreenYSize = 0;
const int MaxScreenXSize = ScreenXSize - 1;
const int MaxScreenYSize = ScreenYSize - 1;

char Arr[ScreenYSize][ScreenXSize] = { 0, };

int PlayerX = ScreenXSize / 2;
int PlayerY = ScreenYSize / 2;

int count = 0;
int aftercount = 1;
int afterimage_count = 0;


//	지도 생성
inline void MapComposition() 
{
	//Arr[2][2] = 'b';

	for (int y = 0; y < ScreenYSize; y++)
	{
		for (int x = 0; x < ScreenXSize; x++)
		{
			if (Arr[y][x] == 'b')
			{
				Arr[y][x] = 'b';
			}
			else if (Arr[y][x] == 'B')
			{
				Arr[y][x] = 'B';

				count++;

				if (count == 7)
				{
					Arr[y][x] = 'P';

					for (int i = 0; i < 5; i++)
					{
						Arr[y][x - i] = '@';
						Arr[y][x + i] = '@';
						Arr[y - i][x] = '@';
						Arr[y + i][x] = '@';
					}
				}
			}
			else if (Arr[y][x] == 'P')
			{
				Arr[y][x] = 'P';
			}
			else if (Arr[y][x] == '@')
			{
				Arr[y][x] = '@';

				afterimage_count++;

				if (afterimage_count > 10)
				{
					Arr[y][x] = 'a';
				}
			}
			else if (x == MinScreenXSize)
			{
				Arr[y][x] = 'b';
			}
			else if (x == MaxScreenXSize)
			{
				Arr[y][x] = 'b';
			}
			else if (y == MinScreenXSize)
			{
				Arr[y][x] = 'b';
			}
			else if (y == MaxScreenYSize)
			{
				Arr[y][x] = 'b';
			}
			else
			{
				Arr[y][x] = 'a';
			}
		}
	}
}

//	물체 판정
void Interact_Objects()
{
	if (Arr[PlayerY][PlayerX] != 'b' && Arr[PlayerY][PlayerX] != 'B' && Arr[PlayerX][PlayerY] != '@')
	{
		Arr[PlayerY][PlayerX] = '*';
	}
}


//	벽 로직
void Plant_Wall()
{
	Arr[PlayerY][PlayerX] = 'b';
}

//	폭탄 로직
void Plant_Bomb()
{
	Arr[PlayerY][PlayerX] = 'B';

}

//	입력처리
inline void KeyInputProcessing()
{
	char Ch = _getch();


	switch (Ch)
	{
	case 'a':
	case 'A':
	{
		if (Arr[PlayerY][PlayerX - 1] != 'b')
		{
			PlayerX -= 1;
		}

	}
	break;
	case 'd':
	case 'D':
	{
		if (Arr[PlayerY][PlayerX + 1] != 'b')
		{
			PlayerX += 1;
		}

	}
	break;
	case 'w':
	case 'W':
	{
		if (Arr[PlayerY - 1][PlayerX] != 'b')
		{
			PlayerY -= 1;
		}

	}
	break;
	case 's':
	case 'S':
	{
		if (Arr[PlayerY + 1][PlayerX] != 'b')
		{
			PlayerY += 1;
		}

	}
	break;

	case 't':
	case 'T':
	{
		Plant_Wall();
	}
	break;
	case 'f':
	case 'F':
	{
		Plant_Bomb();
	}
	break;
	default:
		break;
	}
}

//	게임 출력
inline void GameRender()
{
	system("cls");

	for (int y = 0; y < ScreenYSize; y++)
	{
		for (int x = 0; x < ScreenXSize; x++)
		{
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}


int main()
{
	while (true)
	{
		MapComposition();
		Interact_Objects();

		if (_kbhit())
		{
			KeyInputProcessing();
		}
		GameRender();


		if (0 == _kbhit())
		{
			Sleep(200);
			continue;
		}
	}
}