#pragma once
#include "Position.h"

class Bullet
{
public:
	Bullet();

	void SetPos(const Position& _Value);

	Position GetPos() const;

	static Bullet FirstBullet;

	void FireBullet();

	void BulletMove();

	void Render();

protected:

private:
	Position Pos = Position(nullptr);
};
