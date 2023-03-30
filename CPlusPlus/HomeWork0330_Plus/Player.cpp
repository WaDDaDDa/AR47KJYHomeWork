#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

Player::Player()
{

}
// 화면바깥으로 못나가게 하세요. 
void Player::Input()
{
	if (0 == _kbhit())
	{
		// 0.5초간 멈춘다.
		Sleep(InterFrame);
		// 일부러 멈추게 만들겁니다.
		// continue; 반복문 내부에서만 사용가능
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
		BulletPtr[Bullet::FireCount].SetPos(Pos);
		BulletPtr[Bullet::FireCount].FireOn();
		Bullet::FireCount++;
		break;

	case 'k':
	case 'K': //샷건 키.
		BulletPtr[Bullet::FireCount].SetPos(Pos);    // 플레이어 위치기준 총알 발사
		BulletPtr[Bullet::FireCount].FireOn();       // 총알이 발사되었다는 true
		Bullet::FireCount++;                         // 총알 소비 카운트.

		NextPos = Pos;                               // 총알의 다음 위치.
		NextPos.X += 1;                              // 3갈래로 나가게 하기 위해 x배열 값 증가. (오른쪽 총알)
		BulletPtr[Bullet::FireCount].SetPos(NextPos);
		BulletPtr[Bullet::FireCount].FireOn();        // 발사되었음.
		Bullet::FireCount++;                          // 총알 소비 카운트 증가.

		NextPos.X -= 2;                               // 총알의 다음위치. 왼쪽에 배치하기위해 -2.
		BulletPtr[Bullet::FireCount].SetPos(NextPos);
		BulletPtr[Bullet::FireCount].FireOn();
		Bullet::FireCount++;                          // 총알 소비.

		// 문제점 : 총알 갯수를 체크 하지 않기 때문에 총알이 9발인 시점에서 발사하면
		// 12발을 쏘는 일이 발생함.
		// 1. 총알갯수를 발사 구간마다 체크한다. => 총알 갯수 부족하면 오른쪽총알이 먼저 발사된다.
		// 2. 샷건으로 다른 총알종류를 만들어서 그 특수 총알의 갯수를 센다.
		// 3. 일단 총알갯수가 부족하지 않게 설정한다.
	default:
		break;
	}

	Sleep(InterFrame);
}


void Player::Render()
{
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '*');
}