#include "Head.h"
#include <conio.h>
#include "Body.h"
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

bool Head::IsPlay = true;

Head::Head() 
{
	RenderChar = '$';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

Head::~Head() 
{
}

bool Head::isBody(const int2 _NextPos)
{
	std::list<ConsoleGameObject*>& BodyGroup
		= ConsoleObjectManager::GetGroup(1);

	std::list<ConsoleGameObject*>::iterator Start = BodyGroup.begin();

	ConsoleGameObject* Ptr = *Start;

	if (Ptr->GetPos() == _NextPos)
	{
		return true;
	}

	return false;
}

void Head::CreateBody()
{
	ConsoleObjectManager::CreateConsoleObject<Body>(1);
}

void Head::IsBodyCheck()
{

}

void Head::NewBodyCreateCheck()
{

}

// ȭ��ٱ����� �������� �ϼ���. 
void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}


	if (0 == _kbhit())
	{
		 //SetPos(GetPos() + Dir);
		 //IsBodyCheck();
		 //NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();

	std::list<ConsoleGameObject*>& HeadGroup
		= ConsoleObjectManager::GetGroup(0);

	std::list<ConsoleGameObject*>::iterator Start = HeadGroup.begin();

	ConsoleGameObject* Ptr = *Start;

	int2 NextPos = { 0 , 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		NextPos = Ptr->GetPos();
		NextPos.X -= 1;
		if (true == Head::isBody(NextPos))
		{
			// ��ũ ����
			Head::CreateBody();
		}
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	SetPos(GetPos() + Dir);
	IsBodyCheck();
	NewBodyCreateCheck();

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}



}
