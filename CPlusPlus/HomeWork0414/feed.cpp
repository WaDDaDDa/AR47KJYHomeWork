#include "feed.h"

#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>

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