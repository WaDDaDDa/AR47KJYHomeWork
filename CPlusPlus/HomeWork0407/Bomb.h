#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>


class ConsoleGameScreen;
class Bomb : public ConsoleGameObject
{

public:
	// constrcuter destructer
	Bomb();
	~Bomb();

	// delete Function
	Bomb(const Bomb& _Other) = delete;
	Bomb(Bomb&& _Other) noexcept = delete;
	Bomb& operator=(const Bomb& _Other) = delete;
	Bomb& operator=(Bomb&& _Other) noexcept = delete;

	void Init(int _BombPower);

protected:
	void Update() override;
	void Render() override;

private:
	int BoomCount = 5;
	int MaxExpPower = 5;
	int CurExpPower = 0;
};

