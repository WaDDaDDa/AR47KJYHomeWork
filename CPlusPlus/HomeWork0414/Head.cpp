#include "Head.h"
#include "Body.h"
#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "SnakeEnum.h"

bool Head::IsPlay = true;

Head::Head()
{
	RenderChar = '0';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BodyGroup
		= ConsoleObjectManager::GetGroup(SnakeEnum::Body); // 아이템그룹을 받고

	for (ConsoleGameObject* Ptr : BodyGroup)
	{
		// 터질때가 있습니다.
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BodyPos = Ptr->GetPos();
		if (Pos == BodyPos)   // 현재위치가 아이템 그룹이면
		{
			
			Ptr->Death();    // 바디 죽이고    아이템 크리에이트
			ConsoleObjectManager::CreateConsoleObject<Body>(SnakeEnum::Body);

			return;
		}
	}

	return;
}

void Head::NewBodyCreateCheck()
{

}


void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
		return;
	}

	IsBodyCheck();

	if (0 == _kbhit())
	{
		SetPos(GetPos() + Dir);
		
		// NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();


	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	SetPos(GetPos() + Dir);
	// IsBodyCheck();
	// NewBodyCreateCheck();

}
