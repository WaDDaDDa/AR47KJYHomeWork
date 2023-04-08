#pragma once
#include "ConsoleGameMath.h"

// Screen���� �����̴� ������Ʈ���� �⺻����� �����Ѵ�.
class ConsoleGameObject
{
public:
	inline void SetPos(const int2& _Value)  // ��ġ�� �����ϴ� �Լ�.
	{
		Pos = _Value;
	}

	inline int2 GetPos() const             // ��ġ�� �޴� �Լ�.
	{
		return Pos;
	}

	inline bool IsDeath() const            // �������� ������ ������ Death�� ǥ��.
	{
		return DeathValue;
	}

	inline void Death()
	{
		DeathValue = true;
	}

	inline bool IsUpdate() const           // UpdateValue�� ��ȯ�ϴ� �Լ�.
	{
		return UpdateValue;
	}

	inline void On()
	{
		UpdateValue = true;              // UpdataValue �� true�� On���� �����ִ� �� �ǹ�.
	}

	inline void Off()
	{
		UpdateValue = false;            // UpdataValue �� false�� Off���� �����ִ� �� �ǹ�.
	}

	virtual void Update();
	virtual void Render();   // �� ������Ʈ�� ���� RenderChar�� ��½�����.
	

protected:
	int2 Pos;
	char RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;

};

