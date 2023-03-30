#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "ConsoleGameScreen.h"

void ShootingGame::GameProgress()
{
	// 총알이 여러발 나가게 만드세요.

	Player NewPlayer = Player();

	// Bullet ArrBullet[10] = { Bullet (), Bullet (), Bullet (), Bullet (), Bullet (), Bullet (),};

	NewPlayer.SetBulletArr(Bullet::GetArrBullet());
	// Bullet* BulletPtr = ArrBullet;
	// 이게 되는거야? 이런생각이 들었다면 제발 int를 생각해라 
	//int NewInt[10];
	//int* NewIntPtr = NewInt;

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		Bullet::AllRender();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
	}
}