#include "feed.h"

#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <vector>

feed::feed()
{
	RenderChar = '!';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
	SetPos({ X, Y });
}

feed::~feed()
{

}

void feed::Update()
{
	ConsoleGameObject::Update();
}

void feed::feedcheck()
{
	std::vector<int2> emptyspace;

	for (int y = 0; y < ConsoleGameScreen::GetMainScreen().GetScreenSize().Y; y++)
	{
		for (int x = 0; x < ConsoleGameScreen::GetMainScreen().GetScreenSize().X; x++)
		{
			//map[y][x] = true;
		}
	}

}