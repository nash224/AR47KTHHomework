#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

// ĳ���͸� ������ �ϰڴ�.
void ConsoleGameObject::Render() 
{
	if (false == IsUpdate())
	{
		return;
	}
	// ��ȯ Ÿ���� ���� ��ũ�� ��ü�̰�, ��ǥ�� ���� ��ġ�� ��¡ �������� �Ű������� �޾� 
	// ���� ��ǥ�� RenderChar�� �����Ѵ�.
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, RenderChar);

}