#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();
	void YUpdate();
	static void ChangeDir();

private:
	static int Dir;

};


