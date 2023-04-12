// HomeWork0407.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include "Player.h"
#include "Bomb.h"
#include "ConsoleObjectManager.h"
#include "GameEnum.h"
#include <conio.h>

int main()
{
	// 메모리 누수 검사 : 게임 검사엔진
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 20, 10 };
	// 메모리를 Y만큼 늘리고 X만큼 늘림
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);


	// 업캐스팅
	// 인터페이스 통일
	// 이 프레임워크 상의 모든 존재들은 업데이트와 랜더라는 인터페이스를 
	// ConsoleGameObject* NewPlayer = new Player();

	// 0번 그룹에 속한다
	// CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
	// 1번 그룹속한다.

	// ObjectOrder::Player = 1 <= enum클래스에 명시되어 있음
	// AllOject[1]에 Group을 만들고 메모리를 늘려서 NewObject를 할당받아 리턴함
	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);

	// CreateConsoleObject<Monster>(2);

	// 초기값은 true
	while (Player::IsGameUpdate)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		// 맵을 초기화하고 업데이트된 객체를 화면에 찍음
		ConsoleObjectManager::ConsoleAllObjectRender();
		// 살아있는 객체만 지운다
		// why? => 죽은 폭탄을 해제
		ConsoleObjectManager::ConsoleAllObjectRelease();
		Sleep(200);
	}

	// Object가 해제가 안된 것만 삭제
	ConsoleObjectManager::ConsoleAllObjectDelete();
}

