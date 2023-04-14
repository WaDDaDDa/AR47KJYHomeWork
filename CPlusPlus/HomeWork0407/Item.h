#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsolGameScreen;
class Item  : public ConsoleGameObject
{
public:
    Item();
    ~Item();

    Item& operator=(const Item& _Other) = delete;
    Item& operator=(const Item&& _Other) = delete;
    Item(const Item& _Other) = delete;
    Item(const Item&& _Other) = delete;

protected:
    void Update()override;

private:

};

