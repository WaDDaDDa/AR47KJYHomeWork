#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::MainPlayer;

void ShootingGame::Loading() //게임시작 전에 준비 되어야 할 요소들.
{
	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알의 포인터를 알게 한다.
	MainPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	MainPlayer.SetPos(ScreenSize.Half());

	// 몬스터의 초기 위치를 설정한다.
	Monster::Loading();

}

void ShootingGame::Collision() // 총알과 몬스터 충돌했을 경우
{

	Bullet* BulletArr = Bullet::GetArrBullet(); //총알의배열주소를 받을수있는 BulletArr 선언
	Monster* MonsterArr = Monster::GetArrMonster();//몬스터의배열주소를 받을수있는 MonsterArr 선언
	
	// 모든 총알과 
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		// 참조로 묶었다. CurBullet은 BulletArr인것.
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate()) // 업데이트 밸류가 fasle면 건너뛴다.
		{
			continue;
		}
		// 모든 몬스터는
		for (size_t MonsterIndex = 0; MonsterIndex < Monster::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = MonsterArr[MonsterIndex];

			if (false == CurMonster.IsUpdate()) //업데이트 밸류가 fasle면 건너뛴다.
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())//몬스터와 총알의 위치가 같으면.
			{
				CurMonster.Off();  // 몬스터를 끈다.
				CurBullet.Off();   // 총알을 끈다.
			}
		}
	}

}

void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		MainPlayer.Render();
		Bullet::AllRender();
		Monster::AllRender();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		MainPlayer.Input();

		Bullet::AllUpdate();

		Monster::AllUpdate();
		
		Monster::MonsterEndCheck();

		Collision();
	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}