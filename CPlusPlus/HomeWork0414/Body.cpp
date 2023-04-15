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


	for (ConsoleGameObject* Ptr : HeadGroup) //헤드 그룹을 순회하면서 
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 HeadPos = HeadGroup.back()->GetPos();
		int2 HeadPrevPos = HeadGroup.back()->GetPrevPos();

		//if (true == (NextPos != HeadPos))   // 다음위치가 헤드위치가 아니라면 (처음 바디가 생길때)
		//{
		//	NextPos = HeadPrevPos;          // 다음 위치에 
		//}

		Pos = HeadPrevPos;
		NextPos = HeadPos;

	}
	SetPrevPos();
	
	for (ConsoleGameObject* Ptr : BodyGroup)  // 바디그룹 순회하면서
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BodyPos = BodyGroup.back()->GetPos();    // 바디그룹 제일 뒤에꺼의 포스를 bodypos로 받고
		int2 BodyPrevPos = BodyGroup.back()->GetPrevPos(); // 제일뒤에꺼의 PrevPos를 BodyPrevPos로 받는다.

		//if (true == (NextPos != HeadPos))   // 다음위치가 헤드위치가 아니라면 (처음 바디가 생길때)
		//{
		//	NextPos = HeadPrevPos;          // 다음 위치에 
		//}

		Pos = BodyPrevPos;            // 현재 Body의 Pos에 마지막 Body의 PrevPos를 넣는다.
		NextPos = BodyPos;

	}
	
	
	

	// 바디는 next로 헤드의주소를 알고있어야6하고
	// 헤드가 움직이면 헤드의 prevpos로 위치를 옮겨야한다.
	// 헤드는 prevpos로 이전 바디의 위치를 알고있어야하고
	// 1. 헤드와 바디가 있다.  헤드는 바디의현재위치를 prev포스로 가지고있다.
	// 2. 바디는 헤드의현재위치를 next포스로 가지고있다.
	// 3. 헤드가 움직이면 바디에있던next포스를 바디의 현재위치로 바꾸고 bodypos = bodynextpos
	// 4. 바디의 next포스에 현재헤드의 위치를 넣는다.   bodynextpos = headpos
	// 5. 그러면 헤드는 바디의 위치를 알 필요가 없다.
	// 6. 단방향 리스트.

	// 그러면 바디는 헤드의 주소를 알고있어야하며 다음움직임을 위한 nextpos가 필요하다.

}

