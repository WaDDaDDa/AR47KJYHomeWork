#pragma once
#include <Windows.h>
#include <assert.h>

class GameEngineDebug
{
public:
    GameEngineDebug();
    ~GameEngineDebug();

    GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
    GameEngineDebug& operator=(const GameEngineDebug&& _Other) = delete;
    GameEngineDebug(const GameEngineDebug& _Other) = delete;
    GameEngineDebug(const GameEngineDebug&& _Other) = delete;

protected:

private:

};

#define MsgBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false);
