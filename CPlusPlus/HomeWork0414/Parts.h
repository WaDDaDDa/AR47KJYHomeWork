#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

// Ό³Έν :
class Parts : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	int2 GetBeforePos() const
	{
		return BeforePos;
	}


protected:
	void Update() override;
	void Death() override;
	Parts* Prev = nullptr;
	Parts* Next = nullptr;
	int2 BeforePos = { 0 , 0 };


private:
};

