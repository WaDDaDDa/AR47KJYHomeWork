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

	bool ImFood = GetDataValue();            // 바디가 음식인지 아닌지.

	if (false == ImFood && nullptr == Prev)    // 바디가 음식이 아니고 Prev가 null을 가르키고 있다면 (바디가 머리를 따라가는)
	{
		BeforePos = GetPos();                   // 이전 위치는  현재의 위치.
		int2 CurPos = SnakeHead->GetPos();    // 머리의 현재위치는 이동할 바디의 위치
		SetPos(CurPos);                       // 이동할 위치로 이동.
	}

	else if (false == ImFood && nullptr != Prev)   // 바디가 음식이 아니고 Prev가 null 이 아니라면 (바디가 바디를 따라가는)
	{
		BeforePos = GetPos();                        // 이전위치는 현재의 위치.
		SetPos(Prev->GetBeforePos());                // 이전위치의 이전위치로 이동.
	}

	else if (true == ImFood)          // 바디가 음식이라면 움직이면 안됨.
	{
		return;
	}
}

void Body:: Death()
{
	SetDataValue(false); // 데이터 밸류의 값은 true면 food로 생각하기.
	RenderChar = '@';

	if (nullptr != Prev) // Prev가 null을 가르키고 있지 않다면 
	{
		SetPos(Prev->GetBeforePos());
	}

	Body* NewBody = ConsoleObjectManager::CreateConsoleObject<Body>(SnakeEnum::Body); // Body를 생성
	NewBody->Prev = this; // 생성된 Body의 이전주소를 지금의 주소로
	Next = NewBody;       // 다음주소를 생성된 바디의 주소로 넘김.
	// 다시 랜덤한 바디 생성.
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
//	for (ConsoleGameObject* Ptr : HeadGroup) //헤드 그룹을 순회하면서 
//	{
//		if (nullptr == Ptr)
//		{
//			continue;
//		}
//
//		int2 HeadPos = HeadGroup.back()->GetPos();
//		int2 HeadPrevPos = HeadGroup.back()->GetPrevPos();
//
//		//if (true == (NextPos != HeadPos))   // 다음위치가 헤드위치가 아니라면 (처음 바디가 생길때)
//		//{
//		//	NextPos = HeadPrevPos;          // 다음 위치에 
//		//}
//
//		Pos = HeadPrevPos;
//		NextPos = HeadPos;
//
//	}
//	SetPrevPos();
//	
//	for (ConsoleGameObject* Ptr : BodyGroup)  // 바디그룹 순회하면서
//	{
//		if (nullptr == Ptr)
//		{
//			continue;
//		}
//
//		int2 BodyPos = BodyGroup.back()->GetPos();    // 바디그룹 제일 뒤에꺼의 포스를 bodypos로 받고
//		int2 BodyPrevPos = BodyGroup.back()->GetPrevPos(); // 제일뒤에꺼의 PrevPos를 BodyPrevPos로 받는다.
//
//		//if (true == (NextPos != HeadPos))   // 다음위치가 헤드위치가 아니라면 (처음 바디가 생길때)
//		//{
//		//	NextPos = HeadPrevPos;          // 다음 위치에 
//		//}
//
//		Pos = BodyPrevPos;            // 현재 Body의 Pos에 마지막 Body의 PrevPos를 넣는다.
//		NextPos = BodyPos;
//
//	}
//	
//	
//	
//
//	// 바디는 next로 헤드의주소를 알고있어야6하고
//	// 헤드가 움직이면 헤드의 prevpos로 위치를 옮겨야한다.
//	// 헤드는 prevpos로 이전 바디의 위치를 알고있어야하고
//	// 1. 헤드와 바디가 있다.  헤드는 바디의현재위치를 prev포스로 가지고있다.
//	// 2. 바디는 헤드의현재위치를 next포스로 가지고있다.
//	// 3. 헤드가 움직이면 바디에있던next포스를 바디의 현재위치로 바꾸고 bodypos = bodynextpos
//	// 4. 바디의 next포스에 현재헤드의 위치를 넣는다.   bodynextpos = headpos
//	// 5. 그러면 헤드는 바디의 위치를 알 필요가 없다.
//	// 6. 단방향 리스트.
//
//	// 그러면 바디는 헤드의 주소를 알고있어야하며 다음움직임을 위한 nextpos가 필요하다.
//
//}

