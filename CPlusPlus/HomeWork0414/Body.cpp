#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>

Body::Body()
{
	RenderChar = '@';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
	SetPos({ X, Y });
	BodyCount++;
}

Body::~Body()
{
}

void Body::Update2()
{

}

void Body::Update()
{
	ConsoleGameObject::Update();

	std::list<ConsoleGameObject*>& HeadGroup
		= ConsoleObjectManager::GetGroup(SnakeEnum::Head);

	std::list<ConsoleGameObject*>& BodyGroup
		= ConsoleObjectManager::GetGroup(SnakeEnum::Body);


	for (ConsoleGameObject* Ptr : HeadGroup) //��� �׷��� ��ȸ�ϸ鼭 
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 HeadPos = HeadGroup.back()->GetPos();
		int2 HeadPrevPos = HeadGroup.back()->GetPrevPos();

		//if (true == (NextPos != HeadPos))   // ������ġ�� �����ġ�� �ƴ϶�� (ó�� �ٵ� ���涧)
		//{
		//	NextPos = HeadPrevPos;          // ���� ��ġ�� 
		//}

		Pos = HeadPrevPos;
		NextPos = HeadPos;

	}
	SetPrevPos();
	
	for (ConsoleGameObject* Ptr : BodyGroup)  // �ٵ�׷� ��ȸ�ϸ鼭
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BodyPos = BodyGroup.back()->GetPos();    // �ٵ�׷� ���� �ڿ����� ������ bodypos�� �ް�
		int2 BodyPrevPos = BodyGroup.back()->GetPrevPos(); // ���ϵڿ����� PrevPos�� BodyPrevPos�� �޴´�.

		//if (true == (NextPos != HeadPos))   // ������ġ�� �����ġ�� �ƴ϶�� (ó�� �ٵ� ���涧)
		//{
		//	NextPos = HeadPrevPos;          // ���� ��ġ�� 
		//}

		Pos = BodyPrevPos;            // ���� Body�� Pos�� ������ Body�� PrevPos�� �ִ´�.
		NextPos = BodyPos;

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

