// Homework0407.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include "Player.h"
#include "Bomb.h"
#include <conio.h>

// 배열에 ConsoleGameObject 자료형을 담겠다
GameEngineArray<ConsoleGameObject*> AllObject;

template<typename ObjectType>
// 새로운 오브젝트 생성 후 메모리를 늘림
void CreateConsoleObject()
{
	// 새로운 객체를 소개하고 우리 회사의 인사명부에 추가했습니다.
	// ObjectType의 빈 자료형을 사용하여 나중에 형을 자유자제로 변환할 수 있음
	// ObjectType 포인터형 NewObject에 동적 메모리 하나 생성
	ObjectType* NewObject = new ObjectType();

	// 원래있던 배열에 자리 하나를 마련해줄게 => ([2] -> [3])
	// 인자 : GameEngineArray형으로 만든 동적할당 받은 배열의 수에 하나를 더한다.
	AllObject.ReSize(AllObject.Count() + 1);

	// 니 자리는 방금 만든 2번방으로 가면 되 
	// 지금은 AllObject[3]이니까 AllObject[2]에 넣어라 
	AllObject[AllObject.Count() - 1] = (ConsoleGameObject*)NewObject;

}

int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 20 , 10 };

	// 부모 포인트형을 가진(ConsoleGameObject에서 생성하지않은) 
	// 자식 클래스를 참조할 수 있도록 함
	// NewPlayer 동적할당받은 객체 
	// 동적할당한 이유: 메모리를 조금이라도 줄일려고
	// 업캐스팅한 이유: 공통적인 부분을 간단하게 다루기 위해서 
	// => ConsoleGameObject에서 전부 관리하기 위해서 = 인터페이스 통일
	// 플레이어, 폭탄, 몬스터, 등등등을 전부 통일하기 위해서
	//ConsoleGameObject* NewPlayer = new Player();

	// 템플릿 자료형 Player의 객체를 만들어라
	CreateConsoleObject<Bomb>();
	CreateConsoleObject<Player>();

	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	while (true == Player::IsGameUpdate)
	{
		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 모든 AllObject요소를 실행하라
		for (size_t i = 0; i < AllObject.Count(); i++)
		{
			// 객체가 없을 때는 넘겨라
			if (nullptr == AllObject[i])
			{
				continue;
			}

			AllObject[i]->Update();
			AllObject[i]->Render();
		}

		//if (nullptr != NewPlayer) 
		//{
		//	// ConsoleGameScreen형이지만 Update는 추상상속이기 때문에 
		//	// NewPlayer의 본질인 Update를 가져오게 된다.
		//	// 가져오는 이유는 추상화 테이블에서 가져온다
		//	NewPlayer->Update();
		//	NewPlayer->Render();
		//}

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		Sleep(500);
	}

	for (size_t i = 0; i < AllObject.Count(); i++)
	{
		delete AllObject[i];
		AllObject[i] = nullptr;
	}
}
