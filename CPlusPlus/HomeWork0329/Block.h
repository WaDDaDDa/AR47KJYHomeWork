#pragma once
#include "Position.h"


class Block
{
public:
	Block();

	Position GetPos() const;

	void SetPos(const Position& _Value);

	bool IsBlockOver(const Position& _Pos) const;

protected:

private:
	static const int InterFrame = 200;

	Position Pos = Position(0, 0);
};

