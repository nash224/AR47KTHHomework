#include "Monster.h"
#include "ConsoleGameScreen.h"

int Monster::EntireDirection = 1;

Monster::Monster() 
{
	RenderChar = 'M';
}

void Monster::Update() 
{
	if (false == IsUpdate())
	{
		return;
	}

	Pos.X = Pos.X - Monster::EntireDirection;
}

void Monster::Forward()
{
	Pos.Y = Pos.Y + Monster::Dir;
}


