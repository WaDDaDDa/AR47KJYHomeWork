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
		= ConsoleObjectManager::GetGroup(SnakeEnum::Body); // �����۱׷��� �ް�

	for (ConsoleGameObject* Ptr : BodyGroup)
	{
		// �������� �ֽ��ϴ�.
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BodyPos = Ptr->GetPos();
		if (Pos == BodyPos)   // ������ġ�� ������ �׷��̸�
		{
			
			Ptr->Death();    // �ٵ� ���̰�    ������ ũ������Ʈ
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
