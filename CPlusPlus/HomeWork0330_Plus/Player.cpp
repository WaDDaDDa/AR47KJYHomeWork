#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

Player::Player()
{

}
// ȭ��ٱ����� �������� �ϼ���. 
void Player::Input()
{
	if (0 == _kbhit())
	{
		// 0.5�ʰ� �����.
		Sleep(InterFrame);
		// �Ϻη� ���߰� ����̴ϴ�.
		// continue; �ݺ��� ���ο����� ��밡��
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
		BulletPtr[Bullet::FireCount].SetPos(Pos);
		BulletPtr[Bullet::FireCount].FireOn();
		Bullet::FireCount++;
		break;

	case 'k':
	case 'K': //���� Ű.
		BulletPtr[Bullet::FireCount].SetPos(Pos);    // �÷��̾� ��ġ���� �Ѿ� �߻�
		BulletPtr[Bullet::FireCount].FireOn();       // �Ѿ��� �߻�Ǿ��ٴ� true
		Bullet::FireCount++;                         // �Ѿ� �Һ� ī��Ʈ.

		NextPos = Pos;                               // �Ѿ��� ���� ��ġ.
		NextPos.X += 1;                              // 3������ ������ �ϱ� ���� x�迭 �� ����. (������ �Ѿ�)
		BulletPtr[Bullet::FireCount].SetPos(NextPos);
		BulletPtr[Bullet::FireCount].FireOn();        // �߻�Ǿ���.
		Bullet::FireCount++;                          // �Ѿ� �Һ� ī��Ʈ ����.

		NextPos.X -= 2;                               // �Ѿ��� ������ġ. ���ʿ� ��ġ�ϱ����� -2.
		BulletPtr[Bullet::FireCount].SetPos(NextPos);
		BulletPtr[Bullet::FireCount].FireOn();
		Bullet::FireCount++;                          // �Ѿ� �Һ�.

		// ������ : �Ѿ� ������ üũ ���� �ʱ� ������ �Ѿ��� 9���� �������� �߻��ϸ�
		// 12���� ��� ���� �߻���.
		// 1. �Ѿ˰����� �߻� �������� üũ�Ѵ�. => �Ѿ� ���� �����ϸ� �������Ѿ��� ���� �߻�ȴ�.
		// 2. �������� �ٸ� �Ѿ������� ���� �� Ư�� �Ѿ��� ������ ����.
		// 3. �ϴ� �Ѿ˰����� �������� �ʰ� �����Ѵ�.
	default:
		break;
	}

	Sleep(InterFrame);
}


void Player::Render()
{
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '*');
}