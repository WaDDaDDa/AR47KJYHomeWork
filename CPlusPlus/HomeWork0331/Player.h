#pragma once
#include "ConsoleGameObject.h"

class ConsoleGameScreen;   // 클래스 전방 선언.
class Player : public ConsoleGameObject    // 콘솔게임오브젝트의 자식클래스.
{
public:
	Player();
	void Input();

	// 총알의 주소값을 받아서 플레이어가 가진 총알주소값에 넣는 함수.
	inline void SetBulletArr(class Bullet* _BulletPtr)
	{
		BulletPtr = _BulletPtr;
	}

protected:

private:
	void ShotUpdate();
	static const int InterFrame = 200;
	Bullet* BulletPtr;
	int BulletCount = 0;
};

