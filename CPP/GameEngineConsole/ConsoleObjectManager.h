#pragma once
#include "ConsoleGameObject.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <vector>
#include <list>

// 설명 :
class ConsoleObjectManager
{

	// 몬스터 그룹이 있다.
	// 플레이어 그룹이 있다.
	// 폭탄 그룹이 있다.

public:
	template<typename ObjectType>
	// (std::vector<std::list<ConsoleGameObject*>) AllObject에 NewObject를 추가하고 $ NewObject를 반환
	static ObjectType* CreateConsoleObject(int _Order)
	{// this
		// GameEngineArray<ConsoleGameObject*> Group = AllObject[_Order];

		// 0       ==   0
		if (_Order >= AllObject.size())
		{
			AllObject.resize(_Order + 1);
		}

		std::list<ConsoleGameObject*>& Group = AllObject[_Order];
		ObjectType* NewObject = new ObjectType();
		// Player* NewObject = new Player();
		// ListNode에 End->prev에 NewObject를 추가함
		Group.push_back(NewObject);
		return NewObject;
	}

	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		return CreateConsoleObject<ObjectType>((int)_Order);
	}


	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectRelease();
	static void ConsoleAllObjectDelete();


	template<typename EnumType>
	static std::list<ConsoleGameObject*>& GetGroup(EnumType _Order)
	{
		return AllObject[(int)_Order];
	}

	static std::list<ConsoleGameObject*>& GetGroup(int _Order)
	{
		return AllObject[_Order];
	}

	static size_t GetObjectCount()
	{
		return ObjectCount;
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

	static std::vector<std::list<ConsoleGameObject*>> AllObject;
	static size_t ObjectCount;
};

