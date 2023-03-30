#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

int Bullet::FireCount = 0;


void Bullet::AllRender() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}

		ArrBullet[i].Render();
	}

}


void Bullet::AllUpdate() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}

		ArrBullet[i].Update();
	}
}

Bullet::Bullet()
{

}

void Bullet::Render()
{
	if (true == Fire)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

// �߻�� �Ѿ��� ��� y���� -�� �ǰ� �ִ°��ε�.
// ȭ�鿡�� ��µ��� �ʾƼ� ������ ������ ����ؼ� y���� �پ�� �迭�� ��� ���� �ְ��ִ� �����ΰ� �ƴѰ���?
// ���� �׷��ٸ�.
// onsoleGameScreen::IsScreenOver �� Ȱ���ؼ� ��ũ�� �迭�ȿ� ����ִ� ���� ��쿡�� updata�� �ϵ���
// �����ϴ� ���� �� �������?   �ƴϸ� ū ����� ���� �ǰ���?
void Bullet::Update() 
{
	if (true == Fire)
	{
		--Pos.Y;
	}
}

//
//void Bullet::Update()
//{
//	if (true == Fire)
//	{
//		--Pos.Y;
//	}
//}