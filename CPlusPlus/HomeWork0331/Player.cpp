#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

Player::Player()
{
	RenderChar = '*';
}
// 화면바깥으로 못나가게 하세요. 
void Player::Input()
{
	if (0 == _kbhit())
	{
		Sleep(InterFrame);
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
	{
		ShotUpdate();
		break;
	}
	default:
		break;
	}

	Sleep(InterFrame);
}

void Player::ShotUpdate()
{   // 플레이어가 가진 Bullet* BulletPtr; 을 통해 해당 선언이 가능함.
	Bullet& NewBullet = BulletPtr[BulletCount]; // 값을 보면서 진행하기 위한 NewBullet을 선언
	// 레퍼런스 선언이기에 NewBullet == BulletPtr 이다.
	NewBullet.SetPos(Pos);
	NewBullet.On();

	++BulletCount;
	if (BulletCount >= Bullet::ArrBulletCount)
	{
		BulletCount = 0;
	}
}
