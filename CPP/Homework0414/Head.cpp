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
	RenderChar = '$';
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
	std::list<ConsoleGameObject*>& BodyGroup =
		ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (nullptr == BodyPtr)
		{
			MsgBoxAssert("Body 그룹이 nullptr을 참조하려고 했습니다. -> Head::IsBodyCheck")
			return;
		}

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

	if (nullptr == LastBodyPtr)
	{
		return;
	}

	if (true == LastBodyPtr->GetisFollow())
	{
		return;
	}

	Parts* LastBodyParts = dynamic_cast<Parts*>(LastBodyPtr);

	if (true == Head::isBody(Pos))
	{
		if (false == FirstEatBody)
		{
			Parts::LinktoNext(LastBodyParts);
		}

		FirstEatBody = true;

		if (true == LastBodyParts->GetisFollow())
		{
			return;
		}
		Head::CreateBody();
	}
}

void Head::Update()
{
	//int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	//int ScreenElement = ScreenSize.X * ScreenSize.Y;

	//if (ScreenElement == Parts::GetPartsCount())
	//{
	//	Wintrigger = true;
	//}

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
