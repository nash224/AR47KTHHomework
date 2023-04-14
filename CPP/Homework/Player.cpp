#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include "ConsoleObjectManager.h"
#include "Bomb.h"
#include "GameEnum.h"
#include "ConsoleObjectManager.h"

bool Player::IsGameUpdate = true;

// 시작할때 정함
Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

// 숙제 수정
// Player 객체는 ConsoleGameObject에서 업캐스팅 되었음
bool Player::IsBomb(int2 _NextPos)
{
	// 폭탄이 설치되었다면 못통과하게 만들어놓으세요.
	GameEngineArray<ConsoleGameObject*>& BombGroup // BombGroup이라는 변수를 생성
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb); // 참조형 폭탄 그룹을 얻음

	for (size_t i = 0; i < BombGroup.Count(); i++) // 폭탄 그룹 해제된것까지 반복
	{
		ConsoleGameObject* Ptr = BombGroup[i];

		if (nullptr == Ptr) // 해제됐으면 수행안함
		{
			continue;
		}

		if (_NextPos == Ptr->GetPos()) // Player에서 입력받은 위치가 폭탄이랑 겹치면
		{
			return true; // bool값 반환
		}
	}

	return false;
}

// 화면바깥으로 못나가게 하세요. 
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
		// 다음위치가 넘어 갈려거나, 다음위치에 폭탄이 있을때
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
		// 여기 이상황에서 보면
		// ConsoleObjectManager 있고
		// Player 
		// Bomb 포인터형 NewBomb에 = ConsoleObjectManager에서 만든 AllObject Group배열의 NewObject 객체를 넣음
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());
		// 폭탄설치 
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
