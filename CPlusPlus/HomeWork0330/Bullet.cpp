#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount]; // �Ѿ˰�����ŭ �Ѿ� �� ������ ����.

// Bullet ArrBullet[10] = { Bullet (), Bullet (), Bullet (), Bullet (), Bullet (), Bullet (),};

int Bullet::FireCount = 0 ;    // �Ѿ� �߻� ����.

void Bullet::AllRender()      // �Ѿ˰�����ŭ�� üũ�Ͽ� ���� ��Ű�� �Լ�.
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

void Bullet::AllUpdate()    // �Ѿ˰�����ŭ�� üũ�Ͽ� updata ��Ű�� �Լ�.
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

Bullet::Bullet() // �Ѿ� ������
{

}

// ������ ������� �ʰ� �ش� ������ ����� ������ x= 0 y=0�� ���·� �Ѿ��� ��µ��� �ʴ´�.
void Bullet::Render()    // �Ѿ˿� ������ ���ڸ� �־��ִ� �Լ�.  �ְܼ��� ����� �ʿ�������.
{
	if (true == Fire)    // �Ѿ��� Fire�� true��� ������ ���ڸ� �ְڴ�.
	{                    // �ݴ�� false ��� ������ ���ڸ� ���� �ʱ� ������ ȭ�鿡 �ȳ����� �ȴ�.
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

void Bullet::Update()   // �Ѿ��� �������� ������Ʈ�ϴ� �Լ�. y���� �����ϴ�, ���� �ö󰡴� ������ó�� ������.
{
	if (true == Fire)
	{
		--Pos.Y;
	}
}
