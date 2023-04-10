// HomeWork0407.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include "Player.h"
#include "Bomb.h"
#include "GameEnum.h"
#include <conio.h>
#include "ConsoleObjectManager.h"


int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = {5, 5};

	// 업캐스팅
	// 인터페이스 통일
	// 이 프레임워크 상의 모든 존재들은 내가만든 기능들은(업데이트와 렌더라는)인터페이스를 따른다.
	// ConsoleGameObject* NewPlayer = new Player(); 
	// 0번그룹에 속한다.   하지만 보통 숫자로 하지않고 enum이라는 것을 적용하게된다.
	// CreateConsoleObject<Bomb>((int)ObjectOrder::Bomb);
	// 1번그룹에 속한다.
	ConsoleObjectManager::CreateConsoleObject<Player>((int)ObjectOrder::Player);

	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	while (Player::IsGameUpdate)
	{

		ConsoleObjectManager::ConsoleAllObjectUpdate();
	
	}

	ConsoleObjectManager::ConsoleAllObjectdelete();

}

