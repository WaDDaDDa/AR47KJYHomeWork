#include "Monster.h"
#include "ConsoleGameScreen.h"


Monster Monster::ArrMonster[Monster::MonsterCount];
int Monster::Dir = -1;

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
		// IsScreenOver�� Ʈ��� ȭ�� ���̴�.
		// False�� ȭ�� ���̴�.
		// ȭ����� �Ǳ����� ������ ��ȯ �Ǿ�� �Ѵ�.
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

// ���� Dir�� 1�̶�� ����������
// Dir�� -1 �̶�� ����