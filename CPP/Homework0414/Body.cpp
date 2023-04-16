#include <GameEngineConsole/ConsoleObjectManager.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "Body.h"

Body::Body() 
{
	RenderChar = 'i';

	

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
	SetPos({ X, Y });
}

Body::~Body() 
{
}

