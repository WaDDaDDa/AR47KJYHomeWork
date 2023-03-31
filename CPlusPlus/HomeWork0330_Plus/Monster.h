#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;

class Monster
{
public:
	Monster();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void Render();

	static void AllRender();

	void Update();

	static void AllUpdate();

	static const int MonsterCount = 14;

	inline bool On()
	{
		Life = true;
		return Life;
	}


	inline bool Off()
	{
		Life = false;
		return Life;
	}

	static void Loading();

protected:

private:
	bool Life = true;

	static Monster ArrMonster[Monster::MonsterCount];

	int2 Pos = int2(0, 0);

	// 이런 구조를 Has a라고 한다. Player Has a Bullet
	// Bullet NewBullet; // 플레이어의 신체 내부에 총알 한발이 있다.
	// Bullet* NewBullet; // 바깥에 있는 총알을 조작할수 있다.
};

