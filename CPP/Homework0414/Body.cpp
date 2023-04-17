#include <GameEngineConsole/ConsoleObjectManager.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "Body.h"

int Body::BodyCount = 0;
Body::Body() 
{
	BodyCount++;
	RenderChar = '#'; 

	NewBodyCreate();

	if (2 > BodyCount)
	{
		return;
	}
	
	LinktoPrevBody();
}

Body::~Body() 
{
}

void Body::NewBodyCreate()
{
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	int ScreenElementCount = ScreenSize.Y * ScreenSize.X;

	ConsoleGameScreen::GetMainScreen().ArrDataClear();
	ConsoleGameScreen::GetMainScreen().SetArrData();
	Parts::SetUnitNumberArray(ScreenElementCount);
	Parts::PutNonUnitNumber();
	this->SetPos(Parts::RandomUnitPos());
	Parts::ClearUnitNumberArray();
}

void Body::Update()
{
	if (true == this->GetisFollow())
	{
		RenderChar = 'i';
		SetBeforePos(Pos);
		ConsoleGameObject* PrevPtr = this->GetPrev();
		int2 BodyNextPos = PrevPtr->GetPos();
		this->SetPos(PrevPtr->GetBeforePos());

	}
}


void Body::LinktoPrevBody()
{

	std::list<ConsoleGameObject*>& BodyGroup =
		ConsoleObjectManager::GetGroup(1);

	std::list<ConsoleGameObject*>::iterator BodyStart = BodyGroup.begin();

	if (nullptr == *BodyStart)
	{
		return;
	}

	for (size_t i = 0; i < BodyCount - 2; i++)
	{
		BodyStart++;
	}

	ConsoleGameObject* BodyEndPrevPtr = *BodyStart;

	this->LinktoPrev(BodyEndPrevPtr);

	BodyEndPrevPtr->SetisFollow(true);
}