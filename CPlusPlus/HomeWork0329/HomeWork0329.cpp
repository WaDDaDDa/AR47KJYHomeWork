
#include "Position.h"
#include "ConsoleGameScreen.h"
#include "Block.h"
#include "Block.h"
#include "Player.h"
#include "Bullet.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>

int main()
{
	Block NewBlock0;          // 새로운 블럭개체를 선언하지 않고 블럭을여러개 만들 방법
	Block NewBlock1;
	Block NewBlock2;

	Position ScreenSize = ConsoleGameScreen::GetScreenSize();

	Player::MainPlayer.SetPos(ScreenSize.Half());
	NewBlock0.SetPos(ScreenSize.Half3());



	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();  // 맵을 a으로 초기화.

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Player::MainPlayer.GetPos(), '*'); // 플레이어 생성

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewBlock0.GetPos(), 'O');  // 장애물 생성

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Bomb::FirstBomb.GetPos(), '@');  // 초기 폭탄위치값을 어떻게 해야하나.
		// 폭탄이 없는 상태를 표현할 방법.
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Bullet::FirstBullet.GetPos(), '^');

		ConsoleGameScreen::GetMainScreen().ScreenPrint();           // 화면 출력.

		Player::MainPlayer.CH = 0; // 받은 키 초기화. 받은키가 계속 남아있어서 그 키가 반복되는 현상이 생김

		Player::MainPlayer.InputKey();  // 기다리고 키를 받는것.

		Player::MainPlayer.Move(ConsoleGameScreen::GetMainScreen(), NewBlock0);   // 위에서 받은 키를 통해 이동.

		Player::MainPlayer.CreateBomb(Bomb::FirstBomb);

		Player::MainPlayer.Fire();

		Bullet::FirstBullet.FireBullet();

		Bullet::FirstBullet.BulletMove();

	}

}
