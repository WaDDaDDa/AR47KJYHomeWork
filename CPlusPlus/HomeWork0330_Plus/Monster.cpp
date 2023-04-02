#include "Monster.h"
#include "ConsoleGameScreen.h"


Monster Monster::ArrMonster[Monster::MonsterCount];
int Monster::Dir = -1;

Monster::Monster()
{

}
// 화면바깥으로 못나가게 하세요. 

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
		Pos.X += Dir;
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
		// IsScreenOver가 트루면 화면 밖이다.
		// False면 화면 안이다.
		// 화면밖이 되기전에 방향이 전환 되어야 한다.
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

int Monster::ChangeDir()
 {
	if (Dir == 1)
	{
		Dir = -1;
		return Dir;
	}
	if (Dir == -1)
	{
		Dir = 1;
		return Dir;
	}
}

// 만약 Dir이 1이라면 오른쪽으로
// Dir이 -1 이라면 왼쪽