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
	std::list<ConsoleGameObject*>::iterator End = BodyGroup.end();
	
	for (; Start != End; Start++)
	{
		if (nullptr == *Start)
		{
			continue;
		}

		ConsoleGameObject* Ptr = *Start;

		if (Ptr->GetPos() == _NextPos)
		{
			return  true;
		}
	}

	return false;
}

void Head::CreateBody()
{
	ConsoleObjectManager::CreateConsoleObject<Body>(1);
}

// 충돌확인
void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BodyGroup =
		ConsoleObjectManager::GetGroup(1);

	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (true == BodyPtr->GetisFollow() && 
			Pos == BodyPtr->GetPos())
		{
			IsPlay = false;
		}
	}
}

//
void Head::NewBodyCreateCheck()
{

	std::list<ConsoleGameObject*>& BodyGroup =
		ConsoleObjectManager::GetGroup(1);

	std::list<ConsoleGameObject*>::iterator BodyStart = BodyGroup.begin();
	std::list<ConsoleGameObject*>::iterator BodyEnd = BodyGroup.end();

	for (size_t i = 0; i < Parts::GetPartsCount() - 2; i++)
	{
		BodyStart++;
	}

	ConsoleGameObject* LastBodyPtr = *BodyStart;

	if (true == LastBodyPtr->GetisFollow())
	{
		return;
	}

	if (true == Head::isBody(Pos))
	{
		if (false == FirstEatBody)
		{
			ConsoleGameObject::LinktoNext(LastBodyPtr);
		}

		FirstEatBody = true;

		Head::CreateBody();
	}
}

void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}
	
	SetBeforePos(Pos);

	if (0 == _kbhit())
	{
		 SetPos(GetPos() + Dir);
		 IsBodyCheck();
		 NewBodyCreateCheck();
		 //CreateBody();
		 return;
	}

	char Ch = _getch();

	int2 NextPos = { 0 , 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		if (Dir == int2::Right)
		{
			return;
		}
		Dir = int2::Left;
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
