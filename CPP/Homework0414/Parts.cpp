#include "Parts.h"
#include <GameEngineConsole/ConsoleGameScreen.h>

size_t Parts::PartsCount = 0;

std::vector<int> Parts::NonUnitNumberArray;

Parts::Parts() 
{
	PartsCount++;
}

Parts::~Parts() 
{
	PartsCount--;
}


void Link(Parts* _Other1, Parts* _Other2)
{
}

static void PutNonUnitNumber()
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


void Parts::Update() 
{
	ConsoleGameObject::Update();
}