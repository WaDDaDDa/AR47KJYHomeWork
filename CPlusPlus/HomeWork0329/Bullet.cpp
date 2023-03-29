#include "Bullet.h"
#include "Player.h"

Bullet Bullet::FirstBullet;


Bullet::Bullet()
{

}

void Bullet::SetPos(const Position& _Value)
{
	Pos = _Value;
}

Position Bullet::GetPos() const
{
	return Pos;
}

void Bullet::FireBullet()
{
	if (Player::MainPlayer.CH == 'f' || Player::MainPlayer.CH == 'F')
	{
		Bullet::FirstBullet.SetPos(Player::MainPlayer.GetPos());
		return;
	}
	else
		return;
}

void Bullet::BulletMove()
{           //�迭 �Ѿ�� ��� �������� �ʰ� �ϱ����� üũ
	if (ConsoleGameScreen::MainScreen.IsScreenOver(Bullet::FirstBullet.GetPos()))
	{
		return;
	}
	// �Ҹ��� y���� 1�� �����ؾ���.
	Position New = Bullet::FirstBullet.GetPos();
	New.Y -= 1;
	Bullet::FirstBullet.SetPos(New);

}