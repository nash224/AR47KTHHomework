#include "ConsoleObjectManager.h"
#include <GameEngineConsole/ConsoleGameScreen.h>

// �̷��� �迭�� �־�
GameEngineArray<GameEngineArray<ConsoleGameObject*>> ConsoleObjectManager::AllObject;


ConsoleObjectManager::ConsoleObjectManager() 
{
}

ConsoleObjectManager::~ConsoleObjectManager() 
{
}

void ConsoleObjectManager::ConsoleAllObjectUpdate() 
{
	// AllObject�� �׷��
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		// Group������ �迭 ��
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			// Object�� AllObject�� ��Ҹ� ��������
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			// Object�� ���ų� �����ϰ� ���� ������ �ǳʶ�
			if (nullptr == Object || false == Object->IsUpdate())
			{
				// �ǳʶٴ� ���� : ������ϰ� ������ ������ �ʿ䰡 ���� ������ : �ٺ����� ����
				continue;
			}

			// ���� Object�� ��Ÿ��
			Object->Update();
		}

	}


}

// ���� �����ϱ�?
void ConsoleObjectManager::ConsoleAllObjectRender()
{
	// �ѹ� �� �ʱ�ȭ��
	ConsoleGameScreen::GetMainScreen().ScreenClear();

	// AllObject ���� ���
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		// �׷� ���� ���
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			// ��ü ���� ��ƿ�
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			// Object ���°� x, ������ϴ°� x
			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}

			// ����
			Object->Render();
		}

	}

	// ȭ�鿡 ����
	ConsoleGameScreen::GetMainScreen().ScreenPrint();

}

// ���������� �ұ�?
void ConsoleObjectManager::ConsoleAllObjectRelease()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject*& Object = AllObject[GroupIndex][ObjectIndex];

			// ���� Object�� 0�̰ų� ���������
			if (nullptr == Object || false == Object->IsDeath())
			{// �ѱ�
				continue;
			}

			// => Object�� ���°� �߿��� Object�� �׾�����
			delete Object;
			Object = nullptr;
		}

	}
}

// ���ϴ� �ɱ�
void ConsoleObjectManager::ConsoleAllObjectDelete()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			// Object�� ������ �ȵȰ͸�
			if (nullptr == Object)
			{
				continue;
			}

			// ����
			delete Object;
			Object = nullptr;
		}
	}
}