#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleObjectManager
{
public:
	template<typename ObjectType>
	static ObjectType* CreateConsoleObject(int _Order)  // ������ ���Ҽ��ִ� ���ڸ� ����. 
	{

		if (_Order >= AllObject.Count())
		{
			AllObject.ReSize(_Order + 1);
		}

		// 2�߹迭��  Group[_Order][ObjectType]
		// _Order�� ���ڸ� ���� ������ ���ϱ� ���ؼ� 2�߹迭������ �����ϰ� ���� �ֵ��� �Ѵ�.
		GameEngineArray<ConsoleGameObject*>& Group = AllObject[_Order];
		ObjectType* NewObject = new ObjectType();

		Group.ReSize(Group.Count() + 1);

		Group[Group.Count() - 1] = NewObject;

		return NewObject;

	}

	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)      //int�� ����ȯ �ؼ� �ٽ� ȣ���ϴ°� ��.
	{
		return CreateConsoleObject<ObjectType>((int)_Order);     // int�� order�� �ؾ��� ������ �־.
		// �׳� ó������ EnumType�� �־ ���� �ʳ�?
			// �׷����� Crate�Ҷ� ����_Order���� ���� ���ο��� (int)������ ���ֵ��� ��������.
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

