#pragma once

#include <GameEngineConsole/ConsoleGameObject.h>


class ConsoleGameScreen;
class Bomb : public ConsoleGameObject
{
public:
    Bomb();
    ~Bomb();

    Bomb& operator=(const Bomb& _Other) = delete;
    Bomb& operator=(const Bomb&& _Other) = delete;
    Bomb(const Bomb& _Other) = delete;
    Bomb(const Bomb&& _Other) = delete;

protected:
    void Update() override;

private:
    int BoomCount = 10;

};

