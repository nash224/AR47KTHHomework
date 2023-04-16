#include <GameEngineConsole/ConsoleObjectManager.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "Body.h"

Body::Body() 
{
	RenderChar = 'i'; 

	NewBodyCreate();
}

Body::~Body() 
{
}

void Body::NewBodyCreate()
{
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	int ScreenElementCount = ScreenSize.Y * ScreenSize.X;

	ConsoleGameScreen::GetMainScreen().ArrDataClear();
	ConsoleGameScreen::GetMainScreen().SetArrData();
	Parts::SetUnitNumberArray(ScreenElementCount);
	Parts::PutNonUnitNumber();
	this->SetPos(Parts::RandomUnitPos());
	Parts::ClearUnitNumberArray();
}
