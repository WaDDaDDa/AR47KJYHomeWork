#include "Monster.h"
#include "ConsoleGameScreen.h"


Monster Monster::ArrMonster[Monster::MonsterCount];

Monster::Monster()
{

}
// ȭ��ٱ����� �������� �ϼ���. 

void Monster::Render()
{
	if (true == Monster::On())
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, 'M');
	}
}

void Monster::AllRender()
{
	for (size_t i = 0; i < Monster::MonsterCount; i++)
	{
		if (false == ArrMonster[i].On())
		{
			continue;
		}

		ArrMonster[i].Render();
	}

}

void Monster::Update()
{
	if (true == Monster::On())
	{
		--Pos.Y;
	}
}

void Monster::AllUpdate()
{
	for (size_t i = 0; i < Monster::MonsterCount; i++)
	{
		if (false == ArrMonster[i].On())
		{
			continue;
		}

		ArrMonster[i].Update();
	}
}

void Monster::Loading()
{
	for (int i = 0; i < Monster::MonsterCount; i++)
	{
		Monster::ArrMonster[i].SetPos({ i + 3, 1 });
	}
}