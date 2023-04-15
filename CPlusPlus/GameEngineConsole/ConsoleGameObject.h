#pragma once
#include "ConsoleGameMath.h"

// Screen에서 움직이는 오브젝트들의 기본기능을 제공한다.
class ConsoleGameObject
{
public:
	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	bool IsDeath()
	{
		return DeathValue;
	}

	void Death()
	{
		DeathValue = true;
	}

	bool IsUpdate()
	{
		return UpdateValue;
	}

	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}

	virtual void Update();
	virtual void Render();

	inline void SetNextPos(const int2& _Value)
	{
		NextPos = _Value;
	}

	inline int2 GetNextPos() const
	{
		return NextPos;
	}

	inline void SetPrevPos()
	{
		PrevPos = Pos;
	}

	inline int2 GetPrevPos() const
	{
		return PrevPos;
	}

protected:
	int2 Pos;
	int2 NextPos;
	int2 PrevPos;
	char RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;

};

