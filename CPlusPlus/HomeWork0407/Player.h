#pragma once

#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleGameScreen;   // 클래스 전방 선언.
class Player : public ConsoleGameObject    // 콘솔게임오브젝트의 자식클래스.
{
public:
	static bool IsGameUpdate;

public:
	Player();
	void Update() override;

protected:

private:

};

