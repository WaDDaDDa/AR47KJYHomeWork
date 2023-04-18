#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineBase/GameEngineDebug.h>
// 설명 :
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

	inline Parts* GetLast()
	{
		if (nullptr == Next)
		{
			return this;
		}

		return Next->GetLast();
	}

	inline void SetNext(Parts* _Next)
	{
		if (nullptr == _Next)
		{
			MsgBoxAssert("자신의 NextNode를 nullptr로 세팅하려고 했습니다.");
		}

		Next = _Next;
	}

	inline int2 GetPrevPos() const
	{
		return PrevPos;
	}

	inline void SetPrevPos(const int2 _setpos)
	{
		PrevPos = _setpos;
	}

	void NextMove();


	inline void SetPos(const int2& _Value) override
	{
		PrevPos = GetPos();
		PrevChar = RenderChar;
		ConsoleGameObject::SetPos(_Value);
	}

	inline bool GetImFood()
	{
		return ImFood;
	}

	inline void ImNotFood()
	{
		ImFood = false;
		return;
	}

protected:
	void Update() override;
	void Death() override;
	Parts* Prev = nullptr;
	Parts* Next = nullptr;
	int2 PrevPos = { 0 , 0 };
	bool ImFood = false;
	wchar_t PrevChar = L'◇';

private:
};

