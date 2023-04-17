#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

// 맵에 기호를 나타낸다
void ConsoleGameObject::Render() 
{
	if (false == IsUpdate())
	{
		return;
	}

	// Pos위치에 RenderChar의 기호를 넣는다
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, RenderChar);
}

void ConsoleGameObject::LinktoNext(ConsoleGameObject* _OtherParts)
{
	this->Next = _OtherParts;
	_OtherParts->Prev = this;
}

void ConsoleGameObject::LinktoPrev(ConsoleGameObject* _OtherParts)
{
	this->Prev = _OtherParts;
	_OtherParts->Next = this;
}

void ConsoleGameObject::Update() {}