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

	// �̷� ������ Has a��� �Ѵ�. Player Has a Bullet
	// Bullet NewBullet; // �÷��̾��� ��ü ���ο� �Ѿ� �ѹ��� �ִ�.
	// Bullet* NewBullet; // �ٱ��� �ִ� �Ѿ��� �����Ҽ� �ִ�.
};

