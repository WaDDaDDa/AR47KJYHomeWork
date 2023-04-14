#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "Bomb.h"
#include "GameEnum.h"
#include "Item.h"

bool Player::IsGameUpdate = true;

Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

// �����̵���ġ�� ��ź�̸� Ʈ��.
bool Player::IsBomb(int2 _NextPos)
{
	std::list<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);

	// Ranged for ��� �����̿���

	// ������������. ���ο��� ������ ������ �ٲ�� �ൿ�� �ϸ� �ȵǿ�.
	// push_back
	// push_front
	// erase
	for (ConsoleGameObject* Ptr : BombGroup)
	{
		// �������� �ֽ��ϴ�.
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BombPos = Ptr->GetPos();
		if (_NextPos == BombPos)
		{
			return true;
		}
	}

	return false;
}

void Player::GetItem()
{
	std::list<ConsoleGameObject*>& ItemGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Item); // �����۱׷��� �ް�

	for (ConsoleGameObject* Ptr : ItemGroup)
	{
		// �������� �ֽ��ϴ�.
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 ItemPos = Ptr->GetPos(); 
		if (Pos == ItemPos)   // ������ġ�� ������ �׷��̸�
		{
			BombPower++;     // �÷��̾��� bombpower �ø���
			Ptr->Death();    // ������ ���̰�    ������ ũ������Ʈ
			ConsoleObjectManager::CreateConsoleObject<Item>(ObjectOrder::Item); 
			
			return ;
		}
	}

	return ;
}

// ȭ��ٱ����� �������� �ϼ���. 
void Player::Update()
{
	GetItem();

	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();

	int2 NextPos = Pos;

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos.X -= 1;
		if (true == IsBomb(NextPos)) // ������ġ�� ��ź�̸� ����.
		{
			return;
		}
		else if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}

		break;
	case 'd':
	case 'D':
		NextPos.X += 1;

		if (true == IsBomb(NextPos)) // ������ġ�� ��ź�̸� ����.
		{
			return;
		}

		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos.Y -= 1;

		if (true == IsBomb(NextPos)) // ������ġ�� ��ź�̸� ����.
		{
			return;
		}

		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos.Y += 1;

		if (true == IsBomb(NextPos)) // ������ġ�� ��ź�̸� ����.
		{
			return;
		}

		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
	{
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(Player::BombPower);
		NewBomb->SetPos(GetPos());
		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	default:
		break;
	}
}
