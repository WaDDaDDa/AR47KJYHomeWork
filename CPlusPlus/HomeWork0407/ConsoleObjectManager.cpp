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

			if (nullptr == Object)  // null체크
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
	// Leak 제거 
	for (size_t GroupIndex = 0; GroupIndex < AllObject.Count(); GroupIndex++)
	{
		for (size_t ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Count(); ObjectIndex++)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object)  // null체크
			{
				continue;
			}

			delete Object;
			Object = nullptr;
		}
	}
}
