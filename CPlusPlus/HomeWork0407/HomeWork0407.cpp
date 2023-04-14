
#include <iostream>
#include <conio.h>

#include <GameEngineBase/GameEngineDebug.h>

#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

#include "GameEnum.h"
#include "Player.h"
#include "Bomb.h"
#include "Item.h"

int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 20, 10 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);


	// 업캐스팅
	// 인터페이스 통일
	// 이 프레임워크 상의 모든 존재들은 업데이트와 랜더라는 인터페이스를 
	// ConsoleGameObject* NewPlayer = new Player();

	// 0번 그룹에 속한다
	// CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
	// 1번 그룹속한다.
	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);

	ConsoleObjectManager::CreateConsoleObject<Item>(ObjectOrder::Item);

	// CreateConsoleObject<Monster>(2);


	while (Player::IsGameUpdate)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}

