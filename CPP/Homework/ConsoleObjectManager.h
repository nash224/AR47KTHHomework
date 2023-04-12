#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include <GameEngineConsole/ConsoleGameObject.h>

// ���� :
class ConsoleObjectManager
{

	// ���� �׷��� �ִ�.
	// �÷��̾� �׷��� �ִ�.
	// ��ź �׷��� �ִ�.

public:
	template<typename ObjectType>
	// Player(1)�� �Ѱ��ְ� �Ǹ�
	static ObjectType* CreateConsoleObject(int _Order)
	{
		// ������ ���ο� �迭�� 1���� ��������� ����
		// GameEngineArray<ConsoleGameObject*> Group = AllObject[_Order];

		// 0       ==   0
		// AllObject�� ����ִ� �޸� ���� �Ű����� enum�� ���ؼ� AllObject�� �޸𸮸� �ø�
		if (_Order >= AllObject.Count())
		{
			AllObject.ReSize(_Order + 1);
		}

		// Array�� GameObject �ڷ����� Group�迭�� AllObject[i]�� ������ ����
		GameEngineArray<ConsoleGameObject*>& Group = AllObject[_Order];
		// �ǵ��� ��ü ����
		ObjectType* NewObject = new ObjectType();
		// Player* NewObject = new Player();
		Group.ReSize(Group.Count() + 1);
		Group[Group.Count() - 1] = NewObject;

		return NewObject;
	}

	// ������ �ڷ����� ObjectType���� ���� �� �ְ�,
	// ���� Ÿ���� EnumType���ε� ���� �� �־�.
	template<typename ObjectType, typename EnumType>
	// ������ : ObjectOrder�̳� Ŭ����
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		// ObjectType �ڷ����� CreateConsoleObject�Լ��� ��ȯ
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

