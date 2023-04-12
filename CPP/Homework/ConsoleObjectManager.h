#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include <GameEngineConsole/ConsoleGameObject.h>

// 설명 :
class ConsoleObjectManager
{

	// 몬스터 그룹이 있다.
	// 플레이어 그룹이 있다.
	// 폭탄 그룹이 있다.

public:
	template<typename ObjectType>
	// Player(1)을 넘겨주게 되면
	static ObjectType* CreateConsoleObject(int _Order)
	{
		// 완전히 새로운 배열이 1개더 만들어지는 거죠
		// GameEngineArray<ConsoleGameObject*> Group = AllObject[_Order];

		// 0       ==   0
		// AllObject에 들어있는 메모리 수와 매개변수 enum을 비교해서 AllObject의 메모리를 늘림
		if (_Order >= AllObject.Count())
		{
			AllObject.ReSize(_Order + 1);
		}

		// Array의 GameObject 자료형의 Group배열에 AllObject[i]의 정보를 넣음
		GameEngineArray<ConsoleGameObject*>& Group = AllObject[_Order];
		// 의도한 객체 생성
		ObjectType* NewObject = new ObjectType();
		// Player* NewObject = new Player();
		Group.ReSize(Group.Count() + 1);
		Group[Group.Count() - 1] = NewObject;

		return NewObject;
	}

	// 리턴의 자료형을 ObjectType으로 정할 수 있고,
	// 인자 타입을 EnumType으로도 정할 수 있어.
	template<typename ObjectType, typename EnumType>
	// 인자형 : ObjectOrder이넘 클래스
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		// ObjectType 자료형의 CreateConsoleObject함수를 반환
		return CreateConsoleObject<ObjectType>((int)_Order);
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectRelease();
	static void ConsoleAllObjectDelete();

	template<typename EnumType>
	static GameEngineArray<ConsoleGameObject*>& GetGroup(EnumType _Order)
	{
		return AllObject[(int)_Order];
	}

	static GameEngineArray<ConsoleGameObject*>& GetGroup(int _Order)
	{
		return AllObject[_Order];
	}

private:
	// constrcuter destructer
	ConsoleObjectManager();
	~ConsoleObjectManager();

	// delete Function
	ConsoleObjectManager(const ConsoleObjectManager& _Other) = delete;
	ConsoleObjectManager(ConsoleObjectManager&& _Other) noexcept = delete;
	ConsoleObjectManager& operator=(const ConsoleObjectManager& _Other) = delete;
	ConsoleObjectManager& operator=(ConsoleObjectManager&& _Other) noexcept = delete;

	static GameEngineArray<GameEngineArray<ConsoleGameObject*>> AllObject;
};

