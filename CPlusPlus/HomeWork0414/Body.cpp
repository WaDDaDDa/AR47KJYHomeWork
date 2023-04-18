#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "SnakeEnum.h"
#include <iostream>

int Body::BodyCount = 0;

Body::Body()
{
	RenderChar = L'��';
	ImFood = true;

	if (0 == BodyCount)
	{
		int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
		int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);

		SetPos({ X, Y });
		BodyCount++;
		return;
	}

	std::vector<int2> Map;
	int2 MapSize = ConsoleGameScreen::GetMainScreen().GetScreenSize(); // ���ν�ũ���� ũ�⸦ �޾ƿ´�
	int2 MapPos = { 0,0 };

	Map.reserve(MapSize.X * MapSize.Y);   // capacity�� x * y�� �Ҵ��Ѵ�.

	for (int y = 0; y < MapSize.Y; y++)
	{
		for (int x = 0; x < MapSize.X; x++)
		{
			MapPos = { x, y };
			wchar_t temp = ConsoleGameScreen::GetMainScreen().GetScreenChar(MapPos);
			if (temp == ConsoleGameScreen::GetMainScreen().GetMainScreenChar())  // ȭ����� char �� a��� 
			{
				Map.push_back(MapPos);  // ��ġ�� ���Ϳ� ����.
			}
		}
	}

	if (0 == Map.size())   // ��� ȭ���� üũ�ߴµ� push_back�Ȱ��� ���ٸ� ���� ����.
	{
		printf_s("%s\n", "����� �¸� �Դϴ�.");
		exit(0);
	}

	int Index = GameEngineRandom::MainRandom.RandomInt(0, Map.size() - 1); // 0���� ������ ���� -1 �����߿��� ����.
	
	SetPos(Map[Index]);
}


Body::~Body()
{
}
