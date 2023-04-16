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

// Death가 true인 값인 오브젝트들의 데이터를 delete해주는 함수.
// 여기서 배열을 했을때의 문제점.
// 중간에 데이터를 delete로 삭제하게 된다고 하더라도 그삭제된 공간자체가 nullptr을 가르키는
// 형태로 남아있는 것 이기에 우리가 진정원하는 방식의 삭제는 아니라고 할수있다.
void ConsoleObjectManager::ConsoleAllObjectRelease()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		// std::list
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		// 이터레이터로 돌렸을때는 내부에서 삭제가 용이하기 때문에
		// 보통 삭제 체크를 할때 이터레이터로 순회를 합니다.
		for (; Start != End; )
		{
			ConsoleGameObject* Object = *Start;
			// 여기서 오류가 날겁니다.
			if (nullptr == Object || false == Object->IsDeath())
			{
				// 이해 안되면 그려보고 
				// 이레이즈의 오류를 해결하기 위해서 여기서 ++을 해야 한다.
				++Start;
				continue;
			}

			// 삭제가 되면 
			// 이레이즈는 
			Start = Group.erase(Start);
			delete Object;
			Object = nullptr;
		}

	}
}
