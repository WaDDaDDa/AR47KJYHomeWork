#pragma once
#include "ConsoleGameMath.h"
#include "ShootingGame.h"

class Player;
class ConsoleGameScreen;
class Bullet
{
public:
	static const int ArrBulletCount = 10;  // 총알의 갯수를 전역으로 선언.
	
	static int FireCount;             // 총알이 발사된 횟수를 전역으로 선언. 
	// 누군가가 접근해서 바꾸면 안된다. private로 설정하고 값을 불러오는 함수를 따로 만들자.
	// get set을 만들고 set에 0을넣어 초기화를 해주려고 하는데 안된다.


	static Bullet* GetArrBullet()    // private 인 ArrBullet를 리턴하는 함수.
	{                              // Bullet*인 이유는 주소값을 반환하기 위해서.
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