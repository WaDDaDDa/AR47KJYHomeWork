#include "ShootingGame.h"

#include <iostream>

// ���� ����� ""
#include "Player.h"
#include "Bullet.h"
#include "ConsoleGameScreen.h"

void ShootingGame::GameProgress()
{
	// �Ѿ��� ������ ������ ���弼��.

	Player NewPlayer = Player();

	// Bullet ArrBullet[10] = { Bullet (), Bullet (), Bullet (), Bullet (), Bullet (), Bullet (),};

	NewPlayer.SetBulletArr(Bullet::GetArrBullet());
	// Bullet* BulletPtr = ArrBullet;
	// �̰� �Ǵ°ž�? �̷������� ����ٸ� ���� int�� �����ض� 
	//int NewInt[10];
	//int* NewIntPtr = NewInt;

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// ĳ���� ��ġ�� ���ڸ� �ϳ� ����.
		NewPlayer.Render();
		Bullet::AllRender();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
	}
}