#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "GameEnum.h"
#include "Head.h"
#include "Body.h"

bool Head::IsPlay = true;
bool Head::Wintrigger = false;

Head::Head() 
{
	RenderChar = L'●';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head() 
{
}

bool Head::isBody(const int2 _NextPos)
{
	std::list<ConsoleGameObject*>& BodyGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	std::list<ConsoleGameObject*>::iterator Start = BodyGroup.begin();
	std::list<ConsoleGameObject*>::iterator End = BodyGroup.end();
	
	for (; Start != End; Start++)
	{
		if (nullptr == *Start)
		{
			MsgBoxAssert("Body 그룹이 nullptr을 참조하려고 했습니다. -> Head::isBody()")
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
	ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);
}

// 충돌확인
void Head::IsBodyCheck()
{
	if (3 >= Parts::GetPartsCount())
	{
		return;
	}

	std::list<ConsoleGameObject*>& BodyGroup =
		ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	std::list<ConsoleGameObject*>::iterator BodyStart = BodyGroup.begin();

	for (size_t i = 0; i < Parts::GetPartsCount() - 3 ; i++)
	{
		ConsoleGameObject* BodyPtr = *BodyStart;

		if (nullptr == BodyPtr)
		{
			MsgBoxAssert("Body 그룹이 nullptr을 참조하려고 했습니다. -> Head::IsBodyCheck()");
			return;
		}

		Parts* BodyPartsPtr = dynamic_cast<Parts*>(BodyPtr);

		if (Pos == BodyPtr->GetPos())
		{
			IsPlay = false;
		}

		BodyStart++;
	}
}

void Head::NewBodyCreateCheck()
{
	Parts* LastBodyParts = Body::NotFollowBody();

	if (true == Head::isBody(Pos))
	{
		if (false == this->FirstEatBody)
		{
			Parts::LinktoNext(LastBodyParts);
			this->FirstEatBody = true;
		}

		if (false == IsPlay)
		{
			return;
		}

		if (2 == Parts::GetPartsCount())
		{
			Head::CreateBody();
		}

		Parts* LastFollowBodyParts = Body::GetLastFollowBody();

		if (Pos == LastFollowBodyParts->GetPos())
		{
			return;
		}

		Head::CreateBody();
	}
}

void Head::Update()
{
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	int ScreenElement = ScreenSize.X * ScreenSize.Y;

	if (ScreenElement == Parts::GetPartsCount())
	{
		Wintrigger = true;
		return;
	}

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}

	if (0 == _kbhit())
	{
		 SetPos(GetPos() + Dir);
		 IsBodyCheck();
		 NewBodyCreateCheck();

		 if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
		 {
			 IsPlay = false;
		 }

		 return;
	}

	char Ch = _getch();

	int2 NextPos = { 0 , 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		if (Dir != int2::Right)
		{
			Dir = int2::Left;
		}
		break;
	case 'd':
	case 'D':
		if (Dir != int2::Left)
		{
			Dir = int2::Right;
		}
		break;
	case 'w':
	case 'W':
		if (Dir != int2::Down)
		{
			Dir = int2::Up;
		}
		break;
	case 's':
	case 'S':
		if (Dir != int2::Up)
		{
			Dir = int2::Down;
		}
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
