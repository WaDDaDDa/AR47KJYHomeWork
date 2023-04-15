#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>

Body::Body()
{
	RenderChar = '@';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
	SetPos({ X, Y });
	//SetNextPos();
}

Body::~Body()
{
}

void Body::Update()
{
	ConsoleGameObject::Update();

	std::list<ConsoleGameObject*>&HeadGroup
		= ConsoleObjectManager::GetGroup(SnakeEnum::Head);

	for (ConsoleGameObject* Ptr : HeadGroup)
	{
		// �������� �ֽ��ϴ�.
		if (nullptr == Ptr)
		{
			continue;
		}
		int2 HeadPos = Ptr->GetPos();
		int2 HeadPrevPos = Ptr->GetPrevPos();

		if (true==(NextPos != HeadPos))
		{
			NextPos = HeadPrevPos;
		}

		Pos = NextPos;
		NextPos = HeadPos;

	}
	
	

	// �ٵ�� next�� ������ּҸ� �˰��־��6�ϰ�
	// ��尡 �����̸� ����� prevpos�� ��ġ�� �Űܾ��Ѵ�.
	// ���� prevpos�� ���� �ٵ��� ��ġ�� �˰��־���ϰ�
	// 1. ���� �ٵ� �ִ�.  ���� �ٵ���������ġ�� prev������ �������ִ�.
	// 2. �ٵ�� �����������ġ�� next������ �������ִ�.
	// 3. ��尡 �����̸� �ٵ��ִ�next������ �ٵ��� ������ġ�� �ٲٰ� bodypos = bodynextpos
	// 4. �ٵ��� next������ ��������� ��ġ�� �ִ´�.   bodynextpos = headpos
	// 5. �׷��� ���� �ٵ��� ��ġ�� �� �ʿ䰡 ����.
	// 6. �ܹ��� ����Ʈ.

	// �׷��� �ٵ�� ����� �ּҸ� �˰��־���ϸ� ������������ ���� nextpos�� �ʿ��ϴ�.

}

