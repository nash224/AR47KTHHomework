#include <iostream>
#include <conio.h>
// 운영체제가 도와줄수밖에 없다.
#include <Windows.h>

// 숙제 0 << complete!
// 상하좌우로 다 움직이게 해주세요.

// 숙제 1 << complete!
// 잔상 지우기

// 숙제 2 << complete!
// 화면 바깥으로 못나가게 하세요.

// 안해도 되는 숙제 
// 질문했을때 안받아줄겁니다.

// 숙제 3
// 장애물 만들고 배치하세요 당연히 플레이어는 거기로 못갑니다.

// 숙제 4
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

int main()
{
	const int ScreenYSize = 11;
	const int ScreenXSize = 21;

	const int MinScreenXSize = 0;
	const int MaxScreenXSize = ScreenXSize - 1;

	const int MinScreenYSize = 0;
	const int MaxScreenYSize = ScreenYSize - 1;


	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}

	// 정수를 정수로 나오면 실수는 버리고 정수의 값만 나옵니다.
	int PlayerX = ScreenXSize / 2;
	int PlayerY = ScreenYSize / 2;

	while (true)
	{
		system("cls");

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}

		Arr[PlayerY][PlayerX] = '*';

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}


		// 이건 내가 키를 눌렀다면 1
		// 아니라면 0을 리턴하는 함수고 정지하지 않습니다.
		// 키를 눌렀다는것을 체크해주는 함수
		if (0 == _kbhit())
		{
			Sleep(200);	//	0.5초간 멈춘다.
			continue;
		}

		// 어떤키를 눌렀는지 알려주는 함수.
		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
		{
			if (PlayerX != MinScreenXSize)
			{
				PlayerX -= 1;
			}
		}
			break;
		case 'd':
		case 'D':
		{
			if (PlayerX != MaxScreenXSize)
			{
				PlayerX += 1;
			}
		}
			break;
		case 'w':
		case 'W':
		{
			if (PlayerY != MinScreenYSize)
			{
				PlayerY -= 1;
			}
		}
			break;
		case 's':
		case 'S':
		{
			if (PlayerY != MaxScreenYSize)
			{
				PlayerY += 1;
			}
		}
			break;
		break;
		default:
			break;
		}

		Sleep(200);
	}


}