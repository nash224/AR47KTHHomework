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

		/*ConsoleGameScreen::GetMainScreen().SetArrData(Ptr);*/

		if (Ptr->GetPos() == _NextPos)
		{
			return true;
		}

	}


	return false;
}

void Head::HeadtoBodyLink(const ConsoleGameObject* _Body)
{

}

void Head::CreateBody()
{
	ConsoleObjectManager::CreateConsoleObject<Body>(1);
}

// 충돌확인
void Head::IsBodyCheck()
{
}

//
void Head::NewBodyCreateCheck()
{
	//NextPos = Ptr->GetPos();
	//NextPos.X -= 1;
	//if (true == Head::isBody(NextPos))
	//{
	//	// 링크 로직
	//	Head::CreateBody();
	//}

}

// 화면바깥으로 못나가게 하세요. 
void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}


	if (0 == _kbhit())
	{
		 //SetPos(GetPos() + Dir);
		 IsBodyCheck();
		 NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();

	//std::list<ConsoleGameObject*>& HeadGroup
	//	= ConsoleObjectManager::GetGroup(0);

	//std::list<ConsoleGameObject*>::iterator Start = HeadGroup.begin();

	//ConsoleGameObject* Ptr = *Start;

	//ConsoleGameScreen::GetMainScreen().SetArrData(Ptr);

	int2 NextPos = { 0 , 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
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
