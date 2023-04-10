#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleObjectManager
{
public:
	template<typename ObjectType>
	static ObjectType* CreateConsoleObject(int _Order)  // 순서를 정할수있는 인자를 만듦. 
	{

		if (_Order >= AllObject.Count())
		{
			AllObject.ReSize(_Order + 1);
		}

		// 2중배열의  Group[_Order][ObjectType]
		// _Order에 숫자를 통해 순서를 정하기 위해서 2중배열형으로 정의하고 값을 넣도록 한다.
		GameEngineArray<ConsoleGameObject*>& Group = AllObject[_Order];
		ObjectType* NewObject = new ObjectType();

		Group.ReSize(Group.Count() + 1);

		Group[Group.Count() - 1] = NewObject;

		return NewObject;

	}

	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)      //int로 형변환 해서 다시 호출하는것 뿐.
	{
		return CreateConsoleObject<ObjectType>((int)_Order);     // int인 order로 해야할 계산들이 있어서.
		// 그냥 처음부터 EnumType을 넣어도 되지 않나?
			// 그럴려면 Crate할때 받은_Order들을 전부 내부에서 (int)형변을 해주도록 만들어야함.
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectdelete();

private:
    ConsoleObjectManager();
    ~ConsoleObjectManager();

    ConsoleObjectManager& operator=(const ConsoleObjectManager& _Other) = delete;
    ConsoleObjectManager& operator=(const ConsoleObjectManager&& _Other) = delete;
    ConsoleObjectManager(const ConsoleObjectManager& _Other) = delete;
    ConsoleObjectManager(const ConsoleObjectManager&& _Other) = delete;

	static GameEngineArray<GameEngineArray<ConsoleGameObject*>> AllObject;
};

