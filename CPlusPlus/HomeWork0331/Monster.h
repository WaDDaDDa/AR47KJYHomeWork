#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();

	void XUpdate();
	void YUpdate();

	static void ChangeDir();
	static const int ArrMonsterCount = 4;
	static void Loading();
	static void AllRender();

	static void AllUpdate();

	static void MonsterEndCheck();

	inline static Monster* GetArrMonster()
	{
		return ArrMonster;
	}

private:
	static int Dir;

	static Monster ArrMonster[ArrMonsterCount];
};


