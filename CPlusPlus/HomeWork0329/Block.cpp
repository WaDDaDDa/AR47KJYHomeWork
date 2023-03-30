#include "Block.h"
#include "ConsoleGameScreen.h"

Block::Block()
{

}

Position Block::GetPos() const
{
	return Pos;
}

void Block::SetPos(const Position& _Value)
{
	Pos = _Value;
}

bool Block::IsBlockOver(const Position& _Pos) const
{
	if (Pos.X == _Pos.X && Pos.Y == _Pos.Y)
	{
		return true;
	}

	return false;
}

void Block::Render()
{

	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos(), 'O');  // 장애물 생성
}
