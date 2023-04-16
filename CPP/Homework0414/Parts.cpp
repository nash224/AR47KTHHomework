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
	//ConsoleGameScreen::GetMainScreen().

	int count = -1;

	for (size_t i = 0; i < ScreenSize.Y; i++)
	{
		for (size_t i = 0; i < ScreenSize.X; i++)
		{
			count++;
			
			if ()
			{

			}
		}

	}
}


void Parts::Update() 
{
	ConsoleGameObject::Update();
}