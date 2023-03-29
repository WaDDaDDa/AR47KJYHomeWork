#include "Bomb.h"
#include "Player.h"

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

void Bomb::CreateBomb()
{
	if (Player::MainPlayer.CH == 'k' || Player::MainPlayer.CH == 'K')
	{
		Bomb::FirstBomb.SetPos(Player::MainPlayer.GetPos());
		return;
	}
	else
		return;
}
