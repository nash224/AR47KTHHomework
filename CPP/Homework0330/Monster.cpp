#include "Monster.h"
#include "ConsoleGameScreen.h"

// 살아있는 객체들을 좌표값에 랜더링해준다
void Monster::Render()
{
	if (false == IsUpdate())
	{
		return;
	}


	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, 'M');
}


void Monster::Update()
{
	if (false == IsUpdate())
	{
		return;
	}
}