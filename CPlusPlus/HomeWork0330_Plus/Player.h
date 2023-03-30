#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Player
{
public:
	Player();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void Input();

	void Render();

	// 전방선언은 이렇게 해도 된다.
	void SetBulletArr(class Bullet* _BulletPtr)
	{
		BulletPtr = _BulletPtr;
	}

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);

	Bullet* BulletPtr;

	// 이런 구조를 Has a라고 한다. Player Has a Bullet
	// Bullet NewBullet; // 플레이어의 신체 내부에 총알 한발이 있다.
	// Bullet* NewBullet; // 바깥에 있는 총알을 조작할수 있다.
};

