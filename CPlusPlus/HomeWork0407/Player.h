#pragma once

#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleGameScreen;   // Ŭ���� ���� ����.
class Player : public ConsoleGameObject    // �ְܼ��ӿ�����Ʈ�� �ڽ�Ŭ����.
{
public:
	static bool IsGameUpdate;

public:
	Player();
	void Update() override;

protected:

private:

};

