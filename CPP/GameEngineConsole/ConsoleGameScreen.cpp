#include "ConsoleGameScreen.h"
#include <iostream>
#include <Windows.h>
#include "GameEngineArray.h"

// �̱��� ���� : 3��°
// ���� ��ũ���� ��ü�� �����Ѵ�.
ConsoleGameScreen ConsoleGameScreen::MainScreen;

// ��ũ���� ���� �ʱ�ȭ �ϰڴ�.
void ConsoleGameScreen::ScreenClear()
{
	system("cls");

	// y���� ���� �ݺ���
	for (size_t y = 0; y < ScreenYSize; y++)
	{	// x���� ���� �ݺ���
		for (size_t x = 0; x < ScreenXSize; x++)
		{	// (x,y)�� ���� a�� �ʱ�ȭ�Ѵ�.
			Arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			// Arr[y][x] = 'b';
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

// ��ȯ���� bool�̰�, ��� ������ ���� ���� ���� ���ϰ� �ϸ�,
// int2 ���� Ÿ���� ��� �Ű������� �޴� IsScreenOver() ����Լ��� �����Ѵ�.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	// x�� 0���� ������ ���� ��ȯ�Ѵ�.
	if (0 > _Pos.X)
	{
		return true;
	}
	// y�� 0���� ������ ���� ��ȯ�Ѵ�.
	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenXSize <= _Pos.X)
	{
		return true;
	}

	if (ScreenYSize <= _Pos.Y)
	{
		return true;
	}
	// �� �ƴ϶�� false�� ��ȯ�Ѵ�.
	return false;
}

// ��ȯ Ÿ���� ����, �� �Ű������� �޾� �����ϰڴ�.
void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	// ��ġ�� ȭ���� �Ѿ�� ��ȯ�Ѵ�.
	if (true == IsScreenOver(_Pos))
	{
		return;
	}
	// ������ġ�� _Ch�� �ִ´�
	Arr[_Pos.Y][_Pos.X] = _Ch;
}


// ���� ��ũ���� ������
// Ư���� ��� �Լ��μ� �ڵ����� ���� ���� ȣ��ǰ�, 
// �ֿ� ������ ��� ������ �ʱ�ȭ�̴�.
ConsoleGameScreen::ConsoleGameScreen()
{
}

// ��ǥ Ÿ���� �Լ��� ��ȯ�Ѵ�.
//
int2 ConsoleGameScreen::GetScreenSize()
{
	return int2{ ScreenXSize, ScreenYSize };
}