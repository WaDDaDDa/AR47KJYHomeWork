#include "Bomb.h"


Bomb::Bomb()
{
	RenderChar = '@';
}

Bomb::~Bomb()
{

}
 
void Bomb::Update()  // 가상함수 오버로딩
{
	ConsoleGameObject::Update(); // 오버로딩 된 함수가 기본적으로 부모클래스의 A를 실행하고
	// 오버로딩된 B를 실행하는 동작을 할수도 있으면 이런식으로 아무것도 없는 Update()함수
	// 이더라도 오버로딩된 함수안에 사용해주면 부모의 A를 실행하고 자식의B를 실행하도록 가능하다.


	// 다른 곳에 사용될때에도 부모코드를 확인하기에 용이하다.
	if (false == GetFire())   // Fire 이 false 면 폭탄카운트 감소하고 0보다 작아지면
		                      // 폭탄의 문자를 &로 바꾸고 Fire를 true로 바꾼다.
	{
		if (0 >= --BoomCount) // off면 힙에 off된 bomb이 계속 남아있는 의미가 된다.
		{
			//Off();  // BoomCount가 0이 된다면. 폭발을 실행.
			// 폭탄의 문자가 & 로 변하면서 &가 십자가로 한칸씩 이동하는.
			Bomb::SetChar('&'); // 폭탄의 문자를 '&'로 변경.
			FireOn();
			// 폭탄의 위치를 기준으로 폭발한다.
		}
	}
}

void Bomb::Render()
{
	ConsoleGameObject::Render();

	if (true == GetFire()) // Fire이 true이면 폭발 하는중. 이라는뜻. 폭발이끝나면
		// isupdate 와 Fire 모두 false로 바꿔줌.
	{
		// 폭발 매커니즘. 여기에.
		
		Explosion();

		if (FireCount == FirePower) // 폭발 카운트가 0보다 작아지면 폭발종료.
		{
			Death();
		}
	}

}

void Bomb::Explosion()
{
	if (FirePower == FireCount)
	{
		return;
	}

	for (int i = 0; i < FireCount; i++)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos().Left(i), RenderChar);
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos().Right(i), RenderChar);
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos().Up(i), RenderChar);
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(GetPos().Down(i), RenderChar);
	}
	FireCount++;
}