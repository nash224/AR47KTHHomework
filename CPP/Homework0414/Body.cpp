#include <GameEngineConsole/ConsoleObjectManager.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "GameEnum.h"
#include "Body.h"

int Body::BodyCount = 0;
Body::Body() 
{
	BodyCount++;
	RenderChar = L'★'; 

	NewBodyCreateLocation();

	if (2 > BodyCount)
	{
		return;
	}
	
	LinktoPrevBody();
}

Body::~Body() 
{
}

void Body::Update()
{
	if (true == this->GetisFollow())
	{
		SetDirection();

		RenderChar = GetSign(Dir);

		ConsoleGameObject* PrevPtr = this->GetPrev();
		int2 BodyNextPos = PrevPtr->GetPos();
		Parts* PrevParts = dynamic_cast<Parts*>(PrevPtr);

		this->SetPos(PrevParts->GetBeforePos());
	}
}

Parts* Body::GetLastFollowBody()
{
	std::list<ConsoleGameObject*>& BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);
	
	std::list<ConsoleGameObject*>::iterator Start = BodyGroup.begin();

	for (size_t i = 0; i < BodyCount - 1; i++)
	{
		Start++;
	}

	ConsoleGameObject* LastFollowBody = *Start;
	Parts* LastFollowBodyParts = dynamic_cast<Parts*>(LastFollowBody);

	return LastFollowBodyParts;
}

void Body::NewBodyCreateLocation()
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

void Body::LinktoPrevBody()
{
	std::list<ConsoleGameObject*>& BodyGroup =
		ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	std::list<ConsoleGameObject*>::iterator BodyStart = BodyGroup.begin();

	if (nullptr == *BodyStart)
	{
		MsgBoxAssert("바디 그룹에서 nullptr을 참조했습니다. -> Body::LinkPrevBody()");
		return;
	}

	for (size_t i = 0; i < BodyCount - 2; i++)
	{
		BodyStart++;
	}

	ConsoleGameObject* BodyEndPrevPtr = *BodyStart;
	Parts* LastBodyParts = dynamic_cast<Parts*>(BodyEndPrevPtr);

	this->LinktoPrev(LastBodyParts);

	Parts* PartsEndPrevPtr = dynamic_cast<Parts*>(BodyEndPrevPtr);

	PartsEndPrevPtr->SetisFollow(true);
}

void Body::SetDirection()
{
	Parts* PrevPartsPtr = this->GetPrev();
	if (nullptr == PrevPartsPtr)
	{
		MsgBoxAssert("Body에 링크된 이전 주소가 nullptr입니다. -> Body::GetDirection()");
		return;
	}

	int2 PrevBeforePos = PrevPartsPtr->GetBeforePos();
	if (true == this->GetisFollow())
	{
		this->Dir = PrevBeforePos - this->Pos;
	}
}

wchar_t Body::GetSign(const int2 _Dir)
{
	if (_Dir == int2::Up)
	{
		return L'▲';
	}
	else if (_Dir == int2::Down)
	{
		return L'▼';
	}
	else if (_Dir == int2::Left)
	{
		return L'◀';
	}
	else
	{
		return L'▶';
	}
}