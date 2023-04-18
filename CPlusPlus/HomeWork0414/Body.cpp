#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "SnakeEnum.h"
#include <iostream>

int Body::BodyCount = 0;

Body::Body()
{
	RenderChar = L'■';
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
	int2 MapSize = ConsoleGameScreen::GetMainScreen().GetScreenSize(); // 메인스크린의 크기를 받아온다
	int2 MapPos = { 0,0 };

	Map.reserve(MapSize.X * MapSize.Y);   // capacity를 x * y로 할당한다.

	for (int y = 0; y < MapSize.Y; y++)
	{
		for (int x = 0; x < MapSize.X; x++)
		{
			MapPos = { x, y };
			wchar_t temp = ConsoleGameScreen::GetMainScreen().GetScreenChar(MapPos);
			if (temp == ConsoleGameScreen::GetMainScreen().GetMainScreenChar())  // 화면상의 char 이 a라면 
			{
				Map.push_back(MapPos);  // 위치를 벡터에 저장.
			}
		}
	}

	if (0 == Map.size())   // 모든 화면을 체크했는데 push_back된것이 없다면 게임 종료.
	{
		printf_s("%s\n", "당신의 승리 입니다.");
		exit(0);
	}

	int Index = GameEngineRandom::MainRandom.RandomInt(0, Map.size() - 1); // 0부터 원소의 갯수 -1 까지중에서 랜덤.
	
	SetPos(Map[Index]);
}


Body::~Body()
{
}
