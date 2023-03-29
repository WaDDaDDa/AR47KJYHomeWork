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
{           //배열 넘어가도 계속 진행하지 않게 하기위한 체크
	if (ConsoleGameScreen::MainScreen.IsScreenOver(Bullet::FirstBullet.GetPos()))
	{
		return;
	}
	// 불릿의 y값이 1씩 감소해야함.
	Position New = Bullet::FirstBullet.GetPos();
	New.Y -= 1;
	Bullet::FirstBullet.SetPos(New);

}