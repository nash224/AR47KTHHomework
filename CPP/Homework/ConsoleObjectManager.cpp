#include "ConsoleObjectManager.h"
#include <GameEngineConsole/ConsoleGameScreen.h>

// 이러한 배열이 있어
GameEngineArray<GameEngineArray<ConsoleGameObject*>> ConsoleObjectManager::AllObject;


ConsoleObjectManager::ConsoleObjectManager() 
{
}

ConsoleObjectManager::~ConsoleObjectManager() 
{
}

void ConsoleObjectManager::ConsoleAllObjectUpdate() 
{
	// AllObject의 그룹수
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		// Group에서의 배열 수
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			// Object에 AllObject의 요소를 넣을려고
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			// Object가 없거나 실행하고 있지 않을때 건너뜀
			if (nullptr == Object || false == Object->IsUpdate())
			{
				// 건너뛰는 이유 : 실행안하고 있으면 실행할 필요가 없기 때문에 : 근본적인 이유
				continue;
			}

			// 지금 Object를 나타냄
			Object->Update();
		}

	}


}

// 무슨 역할일까?
void ConsoleObjectManager::ConsoleAllObjectRender()
{
	// 한번 맵 초기화함
	ConsoleGameScreen::GetMainScreen().ScreenClear();

	// AllObject 안의 요소
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		// 그룹 안의 요소
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			// 객체 정보 담아옴
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			// Object 없는거 x, 실행안하는거 x
			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}

			// 랜더
			Object->Render();
		}

	}

	// 화면에 찍음
	ConsoleGameScreen::GetMainScreen().ScreenPrint();

}

// 무슨역할을 할까?
void ConsoleObjectManager::ConsoleAllObjectRelease()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject*& Object = AllObject[GroupIndex][ObjectIndex];

			// 현재 Object가 0이거나 살아있으면
			if (nullptr == Object || false == Object->IsDeath())
			{// 넘김
				continue;
			}

			// => Object가 없는것 중에서 Object가 죽었으면
			delete Object;
			Object = nullptr;
		}

	}
}

// 뭐하는 걸까
void ConsoleObjectManager::ConsoleAllObjectDelete()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			// Object가 해제가 안된것만
			if (nullptr == Object)
			{
				continue;
			}

			// 삭제
			delete Object;
			Object = nullptr;
		}
	}
}