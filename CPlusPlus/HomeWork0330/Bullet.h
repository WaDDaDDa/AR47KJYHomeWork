#pragma once
#include "ConsoleGameMath.h"
#include "ShootingGame.h"

class Player;
class ConsoleGameScreen;
class Bullet
{
public:
	static const int ArrBulletCount = 10;  // �Ѿ��� ������ �������� ����.
	
	static int FireCount;             // �Ѿ��� �߻�� Ƚ���� �������� ����. 
	// �������� �����ؼ� �ٲٸ� �ȵȴ�. private�� �����ϰ� ���� �ҷ����� �Լ��� ���� ������.
	// get set�� ����� set�� 0���־� �ʱ�ȭ�� ���ַ��� �ϴµ� �ȵȴ�.


	static Bullet* GetArrBullet()    // private �� ArrBullet�� �����ϴ� �Լ�.
	{                              // Bullet*�� ������ �ּҰ��� ��ȯ�ϱ� ���ؼ�.
		return ArrBullet;
	}

	static void AllRender();
	static void AllUpdate();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline bool IsFire() const
	{
		return Fire;
	}

	inline void FireOn() 
	{
		Fire = true;
	}

	void Update();
	void Render();

protected:

private:
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();

	bool Fire = false;

	int2 Pos = int2(0, 0);
};