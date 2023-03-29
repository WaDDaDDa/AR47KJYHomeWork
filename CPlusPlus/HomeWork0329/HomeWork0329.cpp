
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

		// 만약 키가 눌렸던 상태가 아니라면 출력하지않는다.
		// Player::MainPlayer.CH 가 0 이라면 출력하지 않는다. 라고한다면.
		// 초기에는 없더라도 이동키a가 눌려도 출력하게 된다.
		// 그럼 대응하는 키가 눌렸을 경우만 출력한다면?
		// 폭탄을 설치하고 이동을 하게되면 사라질 것이다.
		// 어떻게할까?
		// 일단 배열 바깥인 -1,-1에 생성되게 만들었음.
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Bomb::FirstBomb.GetPos(), '@');  // 초기 폭탄위치값을 어떻게 해야하나.
		// 폭탄이 없는 상태를 표현할 방법.
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Bullet::FirstBullet.GetPos(), '^');

		ConsoleGameScreen::GetMainScreen().ScreenPrint();           // 화면 출력.

		Player::MainPlayer.CH = 0; // 받은 키 초기화. 받은키가 계속 남아있어서 그 키가 반복되는 현상이 생김

		Player::MainPlayer.InputKey();  // 기다리고 키를 받는것.

		Player::MainPlayer.Move(ConsoleGameScreen::GetMainScreen(), NewBlock0);   // 위에서 받은 키를 통해 이동.

		Bomb::FirstBomb.CreateBomb();

		Bullet::FirstBullet.FireBullet();

		Bullet::FirstBullet.BulletMove();

	}

}
