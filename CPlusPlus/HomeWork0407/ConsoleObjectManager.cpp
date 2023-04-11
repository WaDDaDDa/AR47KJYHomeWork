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

// Death가 true인 값인 오브젝트들의 데이터를 delete해주는 함수.
// 여기서 배열을 했을때의 문제점.
// 중간에 데이터를 delete로 삭제하게 된다고 하더라도 그삭제된 공간자체가 nullptr을 가르키는
// 형태로 남아있는 것 이기에 우리가 진정원하는 방식의 삭제는 아니라고 할수있다.
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
