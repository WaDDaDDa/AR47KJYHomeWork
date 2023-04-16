#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "SnakeEnum.h"

Body::Body()
{
	RenderChar = '!';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Half().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Half().Y - 1);

	SetPos({ X, Y });
}

Body::~Body()
{
}

void Body::Update()
{
	std::list<ConsoleGameObject*>& HeadGroup
		= ConsoleObjectManager::GetGroup(SnakeEnum::Head);

	ConsoleGameObject* SnakeHead = HeadGroup.front();

	bool ImFood = GetDataValue();            // �ٵ� �������� �ƴ���.

	if (false == ImFood && nullptr == Prev)    // �ٵ� ������ �ƴϰ� Prev�� null�� ����Ű�� �ִٸ� (�ٵ� �Ӹ��� ���󰡴�)
	{
		BeforePos = GetPos();                   // ���� ��ġ��  ������ ��ġ.
		int2 CurPos = SnakeHead->GetPos();    // �Ӹ��� ������ġ�� �̵��� �ٵ��� ��ġ
		SetPos(CurPos);                       // �̵��� ��ġ�� �̵�.
	}

	else if (false == ImFood && nullptr != Prev)   // �ٵ� ������ �ƴϰ� Prev�� null �� �ƴ϶�� (�ٵ� �ٵ� ���󰡴�)
	{
		BeforePos = GetPos();                        // ������ġ�� ������ ��ġ.
		SetPos(Prev->GetBeforePos());                // ������ġ�� ������ġ�� �̵�.
	}

	else if (true == ImFood)          // �ٵ� �����̶�� �����̸� �ȵ�.
	{
		return;
	}
}

void Body:: Death()
{
	SetDataValue(false); // ������ ����� ���� true�� food�� �����ϱ�.
	RenderChar = '@';

	if (nullptr != Prev) // Prev�� null�� ����Ű�� ���� �ʴٸ� 
	{
		SetPos(Prev->GetBeforePos());
	}

	Body* NewBody = ConsoleObjectManager::CreateConsoleObject<Body>(SnakeEnum::Body); // Body�� ����
	NewBody->Prev = this; // ������ Body�� �����ּҸ� ������ �ּҷ�
	Next = NewBody;       // �����ּҸ� ������ �ٵ��� �ּҷ� �ѱ�.
	// �ٽ� ������ �ٵ� ����.
	NewBody->CreateBody();
}


void Body::CreateBody()     // create feed
{
	std::vector<int2> Map;
	int2 MapSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	int2 MapPos = { 0,0 };
	Map.reserve(MapSize.X * MapSize.Y);

	for (int y = 0; y < MapSize.Y; y++)
	{
		for (int x = 0; x < MapSize.X; x++)
		{
			MapPos = { x, y };
			char temp = ConsoleGameScreen::GetMainScreen().GetScreenChar(MapPos);
			if (temp == 'a')
			{
				Map.push_back(MapPos);
			}
		}
	}

	if (0 == Map.size())
	{
		system("cls");
		printf_s("%s\n", "You Win");
		exit(0);
	}

	int Index = GameEngineRandom::MainRandom.RandomInt(0, Map.size() - 1);
	this->SetPos(Map[Index]);
}






//
//void Body::Update()
//{
//	ConsoleGameObject::Update();
//
//	std::list<ConsoleGameObject*>& HeadGroup
//		= ConsoleObjectManager::GetGroup(SnakeEnum::Head);
//
//	std::list<ConsoleGameObject*>& BodyGroup
//		= ConsoleObjectManager::GetGroup(SnakeEnum::Body);
//
//
//	for (ConsoleGameObject* Ptr : HeadGroup) //��� �׷��� ��ȸ�ϸ鼭 
//	{
//		if (nullptr == Ptr)
//		{
//			continue;
//		}
//
//		int2 HeadPos = HeadGroup.back()->GetPos();
//		int2 HeadPrevPos = HeadGroup.back()->GetPrevPos();
//
//		//if (true == (NextPos != HeadPos))   // ������ġ�� �����ġ�� �ƴ϶�� (ó�� �ٵ� ���涧)
//		//{
//		//	NextPos = HeadPrevPos;          // ���� ��ġ�� 
//		//}
//
//		Pos = HeadPrevPos;
//		NextPos = HeadPos;
//
//	}
//	SetPrevPos();
//	
//	for (ConsoleGameObject* Ptr : BodyGroup)  // �ٵ�׷� ��ȸ�ϸ鼭
//	{
//		if (nullptr == Ptr)
//		{
//			continue;
//		}
//
//		int2 BodyPos = BodyGroup.back()->GetPos();    // �ٵ�׷� ���� �ڿ����� ������ bodypos�� �ް�
//		int2 BodyPrevPos = BodyGroup.back()->GetPrevPos(); // ���ϵڿ����� PrevPos�� BodyPrevPos�� �޴´�.
//
//		//if (true == (NextPos != HeadPos))   // ������ġ�� �����ġ�� �ƴ϶�� (ó�� �ٵ� ���涧)
//		//{
//		//	NextPos = HeadPrevPos;          // ���� ��ġ�� 
//		//}
//
//		Pos = BodyPrevPos;            // ���� Body�� Pos�� ������ Body�� PrevPos�� �ִ´�.
//		NextPos = BodyPos;
//
//	}
//	
//	
//	
//
//	// �ٵ�� next�� ������ּҸ� �˰��־��6�ϰ�
//	// ��尡 �����̸� ����� prevpos�� ��ġ�� �Űܾ��Ѵ�.
//	// ���� prevpos�� ���� �ٵ��� ��ġ�� �˰��־���ϰ�
//	// 1. ���� �ٵ� �ִ�.  ���� �ٵ���������ġ�� prev������ �������ִ�.
//	// 2. �ٵ�� �����������ġ�� next������ �������ִ�.
//	// 3. ��尡 �����̸� �ٵ��ִ�next������ �ٵ��� ������ġ�� �ٲٰ� bodypos = bodynextpos
//	// 4. �ٵ��� next������ ��������� ��ġ�� �ִ´�.   bodynextpos = headpos
//	// 5. �׷��� ���� �ٵ��� ��ġ�� �� �ʿ䰡 ����.
//	// 6. �ܹ��� ����Ʈ.
//
//	// �׷��� �ٵ�� ����� �ּҸ� �˰��־���ϸ� ������������ ���� nextpos�� �ʿ��ϴ�.
//
//}

