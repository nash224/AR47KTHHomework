#include "ConsoleGameScreen.h"
#include <iostream>
#include <Windows.h>
#include "GameEngineArray.h"

// �̱��� ���� : 3��°
// ���� ��ũ���� ��ü�� �����Ѵ�.
ConsoleGameScreen ConsoleGameScreen::MainScreen;

// ��ǥ Ÿ���� �Լ��� ��ȯ�Ѵ�.
////
//int2 ConsoleGameScreen::GetScreenSize()
//{
//	return Size;
//}


void ConsoleGameScreen::SetScreenSize(int2 _Size)
{
	Size = _Size;


	// char** 
	// ArrScreen == new char* Arr[y]

	// 2 ���� �迭 = new 1���� Y�迭
	// GameEngineArray<GameEngineArray<char>>
	ArrScreen.ReSize(Size.Y);

	for (size_t i = 0; i < Size.Y; i++)
	{
		// GameEngineArray<char>
		ArrScreen.ReSize(Size.X);
	}
}

// ��ũ���� ���� �ʱ�ȭ �ϰڴ�.
void ConsoleGameScreen::ScreenClear()
{
	system("cls");

	// y���� ���� �ݺ���
	for (size_t y = 0; y < this->Size.Y; y++)
	{	// x���� ���� �ݺ���
		for (size_t x = 0; x < this->Size.X; x++)
		{	// (x,y)�� ���� a�� �ʱ�ȭ�Ѵ�.
			ArrScreen[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{

	for (size_t y = 0; y < this->Size.Y; y++)
	{
		for (size_t x = 0; x < this->Size.X; x++)
		{
			// Arr[y][x] = 'b';
			printf_s("%c", ArrScreen[y][x]);
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

	if (this->Size.X <= _Pos.X)
	{
		return true;
	}

	if (this->Size.Y <= _Pos.Y)
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
	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}


// ���� ��ũ���� ������
// Ư���� ��� �Լ��μ� �ڵ����� ���� ���� ȣ��ǰ�, 
// �ֿ� ������ ��� ������ �ʱ�ȭ�̴�.
ConsoleGameScreen::ConsoleGameScreen()
{
}


ConsoleGameScreen::~ConsoleGameScreen()
{
	//for (size_t i = 0; i < Size.Y; i++)
	//{ 
	//	if (nullptr == ArrScreen[i])
	//	{
	//		continue;
	//	}
	//	delete[] ArrScreen[i];
	//	ArrScreen[i] = nullptr;
	//}

	//if (nullptr == ArrScreen)
	//{
	//	return;
	//}

	//delete[] ArrScreen;
	//ArrScreen = nullptr;
}

