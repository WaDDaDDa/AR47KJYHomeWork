#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

int Bullet::FireCount = 0;


void Bullet::AllRender() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}

		ArrBullet[i].Render();
	}

}


void Bullet::AllUpdate() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}

		ArrBullet[i].Update();
	}
}

Bullet::Bullet()
{

}

void Bullet::Render()
{
	if (true == Fire)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

// 발사된 총알은 계속 y값이 -가 되고 있는것인데.
// 화면에는 출력되지 않아서 보이지 않을뿐 계속해서 y값이 줄어든 배열에 계속 값을 넣고있는 형태인게 아닌가요?
// 만약 그렇다면.
// onsoleGameScreen::IsScreenOver 를 활용해서 스크린 배열안에 들어있는 값일 경우에만 updata를 하도록
// 설정하는 것이 더 좋을까요?   아니면 큰 상관이 없는 건가요?
void Bullet::Update() 
{
	if (true == Fire)
	{
		--Pos.Y;
	}
}
