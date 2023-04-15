#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include "Parts.h"
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "SnakeEnum.h"

class feed  :public ConsoleGameObject
{
public: 
    feed();
    ~feed();

    feed& operator=(const feed& _Other) = delete;
    feed& operator=(const feed&& _Other) = delete;
    feed(const feed& _Other) = delete;
    feed(const feed&& _Other) = delete;

    void Update()override;

protected:

private:

};

