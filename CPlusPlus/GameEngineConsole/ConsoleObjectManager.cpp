#include "ConsoleObjectManager.h"
#include <GameEngineConsole/ConsoleGameScreen.h>

std::vector < std::list <ConsoleGameObject* >> ConsoleObjectManager::AllObject;


ConsoleObjectManager::ConsoleObjectManager()
{
}

ConsoleObjectManager::~ConsoleObjectManager()
{
}

void ConsoleObjectManager::ConsoleAllObjectUpdate()
{
	// std::vector
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		// std::list
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for (; Start != End; ++Start)
		{
			ConsoleGameObject* Object = *Start;

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

	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];
		for (ConsoleGameObject* Object : Group)
		{
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
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		// std::list
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for (; Start != End; ++Start)
		{
			ConsoleGameObject* Object = *Start;

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
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		// std::list
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		// ���ͷ����ͷ� ���������� ���ο��� ������ �����ϱ� ������
		// ���� ���� üũ�� �Ҷ� ���ͷ����ͷ� ��ȸ�� �մϴ�.
		for (; Start != End; )
		{
			ConsoleGameObject* Object = *Start;
			// ���⼭ ������ ���̴ϴ�.
			if (nullptr == Object || false == Object->IsDeath())
			{
				// ���� �ȵǸ� �׷����� 
				// �̷������� ������ �ذ��ϱ� ���ؼ� ���⼭ ++�� �ؾ� �Ѵ�.
				++Start;
				continue;
			}

			// ������ �Ǹ� 
			// �̷������ 
			Start = Group.erase(Start);
			delete Object;
			Object = nullptr;
		}

	}
}
