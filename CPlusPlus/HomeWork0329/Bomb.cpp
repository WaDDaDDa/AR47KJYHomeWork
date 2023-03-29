#include "Bomb.h"

Bomb Bomb::FirstBomb;

Bomb::Bomb()
{

}

Position Bomb::GetPos() const
{
	return Pos;
}

void Bomb::SetPos(const Position& _Value)
{
	Pos = _Value;
}
