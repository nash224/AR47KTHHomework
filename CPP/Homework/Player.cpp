#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h> 
#include <GameEngineConsole/ConsoleObjectManager.h> // AllObject
#include "Bomb.h"
#include "GameEnum.h"

bool Player::IsGameUpdate = true;

Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

bool Player::IsBomb(int2 _NextPos)
{
	std::list<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);

	// Ranged for ��� �����̿���

	// ������������. ���ο��� ������ ������ �ٲ�� �ൿ�� �ϸ� �ȵǿ�.
	// push_back
	// push_front
	// erase
	for (ConsoleGameObject* Ptr : BombGroup)
	{
		// �������� �ֽ��ϴ�.
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BombPos = Ptr->GetPos();
		if (_NextPos == BombPos)
		{
			return true;
		}
	}

	return false;
}

bool Player::isItem(const int2 const_NextPos)
{
	std::list<ConsoleGameObject*>& ItemGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Item);

	std::list<ConsoleGameObject*>::iterator Start = ItemGroup.begin();
	std::list<ConsoleGameObject*>::iterator End = ItemGroup.end();

	for (;Start != End; Start++)
	{
		ConsoleGameObject* Ptr = *Start;
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 ItemPos = Ptr->GetPos();
		if (const_NextPos == ItemPos)
		{
			Ptr->Off();
			return true;
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
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) || true == IsBomb(NextPos))
		{
			return;
		}
		Pos.X -= 1;
		if (true == isItem(NextPos))
		{
			BombPower++;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) || true == IsBomb(NextPos))
		{
			return;
		}
		Pos.X += 1;
		if (true == isItem(NextPos))
		{
			BombPower++;
		}
		break;
	case 'w':
	case 'W':
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) || true == IsBomb(NextPos))
		{
			return;
		}
		Pos.Y -= 1;
		if (true == isItem(NextPos))
		{
			BombPower++;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos) || true == IsBomb(NextPos))
		{
			return;
		}
		Pos.Y += 1;
		if (true == isItem(NextPos))
		{
			BombPower++;
		}
		break;
	case 'f':
	case 'F':
	{
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());
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
