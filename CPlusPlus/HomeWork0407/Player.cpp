#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include "ConsoleObjectManager.h"
#include "Bomb.h"
#include "GameEnum.h"

bool Player::IsGameUpdate = true;

Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

// �����̵���ġ�� ��ź�̸� Ʈ��.
bool Player::IsBomb(int2 _NextPos)
{
	// ��ź�� ��ġ�Ǿ��ٸ� ������ϰ� ������������.
	// ��ź�׷��� �迭�� BombGroup���� �����Ͽ� ���� ����.
	GameEngineArray<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);

	// ���� ���� BombGroup�� �̿��Ͽ� ��ź�׷��� ��ź���� for������ nextpos�� üũ
	// ���� nullüũ�� �ؼ� ��ź�� ������ ������ nullptr�� �Ǵµ� �׷�����
	// continue�� �ٷ� ���� ���� üũ�ϵ���.

	for (size_t i = 0; i < BombGroup.Count(); i++)
	{
		if (nullptr == BombGroup[i])
		{
			continue;
		}

		int2 BombPos = BombGroup[i]->GetPos();

		if (BombPos == _NextPos)
		{
			return true;
		}
	}
	return false;
}

// ȭ��ٱ����� �������� �ϼ���. 
void Player::Update()
{
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
