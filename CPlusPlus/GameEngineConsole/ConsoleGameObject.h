#pragma once
#include "ConsoleGameMath.h"

// Screen에서 움직이는 오브젝트들의 기본기능을 제공한다.
class ConsoleGameObject
{
public:
	virtual inline void SetPos(const int2& _Value)
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
	
	inline void ChangeRenderChar(const wchar_t _Char)
	{
		RenderChar = _Char;
	}

	inline wchar_t GetRenderChar()const
	{
		return RenderChar;
	}


protected:
	int2 Pos;
	wchar_t RenderChar = L' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;
	bool DataValue = true;

};

