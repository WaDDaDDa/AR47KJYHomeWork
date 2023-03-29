#pragma once
#include "Position.h"
#include "Player.h"

class Bullet
{
public:
	Bullet();

	void SetPos(const Position& _Value);

	Position GetPos() const;

	static Bullet FirstBullet;

	void FireBullet()
	{
		if (Player::MainPlayer.CH == 'f' || Player::MainPlayer.CH == 'F')
		{
			Bullet::FirstBullet.SetPos(Player::MainPlayer.GetPos());
			return;
		}
		else
		return;
	}

	void BulletMove()
	{
		// �Ҹ��� y���� 1�� �����ؾ���.
		Position New = Bullet::FirstBullet.GetPos();
		New.Y -= 1;
		Bullet::FirstBullet.SetPos(New);
	}

protected:

private:
	Position Pos = Position(5, 6);
};
