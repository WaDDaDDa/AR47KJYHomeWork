#pragma once
#include "ConsoleGameObject.h"

class ConsoleGameScreen;   // Ŭ���� ���� ����.
class Player : public ConsoleGameObject    // �ְܼ��ӿ�����Ʈ�� �ڽ�Ŭ����.
{
public:
	Player();
	void Input();

	// �Ѿ��� �ּҰ��� �޾Ƽ� �÷��̾ ���� �Ѿ��ּҰ��� �ִ� �Լ�.
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

