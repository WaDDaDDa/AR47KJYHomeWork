#pragma once
#include "ConsoleGameMath.h"

// Screen���� �����̴� ������Ʈ���� �⺻����� �����Ѵ�.
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

protected:
	int2 Pos;
	char RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;

};

