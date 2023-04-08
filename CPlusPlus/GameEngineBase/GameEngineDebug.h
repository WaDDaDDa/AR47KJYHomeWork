#pragma once
#include <Windows.h>
#include <assert.h>
#include <iostream>

class GameEngineDebug
{
public:
    GameEngineDebug();
    ~GameEngineDebug();

    static void LeckCheck();

    GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
    GameEngineDebug& operator=(const GameEngineDebug&& _Other) = delete;
    GameEngineDebug(const GameEngineDebug& _Other) = delete;
    GameEngineDebug(const GameEngineDebug&& _Other) = delete;

protected:

private:

};

#define MsgBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false);
