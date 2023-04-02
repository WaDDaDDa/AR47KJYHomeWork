#include "ShootingGame.h"

#include <iostream>

// ���� ����� ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::MainPlayer;

void ShootingGame::Loading() //���ӽ��� ���� �غ� �Ǿ�� �� ��ҵ�.
{
	// �����ϸ� ������ ��� �Ѿ��� �߻���� �ʾ������̹Ƿ� �� ����.
	Bullet::AllOff();

	// �÷��̾ �Ѿ��� �����͸� �˰� �Ѵ�.
	MainPlayer.SetBulletArr(Bullet::GetArrBullet());

	// �÷��̾ ȭ���� �߾ӿ� ��ġ��Ų��.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	MainPlayer.SetPos(ScreenSize.Half());

	// ������ �ʱ� ��ġ�� �����Ѵ�.
	Monster::Loading();

}

void ShootingGame::Collision() // �Ѿ˰� ���� �浹���� ���
{

	Bullet* BulletArr = Bullet::GetArrBullet(); //�Ѿ��ǹ迭�ּҸ� �������ִ� BulletArr ����
	Monster* MonsterArr = Monster::GetArrMonster();//�����ǹ迭�ּҸ� �������ִ� MonsterArr ����
	
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
		for (size_t MonsterIndex = 0; MonsterIndex < Monster::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = MonsterArr[MonsterIndex];

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

void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// ĳ���� ��ġ�� ���ڸ� �ϳ� ����.
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