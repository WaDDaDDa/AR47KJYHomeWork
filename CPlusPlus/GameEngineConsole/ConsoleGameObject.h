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

	virtual void Death()
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



	inline bool GetDataValue()const
	{
		return DataValue;
	}

	inline void SetDataValue(bool _bValue)
	{
		DataValue = _bValue;
	}

protected:
	int2 Pos;
	char RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;
	bool DataValue = true;

};

