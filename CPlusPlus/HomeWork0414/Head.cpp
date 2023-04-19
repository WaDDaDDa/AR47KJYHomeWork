#include "Head.h"
#include "Body.h"
#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "SnakeEnum.h"
#include <iostream>


bool Head::IsPlay = true;

Head::Head()
{

	RenderChar = L'��';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BodyGroup
		= ConsoleObjectManager::GetGroup(SnakeEnum::Body);

	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		// �������� �ֽ��ϴ�.
		if (nullptr == BodyPtr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();
		if (GetPos() == BodyPos)
		{
			Parts* BodyPart = dynamic_cast<Parts*>(BodyPtr);

			if (BodyPart->GetImFood() == false)  // �÷��̾ ����� ������
			{
				IsPlay = false;   // ����
				return;
			}

			if (nullptr == BodyPart)
			{
				MsgBoxAssert("�ٵ�׷� �ʿ� �ٵ� �ƴ� ��ü�� ����־����ϴ�.");
				return;
			}

			Parts* Last = GetLast();

			//int2 PrevPos = GetPrevPos();
			//BodyPart->SetPos(PrevPos);
			// ??BodyPart
			Last->SetNext(BodyPart);
			BodyPart->ImNotFood();
			ConsoleObjectManager::CreateConsoleObject<Body>(SnakeEnum::Body);
			return;
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
		NextMove();
		return;
	}

	char Ch = _getch();

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		ChangeRenderChar(L'��');
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		ChangeRenderChar(L'��');
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		ChangeRenderChar(L'��');
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		ChangeRenderChar(L'��');
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
	NextMove();

}
