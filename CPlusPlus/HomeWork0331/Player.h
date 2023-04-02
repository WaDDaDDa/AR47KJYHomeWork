#pragma once
#include "ConsoleGameObject.h"


class ConsoleGameScreen;
class Player : public ConsoleGameObject
{
public:
	Player();
	void Input();
	void SetBulletArr(class Bullet* _BulletPtr)
	{
		BulletPtr = _BulletPtr;
	}

protected:

private:
	void ShotUpdate();
	static const int InterFrame = 200;
	Bullet* BulletPtr;
	int BulletCount = 0;
};

