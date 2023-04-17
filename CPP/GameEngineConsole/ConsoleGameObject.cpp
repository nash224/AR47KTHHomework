#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

// �ʿ� ��ȣ�� ��Ÿ����
void ConsoleGameObject::Render() 
{
	if (false == IsUpdate())
	{
		return;
	}

	// Pos��ġ�� RenderChar�� ��ȣ�� �ִ´�
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