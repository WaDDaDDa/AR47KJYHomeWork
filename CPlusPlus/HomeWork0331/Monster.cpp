#include "Monster.h"
#include "ConsoleGameScreen.h"

int Monster::Dir = -1;

Monster Monster::ArrMonster[ArrMonsterCount];

Monster::Monster() 
{
	RenderChar = 'M';
}

void Monster::XUpdate() 
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

void Monster::Loading()
{
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({ i + 3, 1 });
	}
}

void Monster::AllRender()
{
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].Render();
	}
}

void Monster::AllUpdate()
{
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].XUpdate();
	}
}

void Monster::MonsterEndCheck()
{
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{

		//if (ConsoleGameScreen::IsScreenOver(ArrMonster[i].GetPos()) == ArrMonster[i].IsUpdate())
		//{               공격받으면 살아남은 몬스터가 그대로 아래로 날라옴
		//	Monster::ChangeDir();

		//	for (size_t i = 0; i < ArrMonsterCount; i++)
		//	{
		//		ArrMonster[i].YUpdate();
		//		ArrMonster[i].Update();
		//	}
		//}

		if (true == ConsoleGameScreen::IsScreenOver(ArrMonster[i].GetPos()))
		{
			Monster::ChangeDir();

			for (size_t i = 0; i < ArrMonsterCount; i++)
			{
				ArrMonster[i].YUpdate();
				ArrMonster[i].XUpdate();
			}
		}
	}
}