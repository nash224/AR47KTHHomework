#include "Monster.h"
#include "ConsoleGameScreen.h"

// ����ִ� ��ü���� ��ǥ���� ���������ش�
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