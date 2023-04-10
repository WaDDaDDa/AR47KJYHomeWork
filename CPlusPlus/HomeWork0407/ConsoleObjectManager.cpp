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
	ConsoleGameScreen::GetMainScreen().ScreenClear();

	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object)  // nullüũ
			{
				continue;
			}

			Object->Update();
			Object->Render();
		}
	}

	ConsoleGameScreen::GetMainScreen().ScreenPrint();

	Sleep(200);

}

void ConsoleObjectManager::ConsoleAllObjectdelete()
{
	// Leak ���� 
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object)  // nullüũ
			{
				continue;
			}

			delete Object;
			Object = nullptr;
		}
	}
}
