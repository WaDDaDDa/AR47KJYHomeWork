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
		= ConsoleObjectManager::GetGroup(SnakeEnum::Body); // 바디 그룹을 받고

	std::list<ConsoleGameObject*>::iterator Start = BodyGroup.begin();
	std::list<ConsoleGameObject*>::iterator End = BodyGroup.end();


	for (; Start != End; ++Start)
	{
		if (nullptr == *Start)
		{
			continue;
		}
		ConsoleGameObject* CurBody = *Start;
		int2 CurBodyPos = CurBody->GetPos();
		
		if (GetPos() == CurBodyPos && CurBody->GetDataValue() == true)   //데이터 밸류는 true면 바디가 먹이인 상황.
		{
			CurBody->Death();      // 먹이상태인 바디는 death
		}
		else if (GetPos() == CurBodyPos && CurBody->GetDataValue() == false) // false면 먹이가 아님.
		{
			IsPlay = false;
		}
	}

}


void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
		return;
	}

	

	if (0 == _kbhit())
	{
		SetPos(GetPos() + Dir);
		IsBodyCheck();
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
	IsBodyCheck();
	// NewBodyCreateCheck();

}
