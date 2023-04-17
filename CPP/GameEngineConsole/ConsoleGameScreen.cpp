#include "ConsoleGameScreen.h"
#include "ConsoleGameObject.h"
#include "ConsoleObjectManager.h"
#include <iostream>
#include <list>

// ��ü����
ConsoleGameScreen ConsoleGameScreen::MainScreen;

// �ϴ� a�� �ʱ�ȭ
void ConsoleGameScreen::ScreenClear()
{
	system("cls");

	for (size_t y = 0; y < this->Size.Y; y++)
	{
		for (size_t x = 0; x < this->Size.X; x++)
		{
			ArrScreen[y][x] = 'a';
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

// ��ü���� ������ ����
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

	// ũ�⿡ �°� �Ҵ���� �迭�� ũ�⸦ �÷���
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

// �̳༮�� ������ ����ؼ� �÷��̾ �ٱ����� �������� ���弼��.
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

	// this�� ���� ����
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

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}

void ConsoleGameScreen::PutArrDataPartsPos(ConsoleGameObject* _PartsPos)
{
	int2 PartsPos = _PartsPos->GetPos();
	ArrData[PartsPos.Y][PartsPos.X] = 1;
	
}

void ConsoleGameScreen::SetArrData()
{
	std::list<ConsoleGameObject*>& HeadGroup
		= ConsoleObjectManager::GetGroup(0);

	std::list<ConsoleGameObject*>::iterator StartHeadGroup = HeadGroup.begin();

	ConsoleGameObject* HeadPtr = *StartHeadGroup;

	ConsoleGameScreen::GetMainScreen().PutArrDataPartsPos(HeadPtr);


	std::list<ConsoleGameObject*>& BodyGroup
		= ConsoleObjectManager::GetGroup(1);

	std::list<ConsoleGameObject*>::iterator BodyGroupStart = BodyGroup.begin();
	std::list<ConsoleGameObject*>::iterator BodyGroupEnd = BodyGroup.end();

	for (; BodyGroupStart != BodyGroupEnd; BodyGroupStart++)
	{
		ConsoleGameObject* CurrentBodyPtr = *BodyGroupStart;

		if (nullptr == CurrentBodyPtr)
		{
			continue;
		}

		ConsoleGameScreen::GetMainScreen().PutArrDataPartsPos(CurrentBodyPtr);
	}
}


ConsoleGameScreen::ConsoleGameScreen()
{
}

int2 ConsoleGameScreen::GetScreenSize()
{
	return Size;
}