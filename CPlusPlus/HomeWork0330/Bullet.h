#pragma once
#include "ConsoleGameMath.h"
#include "ShootingGame.h"

class Player;
class ConsoleGameScreen;
class Bullet
{
public:
	static const int ArrBulletCount = 10;

	static int FireCount;

	static Bullet* GetArrBullet() 
	{
		return ArrBullet;
	}

	static void AllRender();
	static void AllUpdate();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline bool IsFire() const
	{
		return Fire;
	}

	inline void FireOn() 
	{
		Fire = true;
	}

	void Update();
	void Render();

protected:

private:
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();

	bool Fire = false;

	int2 Pos = int2(0, 0);
};

