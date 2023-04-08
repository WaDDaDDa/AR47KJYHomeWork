// HomeWork0407.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include "Player.h"
#include <conio.h>

GameEngineArray<ConsoleGameObject*> AllObject;

void CreateConsoleObject()
{

}

int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 5, 5 };

	ConsoleGameObject* NewPlayer = new Player();

	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	while (Player::IsGameUpdate)
	{
		ConsoleGameScreen::GetMainScreen().ScreenClear();

		if (nullptr != NewPlayer)
		{
			NewPlayer->Update();
			NewPlayer->Render();
		}

		ConsoleGameScreen::GetMainScreen().ScreenPrint();
		Sleep(500);
	}
}

