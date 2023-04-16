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
		= ConsoleObjectManager::GetGroup(SnakeEnum::Body); // �ٵ� �׷��� �ް�

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
		
		if (GetPos() == CurBodyPos && CurBody->GetDataValue() == true)   //������ ����� true�� �ٵ� ������ ��Ȳ.
		{
			CurBody->Death();      // ���̻����� �ٵ�� death
		}
		else if (GetPos() == CurBodyPos && CurBody->GetDataValue() == false) // false�� ���̰� �ƴ�.
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
