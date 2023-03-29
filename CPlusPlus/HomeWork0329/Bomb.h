#pragma once
#include "Position.h"

class Bomb
{
public:
	Bomb();

	static Bomb FirstBomb;

	Position GetPos() const;

	void SetPos(const Position& _Value);

protected:

private:
	static const int InterFrame = 200;

	Position Pos = Position(0, 0);
};
