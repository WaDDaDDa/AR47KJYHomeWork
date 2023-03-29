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

void Player::CreateBomb(Bomb& _Bomb)  // 폭탄 생성 함수로 만들려던거.
{
	switch (CH)
	{
	case 'k':
	case 'K':  //누를 때 마다 새로운 폭탄개체를 만들 방법
		Bomb::FirstBomb.SetPos(GetPos());
		break;
	default:
		break;
	}
}

bool Player::Fire()  // 폭탄 생성 함수로 만들려던거.
{
	if (CH == 'f' || CH == 'F')
	{
		return true;
	}
	else
	{
		return false;
	}

}