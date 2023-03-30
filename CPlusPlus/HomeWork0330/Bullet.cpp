#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount]; // 총알갯수만큼 총알 을 생성을 선언.

// Bullet ArrBullet[10] = { Bullet (), Bullet (), Bullet (), Bullet (), Bullet (), Bullet (),};

int Bullet::FireCount = 0 ;    // 총알 발사 갯수.

void Bullet::AllRender()      // 총알갯수만큼을 체크하여 랜더 시키는 함수.
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

void Bullet::AllUpdate()    // 총알갯수만큼을 체크하여 updata 시키는 함수.
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

Bullet::Bullet() // 총알 생성자
{

}

// 무조건 출력하지 않고 해당 조건을 만들어 놓으면 x= 0 y=0인 상태로 총알이 출력되지 않는다.
void Bullet::Render()    // 총알에 지정한 문자를 넣어주는 함수.  콘솔게임 헤더가 필요해진다.
{
	if (true == Fire)    // 총알의 Fire가 true라면 지정한 문자를 넣겠다.
	{                    // 반대로 false 라면 지정한 문자를 넣지 않기 때문에 화면에 안나오게 된다.
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

void Bullet::Update()   // 총알의 움직임을 업데이트하는 함수. y값이 감소하는, 위로 올라가는 움직임처럼 보여짐.
{
	if (true == Fire)
	{
		--Pos.Y;
	}
}
