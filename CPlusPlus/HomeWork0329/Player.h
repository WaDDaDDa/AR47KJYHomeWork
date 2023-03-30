#pragma once
#include "Bomb.h"
#include "ConsoleGameScreen.h"
#include "Block.h"

class Player
{
public:

	char CH = 0;

	static Player MainPlayer;

	Position GetPos() const;

	void SetPos(const Position& _Value);

	void InputKey();

	void Move(ConsoleGameScreen& _Screen, Block& _Block);

	void Render();

protected:

private:
	Player();

	static const int InterFrame = 200;

	Position Pos = Position(0, 0);
};
