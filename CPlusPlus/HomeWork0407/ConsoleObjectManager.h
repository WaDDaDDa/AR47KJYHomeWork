#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include <GameEngineConsole/ConsoleGameObject.h>

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
		if (_Order >= AllObject.Count())
		{
			AllObject.ReSize(_Order + 1);
		}

		GameEngineArray<ConsoleGameObject*>& Group = AllObject[_Order];
		ObjectType* NewObject = new ObjectType();
		// Player* NewObject = new Player();
		Group.ReSize(Group.Count() + 1);
		Group[Group.Count() - 1] = NewObject;

		return NewObject;
	}

	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		return CreateConsoleObject<ObjectType>((int)_Order);
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectDelete();
	static void ConsoleAllObjectRelease();


	template <typename EnumType>
	static GameEngineArray<ConsoleGameObject*>& GetGroup(EnumType _Order)
	{
		return AllObject[(int)_Order];
	}

	// Enum타입으로 지정한 그룹전체 배열을 받는것.
	// ex) 폭탄이면 AllObject[0] 으로 받는것.
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

