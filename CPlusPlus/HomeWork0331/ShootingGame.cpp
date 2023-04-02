#include "ShootingGame.h"

#include <iostream>

// ���� ����� ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;

Monster ShootingGame::ArrMonster[ArrMonsterCount];

void ShootingGame::Loading() //���ӽ��� ���� �غ� �Ǿ�� �� ��ҵ�.
{
	// �����ϸ� ������ ��� �Ѿ��� �߻���� �ʾ������̹Ƿ� �� ����.
	Bullet::AllOff();

	// �÷��̾ �Ѿ��� �����͸� �˰� �Ѵ�.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// �÷��̾ ȭ���� �߾ӿ� ��ġ��Ų��.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	// ������ �ʱ� ��ġ�� �����Ѵ�.
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({ i + 3, 1 });
	}

}

void ShootingGame::Collision() // �Ѿ˰� ���� �浹���� ���
{

	Bullet* BulletArr = Bullet::GetArrBullet();

	// ��� �Ѿ˰�
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		// ������ ������. CurBullet�� BulletArr�ΰ�.
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate()) // ������Ʈ ����� fasle�� �ǳʶڴ�.
		{
			continue;
		}
		// ��� ���ʹ�
		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = ArrMonster[MonsterIndex];

			if (false == CurMonster.IsUpdate()) //������Ʈ ����� fasle�� �ǳʶڴ�.
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())//���Ϳ� �Ѿ��� ��ġ�� ������.
			{
				CurMonster.Off();  // ���͸� ����.
				CurBullet.Off();   // �Ѿ��� ����.
			}
		}
	}

}

void ShootingGame::MonsterEndCheck()
{
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{

		//if (ConsoleGameScreen::IsScreenOver(ArrMonster[i].GetPos()) == ArrMonster[i].IsUpdate())
		//{               ���ݹ����� ��Ƴ��� ���Ͱ� �״�� �Ʒ��� �����
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

		// ĳ���� ��ġ�� ���ڸ� �ϳ� ����.
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