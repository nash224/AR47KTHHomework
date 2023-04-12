#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>

// IsGameUpdate�ǵ� ���߱� ������ ��� ����
bool Player::IsGameUpdate = true;


Player::Player()
{
	RenderChar = '*';
}
// ȭ��ٱ����� �������� �ϼ���. 
void Player::Update()
{
	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		// ���ο� ��ġ�� ���� ��ġ�� ��´�.
		NextPos = Pos;
		// NextPos�� �ǵ� ���� ��ġ���� �������� �� ��ġ�� ����
		NextPos.X -= 1;
		// ������ġ�� ���� �ʾҴٸ�
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{// �÷��̾��� ��ǥ�� �������� ��ĭ ������.
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'q':
	case 'Q':
	{
		// ������ �����Ѵ�
		IsGameUpdate = false;
		break;
	}
	case 'f':
	case 'F':
	{
		// �Ѿ˿� ���� ������  �ҷ��´�
		break;
	}
	default:
		break;
	}
}
