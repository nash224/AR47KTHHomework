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

void ConsoleGameObject::Update() {}