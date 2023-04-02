#include "Monster.h"
#include "ConsoleGameScreen.h"

int Monster::Dir = -1;


Monster::Monster() 
{
	RenderChar = 'M';
}

void Monster::Update() 
{
	if (false == IsUpdate())
	{
		return;
	}
	Pos.X += Dir;
}

void Monster::YUpdate()
{
	if (false == IsUpdate())
	{
		return;
	}
	Pos.Y += 1;
}

void Monster::ChangeDir()
{
	Dir *= -1;
}
