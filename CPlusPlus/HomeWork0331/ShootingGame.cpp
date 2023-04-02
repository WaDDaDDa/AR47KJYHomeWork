#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;

Monster ShootingGame::ArrMonster[ArrMonsterCount];

void ShootingGame::Loading() //게임시작 전에 준비 되어야 할 요소들.
{
	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알의 포인터를 알게 한다.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	// 몬스터의 초기 위치를 설정한다.
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({ i + 3, 1 });
	}

}

void ShootingGame::Collision() // 총알과 몬스터 충돌했을 경우
{

	Bullet* BulletArr = Bullet::GetArrBullet();

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
		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = ArrMonster[MonsterIndex];

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

void ShootingGame::MonsterEndCheck()
{
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{

		//if (ConsoleGameScreen::IsScreenOver(ArrMonster[i].GetPos()) == ArrMonster[i].IsUpdate())
		//{               공격받으면 살아남은 몬스터가 그대로 아래로 날라옴
		//	Monster::ChangeDir();

		//	for (size_t i = 0; i < ArrMonsterCount; i++)
		//	{
		//		ArrMonster[i].YUpdate();
		//		ArrMonster[i].Update();
		//	}
		//}

		if (true == ConsoleGameScreen::IsScreenOver(ArrMonster[i].GetPos()))
		{
			Monster::ChangeDir();

			for (size_t i = 0; i < ArrMonsterCount; i++)
			{
				ArrMonster[i].YUpdate();
				ArrMonster[i].Update();
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
		NewPlayer.Render();
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Render();
		}

		Collision();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();

		Bullet::AllUpdate();

		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

		MonsterEndCheck();

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}