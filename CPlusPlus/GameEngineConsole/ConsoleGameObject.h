#pragma once
#include "ConsoleGameMath.h"

// Screen에서 움직이는 오브젝트들의 기본기능을 제공한다.
class ConsoleGameObject
{
public:
	inline void SetPos(const int2& _Value)  // 위치를 설정하는 함수.
	{
		Pos = _Value;
	}

	inline int2 GetPos() const             // 위치를 받는 함수.
	{
		return Pos;
	}

	inline bool IsDeath() const            // 데이터의 완전한 삭제를 Death로 표현.
	{
		return DeathValue;
	}

	inline void Death()
	{
		DeathValue = true;
	}

	inline bool IsUpdate() const           // UpdateValue를 반환하는 함수.
	{
		return UpdateValue;
	}

	inline void On()
	{
		UpdateValue = true;              // UpdataValue 가 true면 On으로 켜져있다 의 의미.
	}

	inline void Off()
	{
		UpdateValue = false;            // UpdataValue 가 false면 Off으로 껴져있다 의 의미.
	}

	virtual void Update();
	virtual void Render();   // 각 오브젝트가 가진 RenderChar를 출력시켜줌.
	

protected:
	int2 Pos;
	char RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;

};

