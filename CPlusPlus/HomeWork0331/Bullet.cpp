#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

void Bullet::AllOff()  // �Ҹ� ���� ����
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		ArrBullet[i].Off();
	}
}

void Bullet::AllRender()  // �Ҹ� ���� ���� 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsUpdate())  // off�Ǿ������� ������������.
		{
			continue;
		}

		ArrBullet[i].Render();
	}

}

void Bullet::AllUpdate()  // �Ҹ� ���� ������Ʈ.
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsUpdate())  // �Ҹ� off�� ������Ʈ ���� ����.
		{
			continue;
		}

		ArrBullet[i].Update();
	}
}

Bullet::Bullet()
{
	RenderChar = '^';
}


void Bullet::Update() 
{
	if (true == IsUpdate())
	{
		--Pos.Y;
	}
}