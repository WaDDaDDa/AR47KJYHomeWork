#include "Bullet.h"


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
