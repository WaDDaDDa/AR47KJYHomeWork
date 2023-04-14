#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include <GameEngineConsole/ConsoleGameObject.h>
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
	static ObjectType* CreateConsoleObject(int _Order)
	{
		// 완전히 새로운 배열이 1개더 만들어지는 거죠
		// GameEngineArray<ConsoleGameObject*> Group = AllObject[_Order];

		// 0       ==   0
		if (_Order >= AllObject.size())
		{
			AllObject.resize(_Order + 1);
		}

		std::list<ConsoleGameObject*>& Group = AllObject[_Order];
		ObjectType* NewObject = new ObjectType();
		// Player* NewObject = new Player();
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
};

