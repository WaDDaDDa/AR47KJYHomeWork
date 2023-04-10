#pragma once

#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleGameScreen.h>


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

    void SetChar(char _Char)
    {
        RenderChar = _Char;
    }

    void FireOn()
    {
        Fire = true;
    }

    void FireOff()
    {
        Fire = false;
    }

    bool GetFire()
    {
        return Fire;
    }

    void Explosion()
    {
        if (FirePower == FireCount)
        {
            return;
        }

        for (int i = 0; i < FireCount; i++)
        {
            ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ GetPos().X - i, GetPos().Y }, RenderChar);
            ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ GetPos().X + i, GetPos().Y }, RenderChar);
            ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ GetPos().X , GetPos().Y - i }, RenderChar);
            ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ GetPos().X , GetPos().Y + i }, RenderChar);
        }
        FireCount++;
    }
    
protected:
    void Update() override;
    void Render() override;

private:
    int BoomCount = 10;
    int FireCount = 0;
    int FirePower = 7;
    bool Fire = false;

};

