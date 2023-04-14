#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include "ConsoleObjectManager.h"
#include "Bomb.h"
#include "GameEnum.h"
#include "ConsoleObjectManager.h"

bool Player::IsGameUpdate = true;

// �����Ҷ� ����
Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

// ���� ����
// Player ��ü�� ConsoleGameObject���� ��ĳ���� �Ǿ���
bool Player::IsBomb(int2 _NextPos)
{
	// ��ź�� ��ġ�Ǿ��ٸ� ������ϰ� ������������.
	GameEngineArray<ConsoleGameObject*>& BombGroup // BombGroup�̶�� ������ ����
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb); // ������ ��ź �׷��� ����

	for (size_t i = 0; i < BombGroup.Count(); i++) // ��ź �׷� �����Ȱͱ��� �ݺ�
	{
		ConsoleGameObject* Ptr = BombGroup[i];

		if (nullptr == Ptr) // ���������� �������
		{
			continue;
		}

		if (_NextPos == Ptr->GetPos()) // Player���� �Է¹��� ��ġ�� ��ź�̶� ��ġ��
		{
			return true; // bool�� ��ȯ
		}
	}

	return false;
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
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) && 
			false == IsBomb(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) || 
			true == IsBomb(NextPos))
		{
			return;
		}
		Pos.X += 1;
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		// ������ġ�� �Ѿ� �����ų�, ������ġ�� ��ź�� ������
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) && false == IsBomb(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) && false == IsBomb(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
	{
		// ���� �̻�Ȳ���� ����
		// ConsoleObjectManager �ְ�
		// Player 
		// Bomb �������� NewBomb�� = ConsoleObjectManager���� ���� AllObject Group�迭�� NewObject ��ü�� ����
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());
		// ��ź��ġ 
		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	default:
		break;
	}
}
