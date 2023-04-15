#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

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

void Body::CreateBody()
{
	std::list<ConsoleGameObject*>& HeadGroup
		= ConsoleObjectManager::GetGroup(0);

	
	std::list<ConsoleGameObject*>::iterator Start = HeadGroup.begin();
	

	ConsoleObjectManager::CreateConsoleObject<Body>(1);
	
}