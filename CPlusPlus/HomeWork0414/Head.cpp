#include "Head.h"
#include "Body.h"
#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "SnakeEnum.h"
#include "feed.h"

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
	std::list<ConsoleGameObject*>& FeedGroup
		= ConsoleObjectManager::GetGroup(SnakeEnum::feed); // 아이템그룹을 받고

	for (ConsoleGameObject* Ptr : FeedGroup)
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 FeedPos = Ptr->GetPos();
		if (Pos == FeedPos)   // 현재위치가 바디 그룹이면
		{
			
			Ptr->Death();    // 피드 죽이고    피드 와 바디 크리에이트
			ConsoleObjectManager::CreateConsoleObject<Body>(SnakeEnum::Body);
			ConsoleObjectManager::CreateConsoleObject<feed>(SnakeEnum::feed);

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
	SetPrevPos();

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
