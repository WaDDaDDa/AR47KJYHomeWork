#include "ConsoleObjectManager.h"
#include <GameEngineConsole/ConsoleGameScreen.h>

GameEngineArray<GameEngineArray<ConsoleGameObject*>> ConsoleObjectManager::AllObject;


ConsoleObjectManager::ConsoleObjectManager()
{
}

ConsoleObjectManager::~ConsoleObjectManager()
{
}

void ConsoleObjectManager::ConsoleAllObjectUpdate()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}

			Object->Update();
		}

	}


}

void ConsoleObjectManager::ConsoleAllObjectRender()
{
	ConsoleGameScreen::GetMainScreen().ScreenClear();

	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}

			Object->Render();
		}

	}

	ConsoleGameScreen::GetMainScreen().ScreenPrint();

}

void ConsoleObjectManager::ConsoleAllObjectDelete()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object)
			{
				continue;
			}

			delete Object;
			Object = nullptr;
		}
	}
}

// Death�� true�� ���� ������Ʈ���� �����͸� delete���ִ� �Լ�.
// ���⼭ �迭�� �������� ������.
// �߰��� �����͸� delete�� �����ϰ� �ȴٰ� �ϴ��� �׻����� ������ü�� nullptr�� ����Ű��
// ���·� �����ִ� �� �̱⿡ �츮�� �������ϴ� ����� ������ �ƴ϶�� �Ҽ��ִ�.
void ConsoleObjectManager::ConsoleAllObjectRelease()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject*& Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object || false == Object->IsDeath())
			{
				continue;
			}

			delete Object;
			Object = nullptr;
		}

	}
}
