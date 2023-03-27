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

class BomberMan_Game
{
public:
	//	지도 크기

	//	class안으로 들어가게 되면 메모리 영역이 어디에든 넣을 수 있어서 변수로 선언되므로,
	//	배열안에 변수를 넣을 수 없다.

	//	static을 선언하면 클래스 내부에서 전역변수로 사용할 수 있다.
	static const int ScreenYSize = 11;
	static const int ScreenXSize = 21;
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	//	지도 최소치 또는 최대치
	const int MinScreenXSize = 0;
	const int MinScreenYSize = 0;
	const int MaxScreenXSize = ScreenXSize - 1;
	const int MaxScreenYSize = ScreenYSize - 1;


	int PlayerX = ScreenXSize / 2;
	int PlayerY = ScreenYSize / 2;

	int Bombcount = 0;	
	int aftercount = 0;
	int afterimage_count = 0;

};




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
			else if (Arr[y][x] == 'B')	//	폭탄 로직
			{
				Arr[y][x] = 'B';

				Bombcount++;

				if (Bombcount == 7)	//	폭탄 터지는 시간
				{
					Arr[y][x] = 'P';
					Bombcount = 0;

					for (int i = 0; i < 5; i++)
					{
						aftercount++;
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
			else if (Arr[y][x] == '@')	//	잔상 처리
			{
				Arr[y][x] = '@';

				afterimage_count++;

				if (afterimage_count > 10)
				{
					Arr[y][x] = 'a';
				}
			}
			else if (x == MinScreenXSize)	//	윗쪽 외벽
			{
				Arr[y][x] = 'b';
			}
			else if (x == MaxScreenXSize)	//	아랫쪽 외벽
			{
				Arr[y][x] = 'b';
			}
			else if (y == MinScreenXSize)	//	왼쪽 외벽
			{
				Arr[y][x] = 'b';
			}
			else if (y == MaxScreenYSize)	//	오른쪽 외벽
			{
				Arr[y][x] = 'b';
			}
			else	//	필드
			{
				Arr[y][x] = 'a';
			}
			aftercount++;
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
void NoticetheGame()
{
	printf_s("\n\n");
	printf_s("=====================\n\n");
	printf_s("벽 설치 : T\n");
	printf_s("폭탄 설치 : F\n");
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

	NoticetheGame();
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