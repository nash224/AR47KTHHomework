#include "ConsoleGameScreen.h"
#include "ConsoleGameObject.h"
#include "ConsoleObjectManager.h"
#include <iostream>
#include <list>

// 객체생성
ConsoleGameScreen ConsoleGameScreen::MainScreen;

// 싹다 a로 초기화
void ConsoleGameScreen::ScreenClear()
{
	system("cls");

	for (size_t y = 0; y < this->Size.Y; y++)
	{
		for (size_t x = 0; x < this->Size.X; x++)
		{
			ArrScreen[y][x] = L'□';
		}
	}
}

void ConsoleGameScreen::ArrDataClear()
{

	for (size_t y = 0; y < this->Size.Y; y++)
	{
		for (size_t x = 0; x < this->Size.X; x++)
		{
			ArrData[y][x] = 0;
		}
	}
}

// 객체들의 정보를 넣음
void ConsoleGameScreen::ScreenPrint() const
{
	setlocale(LC_ALL, "KOR");
	for (size_t y = 0; y < this->Size.Y; y++)
	{
		for (size_t x = 0; x < this->Size.X; x++)
		{
			// Arr[y][x] = 'b';
			wprintf_s(L"%c", ArrScreen[y][x]);
		}
		wprintf_s(L"\n");
	}
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

	//if (nullptr != ArrScreen)
	//{
	//	delete[] ArrScreen;
	//	ArrScreen = nullptr;
	//}
}

void ConsoleGameScreen::SetScreenSize(int2 _Size)
{
	Size = _Size;

	// 크기에 맞게 할당받은 배열의 크기를 늘려줌
	ArrScreen.resize(Size.Y);

	for (size_t i = 0; i < Size.Y; i++)
	{
		ArrScreen[i].resize(Size.X);
	}
}

void ConsoleGameScreen::SetArrDataSize()
{
	ArrData.resize(Size.Y);

	for (size_t i = 0; i < Size.Y; i++)
	{
		ArrData[i].resize(Size.X);
	}
}

// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	// this는 여기 정보
	if (this->Size.X <= _Pos.X)
	{
		return true;
	}

	if (this->Size.Y <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, wchar_t _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}

void ConsoleGameScreen::PutArrDataPartsPos(int2& _PartsPos)
{
	ArrData[_PartsPos.Y][_PartsPos.X] = 1;
}

ConsoleGameScreen::ConsoleGameScreen()
{
}

int2 ConsoleGameScreen::GetScreenSize()
{
	return Size;
}