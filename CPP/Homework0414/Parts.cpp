#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include <list>
#include "Parts.h"

int Parts::PartsCount = 0;

std::vector<int> Parts::NonUnitNumberArray;

Parts::Parts() 
{
	PartsCount++;
}

Parts::~Parts() 
{
	PartsCount--;
}

void Parts::SetArrData()
{
	std::list<ConsoleGameObject*>& HeadGroup
		= ConsoleObjectManager::GetGroup(0);

	std::list<ConsoleGameObject*>::iterator StartHeadGroup = HeadGroup.begin();

	ConsoleGameObject* HeadPtr = *StartHeadGroup;

	Parts* HeadParts = dynamic_cast<Parts*>(HeadPtr);

	int2 HeadBeforePos = HeadParts->GetBeforePos();

	ConsoleGameScreen::GetMainScreen().PutArrDataPartsPos(HeadBeforePos);

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
		int2 CurretnBodyPos = CurrentBodyPtr->GetPos();
		ConsoleGameScreen::GetMainScreen().PutArrDataPartsPos(CurretnBodyPos);
	}
}

void Parts::PutNonUnitNumber()
{
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();

	int count = -1;

	for (size_t y = 0; y < ScreenSize.Y; y++)
	{
		std::vector<int> ArrPtr = ConsoleGameScreen::GetMainScreen().GetArrData(y);
		for (size_t x = 0; x < ScreenSize.X; x++)
		{
			count++;
			
			if (0 == ArrPtr[x])
			{
				Parts::UnitNumberPushback(count);
			}
		}

	}
}

int2 Parts::RandomUnitPos()
{
	int2 Screensize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	int RandomMax = Screensize.Y * Screensize.X - PartsCount;

	int DrawNumberOder = GameEngineRandom::MainRandom.RandomInt(0, RandomMax);

	int DrawNumber = NonUnitNumberArray[DrawNumberOder];

	int X = DrawNumber % Screensize.X;
	int Y = DrawNumber / Screensize.X;

	int2 BodyCreatePos = { X , Y };

	return BodyCreatePos;
}

void Parts::Update() 
{
	ConsoleGameObject::Update();
}


void Parts::LinktoNext(Parts* _OtherParts)
{
	this->Next = _OtherParts;
	_OtherParts->Prev = this;
}

void Parts::LinktoPrev(Parts* _OtherParts)
{
	this->Prev = _OtherParts;
	_OtherParts->Next = this;
}