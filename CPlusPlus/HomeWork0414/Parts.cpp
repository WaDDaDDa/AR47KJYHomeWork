#include "Parts.h"

Parts::Parts()
{
}

Parts::~Parts()
{
}

void Parts::Update()
{
	ConsoleGameObject::Update();
}

void Parts::Death()
{
	ConsoleGameObject::Death();
}

void Parts::NextMove()
{
	if (nullptr == Next)
	{
		return;
	}

	int2 CurPos = GetPos();
	int2 NextPos = GetPrevPos();

	Next->SetPos(NextPos);
	Next->ChangeRenderChar(PrevChar);

	return Next -> NextMove();
}