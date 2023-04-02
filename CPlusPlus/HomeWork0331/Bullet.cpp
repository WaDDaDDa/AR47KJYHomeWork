#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

void Bullet::AllOff()  // 불릿 전부 오프
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		ArrBullet[i].Off();
	}
}

void Bullet::AllRender()  // 불릿 전부 랜더 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsUpdate())  // off되어있으면 렌드하지않음.
		{
			continue;
		}

		ArrBullet[i].Render();
	}

}

void Bullet::AllUpdate()  // 불릿 전부 업데이트.
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsUpdate())  // 불릿 off면 업데이트 하지 않음.
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