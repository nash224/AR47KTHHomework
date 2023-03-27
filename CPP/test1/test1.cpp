#include <iostream>
#include <conio.h>
#include <Windows.h>

// 폭탄의 시간을 재주는 함수
void BombTimeCounting(short* _BombTimerArr, const short _MaxBombNum)
{
	for (size_t i = 0; i < _MaxBombNum; i++)
	{
		if (_BombTimerArr[i] > 3)
		{
			--_BombTimerArr[i];
		}
	}
}

int main()
{
	// 기본 맵 틀 생성
	const short ScreenYSize = 20;
	const short ScreenXSize = 20;

	// 맵 출력 구조물 구분 숫자
	const short EmptySpaceIconNum = 0;
	const short WallIconNum = 1;
	const short InstallWallIconNum = 2;
	const short BombIconNum = 3;
	const short Explosion = 5;

	// 폭탄 기준 데이터 구조물 구분 숫자
	const short BombLocEmptySpaceIconNum = -1;
	const short BombLocWallIconNum = -2;
	const short BombLocInstallWallIconNum = -3;

	// 맵 초기화
	short MapDataArr[ScreenYSize][ScreenXSize] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,2,2,2,2,2,2,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,0,2,2,0,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,0,2,2,0,2,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,2,2,2,2,2,2,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	// 폭탄 위치 배열 : 0 ~ 최대폭탄개수 의 숫자는 각각 폭탄의 시간과 위치를 저장시킨다.
	short BombLocationArr[ScreenYSize][ScreenXSize];

	// 폭발 위치 제어 배열 : 0이면 지나가고 1이면 지나갈 수 없음
	short AnimationArr[ScreenYSize][ScreenXSize];

	// 맵 초기화
	for (short y = 0; y < ScreenYSize; y++)
	{
		for (short x = 0; x < ScreenXSize; x++)
		{
			if (MapDataArr[y][x] == 1)
			{
				BombLocationArr[y][x] = BombLocWallIconNum;
				AnimationArr[y][x] = WallIconNum;
			}
			else if (MapDataArr[y][x] == 0)
			{
				BombLocationArr[y][x] = BombLocEmptySpaceIconNum;
				AnimationArr[y][x] = EmptySpaceIconNum;
			}
			else if (MapDataArr[y][x] == 2)
			{
				BombLocationArr[y][x] = BombLocEmptySpaceIconNum;
				AnimationArr[y][x] = WallIconNum;
			}
		}
	}

	// 30프레임
	const short ScreenFrame = 33;

	// 화면 변환
	short ChangeWindow = 0;

	const short MaxBombNum = 5; // 폭탄 설치 개수
	short BombNumCount = 0; // 설치된 폭탄 개수
	const short TimeOfBomb = 30; // 폭탄의 시간
	short BombTimerArr[MaxBombNum] = { 0, }; // 폭탄마다 시간 저장
	const short BombAnimCount = 1; // 폭탄 애니메이션 주기값

	// 플레이어 좌표
	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 4;

	while (true)
	{
		// 화면 초기화
		system("cls");

		for (short y = 0; y < ScreenYSize; y++)
		{
			for (short x = 0; x < ScreenXSize; x++)
			{
				if (BombLocationArr[y][x] >= 0) // 폭탄의 위치번호는 0보다 크거나 같음
				{
					// 첫 번째 애니메이션 조건
					if (BombTimerArr[BombLocationArr[y][x]] == 3)
					{
						// 세로 폭발
						for (short i = y - 1; i <= y + 1; i += 2)
						{
							if (MapDataArr[i][x] == InstallWallIconNum) // 이곳에 설치 된 벽이 있는가?
							{
								MapDataArr[i][x] = Explosion;
							}
							else if (MapDataArr[i][x] == BombIconNum) // 이곳에 폭탄이 있는가?
							{
								BombTimerArr[BombLocationArr[i][x]] = 3;
							}
							else if (MapDataArr[i][x] == EmptySpaceIconNum) // 이곳에 아무것도 없는가?
							{
								MapDataArr[i][x] = Explosion;
							}
						}
						// 가로 폭발
						for (short i = x - 1; i <= x + 1; i += 2)
						{
							if (MapDataArr[y][i] == InstallWallIconNum) // 이곳에 설치 된 벽이 있는가?
							{
								MapDataArr[y][i] = Explosion;
							}
							else if (MapDataArr[y][i] == BombIconNum) // 이곳에 폭탄이 있는가? 
							{
								BombTimerArr[BombLocationArr[y][i]] = 3;
							}
							else if (MapDataArr[y][i] == EmptySpaceIconNum) // 이곳에 아무것도 없는가?
							{
								MapDataArr[y][i] = Explosion;
							}
						}
						// 중심
						MapDataArr[y][x] = Explosion;
						BombTimerArr[BombLocationArr[y][x]]--;
					}
					// 두 번째 애니메이션 조건
					else if (BombTimerArr[BombLocationArr[y][x]] == 2)
					{
						// 세로 폭발
						for (short i = y - 2; i <= y + 2; i += 4)
						{
							if (i < y)
							{
								if (AnimationArr[i + 1][x] != WallIconNum)
								{
									if (MapDataArr[i][x] == InstallWallIconNum)
									{
										MapDataArr[i][x] = Explosion;
										AnimationArr[i][x] = EmptySpaceIconNum;
									}
									else if (MapDataArr[i][x] == BombIconNum)
									{
										BombTimerArr[BombLocationArr[i][x]] = 3;
									}
									else if (MapDataArr[i][x] == EmptySpaceIconNum)
									{
										MapDataArr[i][x] = Explosion;
									}
								}
								else if (AnimationArr[i + 1][x] == WallIconNum)
								{
									if (MapDataArr[i + 1][x] != WallIconNum)
									{
										AnimationArr[i + 1][x] = EmptySpaceIconNum;
									}
								}
							}
							else if (i > y)
							{
								if (AnimationArr[i - 1][x] != 1)
								{
									if (MapDataArr[i][x] == InstallWallIconNum)
									{
										MapDataArr[i][x] = Explosion;
										AnimationArr[i][x] = EmptySpaceIconNum;
									}
									else if (MapDataArr[i][x] == BombIconNum)
									{
										BombTimerArr[BombLocationArr[i][x]] = 3;
									}
									else if (MapDataArr[i][x] == EmptySpaceIconNum)
									{
										MapDataArr[i][x] = Explosion;
									}
								}
								else if (AnimationArr[i - 1][x] == WallIconNum)
								{
									if (MapDataArr[i - 1][x] != WallIconNum)
									{
										AnimationArr[i - 1][x] = EmptySpaceIconNum;
									}
								}
							}
						}
						// 가로 폭발
						for (short i = x - 2; i <= x + 2; i += 4)
						{
							if (i < x)
							{
								if (AnimationArr[y][i + 1] != WallIconNum)
								{
									if (MapDataArr[y][i] == InstallWallIconNum)
									{
										MapDataArr[y][i] = Explosion;
										AnimationArr[y][i] = EmptySpaceIconNum;
									}
									else if (MapDataArr[y][i] == BombIconNum)
									{
										BombTimerArr[BombLocationArr[y][i]] = 3;
									}
									else if (MapDataArr[y][i] == EmptySpaceIconNum)
									{
										MapDataArr[y][i] = Explosion;
									}
								}
								else if (AnimationArr[y][i + 1] == WallIconNum)
								{
									if (MapDataArr[y][i + 1] != WallIconNum)
									{
										AnimationArr[y][i + 1] = EmptySpaceIconNum;
									}
								}
							}
							else if (i > x)
							{
								if (AnimationArr[y][i - 1] != 1)
								{
									if (MapDataArr[y][i] == InstallWallIconNum)
									{
										MapDataArr[y][i] = Explosion;
										AnimationArr[y][i] = EmptySpaceIconNum;
									}
									else if (MapDataArr[y][i] == BombIconNum)
									{
										BombTimerArr[BombLocationArr[y][i]] = 3;
									}
									else if (MapDataArr[y][i] == EmptySpaceIconNum)
									{
										MapDataArr[y][i] = Explosion;
									}
								}
								else if (AnimationArr[y][i - 1] == 1)
								{
									if (MapDataArr[y][i - 1] != 1)
									{
										AnimationArr[y][i - 1] = 0;
									}
								}
							}
						}
						BombTimerArr[BombLocationArr[y][x]]--;
					}
					// 폭발 이펙트 초기화
					else if (BombTimerArr[BombLocationArr[y][x]] == 1)
					{
						// 폭탄 시간 배열 초기화
						BombTimerArr[BombLocationArr[y][x]] = 0;

						// 폭탄 위치 배열 초기화
						BombLocationArr[y][x] = BombLocEmptySpaceIconNum;

						// 맵 폭발 이펙트 초기화
						for (short i = y - 2; i <= y + 2; i++)
						{
							if (MapDataArr[i][x] == Explosion)
							{
								MapDataArr[i][x] = EmptySpaceIconNum;
							}
						}
						for (short i = x - 2; i <= x + 2; i++)
						{
							if (MapDataArr[y][i] == Explosion)
							{
								MapDataArr[y][i] = EmptySpaceIconNum;
							}
						}
					}
				}
			}
		}

		// 실시간 폭탄 개수 카운트
		BombNumCount = 0;
		for (short i = 0; i < MaxBombNum; i++)
		{
			if (BombTimerArr[i] > 0)
			{
				BombNumCount++;
			}
		}

		// 메인 화면 출력
		for (short y = 0; y < ScreenYSize; y++)
		{
			for (short x = 0; x < ScreenXSize; x++)
			{
				if (x == PlayerX && y == PlayerY)
				{
					printf_s("●");
				}
				else {
					switch (MapDataArr[y][x])
					{
					case EmptySpaceIconNum:
						printf_s("  ");
						break;

					case WallIconNum:
						printf_s("■");
						break;

					case InstallWallIconNum:
						printf_s("▣");
						break;

					case BombIconNum:
						printf_s("δ");
						break;

					case Explosion:
						printf_s("＠");
						break;
					}
				}
			}
			// 개발자 화면 1 : 폭탄 위치 저장 배열
			if (ChangeWindow == 1)
			{
				printf_s("  ");

				for (short x = 0; x < ScreenXSize; x++)
				{
					if (BombLocationArr[y][x] == BombLocWallIconNum)
					{
						printf_s("■");
					}
					else {
						printf_s("%2d", BombLocationArr[y][x]);
					}

				}
			}
			// 개발자 화면 2 : 메인 화면 실제 배열
			else if (ChangeWindow == 2)
			{
				printf_s("  ");

				for (short x = 0; x < ScreenXSize; x++)
				{
					printf_s("%2d", MapDataArr[y][x]);
				}
			}
			// 개발자 화면 3 : 폭발 위치 제어 배열
			else if (ChangeWindow == 3)
			{
				printf_s("  ");

				for (short x = 0; x < ScreenXSize; x++)
				{
					printf_s("%2d", AnimationArr[y][x]);
				}
			}
			printf_s("\n");
		}

		switch (ChangeWindow)
		{
		case 0:
			printf_s("\n  [ G ]: 장애물 설치  [ F ]: 폭탄 설치                                \n");
			break;
		case 1:
			printf_s("\n  [ G ]: 장애물 설치  [ F ]: 폭탄 설치              폭탄 위치 저장 배열\n");
			break;
		case 2:
			printf_s("\n  [ G ]: 장애물 설치  [ F ]: 폭탄 설치              메인 화면 실제 배열\n");
			break;
		case 3:
			printf_s("\n  [ G ]: 장애물 설치  [ F ]: 폭탄 설치              폭발 위치 제어 배열\n");
			break;
		}
		printf_s("\n                                                    [ M ]: 개발 모드(%d)\n        ", ChangeWindow);

		// 폭탄 정보 출력 화면
		for (short i = 0; i < MaxBombNum; i++)
		{
			printf_s(" %2d ", BombTimerArr[i]);
		}
		printf_s("\n\n    설치된 폭탄 수: %2d  (최대 %d개)      \n", BombNumCount, MaxBombNum);

		// 키를 누르지 않을 때 작업
		if (0 == _kbhit())
		{
			// 키 입력 없을 시 폭탄 시간 감소
			BombTimeCounting(BombTimerArr, MaxBombNum);

			Sleep(ScreenFrame);
			continue;
		}

		// 키 입력
		char Ch = _getch();

		// 키 입력 중 폭탄 시간 감소
		BombTimeCounting(BombTimerArr, MaxBombNum);

		// 키 값 대응
		switch (Ch)
		{
		case 'w':
		case 'W':
			if (MapDataArr[PlayerY - 1][PlayerX] == WallIconNum ||
				MapDataArr[PlayerY - 1][PlayerX] == InstallWallIconNum ||
				MapDataArr[PlayerY - 1][PlayerX] == BombIconNum)
			{
				break;
			}
			else
			{
				--PlayerY;
				break;
			}

		case 's':
		case 'S':
			if (MapDataArr[PlayerY + 1][PlayerX] == WallIconNum ||
				MapDataArr[PlayerY + 1][PlayerX] == InstallWallIconNum ||
				MapDataArr[PlayerY + 1][PlayerX] == BombIconNum)
			{
				break;
			}
			else
			{
				++PlayerY;
				break;
			}

		case 'a':
		case 'A':
			if (MapDataArr[PlayerY][PlayerX - 1] == WallIconNum ||
				MapDataArr[PlayerY][PlayerX - 1] == InstallWallIconNum ||
				MapDataArr[PlayerY][PlayerX - 1] == BombIconNum)
			{
				break;
			}
			else
			{
				--PlayerX;
				break;
			}

		case 'd':
		case 'D':
			if (MapDataArr[PlayerY][PlayerX + 1] == WallIconNum ||
				MapDataArr[PlayerY][PlayerX + 1] == InstallWallIconNum ||
				MapDataArr[PlayerY][PlayerX + 1] == BombIconNum)
			{
				break;
			}
			else
			{
				++PlayerX;
				break;
			}

			// 장애물 설치
		case 'g':
		case 'G':
			if (MapDataArr[PlayerY][PlayerX] != EmptySpaceIconNum)
			{
				break;
			}
			MapDataArr[PlayerY][PlayerX] = InstallWallIconNum;
			AnimationArr[PlayerY][PlayerX] = WallIconNum;
			break;

			// 폭탄
		case 'f':
		case 'F':

			// 폭탄은 빈 공간일 경우에만 설치 가능하다.
			// 폭탄의 최대 설치 수 제한
			if (MapDataArr[PlayerY][PlayerX] != 0 || BombNumCount == MaxBombNum)
			{
				break;
			}

			MapDataArr[PlayerY][PlayerX] = BombIconNum;

			// 위치 저장
			for (short i = 0; i < MaxBombNum; i++)
			{
				if (BombTimerArr[i] == 0)
				{
					BombLocationArr[PlayerY][PlayerX] = i;
					BombTimerArr[i] = TimeOfBomb;
					break;
				}
			}
			break;

		case 'm':
		case 'M':
			if (ChangeWindow != 3)
			{
				ChangeWindow++;
			}
			else {
				ChangeWindow -= 3;
			}
			break;

		default:
			break;
		}

		Sleep(ScreenFrame);
	}
}