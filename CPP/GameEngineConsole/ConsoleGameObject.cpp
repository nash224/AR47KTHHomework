#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

// 맵에 기호를 나타낸다
void ConsoleGameObject::Render() 
{
	if (false == IsUpdate())
	{
		return;
	}

	// Pos위치에 RenderChar의 기호를 넣는다
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, RenderChar);
}

void ConsoleGameObject::Update() {}