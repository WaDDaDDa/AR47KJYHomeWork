#include "Player.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>

Player Player::MainPlayer;

Player::Player()
{
	CH = 0;
}

Position Player::GetPos() const
{
	return Pos;
}

void Player::SetPos(const Position& _Value)
{
	Pos = _Value;
}

void Player::InputKey()
{
	if (0 == _kbhit())
	{

		Sleep(InterFrame);

		return;
	}

	Player::MainPlayer.CH = _getch();
}

void Player::Move(ConsoleGameScreen& _Screen, Block& _Block)
{
	Position NextPos = { 0, 0 };
	switch (Player::MainPlayer.CH)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == (_Screen.IsScreenOver(NextPos) || _Block.IsBlockOver(NextPos)))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == (_Screen.IsScreenOver(NextPos) || _Block.IsBlockOver(NextPos)))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == (_Screen.IsScreenOver(NextPos) || _Block.IsBlockOver(NextPos)))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == (_Screen.IsScreenOver(NextPos) || _Block.IsBlockOver(NextPos)))
		{
			Pos.Y += 1;
		}
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}

