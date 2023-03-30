
#include "Position.h"
#include "ConsoleGameScreen.h"
#include "Block.h"
#include "Block.h"
#include "Player.h"
#include "Bullet.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>

int main()
{
	Block NewBlock0;          // 새로운 블럭개체를 선언하지 않고 블럭을여러개 만들 방법
	Block NewBlock1;
	Block NewBlock2;

	Position ScreenSize = ConsoleGameScreen::GetScreenSize();

	Player::MainPlayer.SetPos(ScreenSize.Half());
	NewBlock0.SetPos(ScreenSize.Half3());



	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();  // 맵을 a으로 초기화.

		Player::MainPlayer.Render();

		NewBlock0.Render();

		// 만약 키가 눌렸던 상태가 아니라면 출력하지않는다.
		// Player::MainPlayer.CH 가 0 이라면 출력하지 않는다. 라고한다면.
		// 초기에는 없더라도 이동키a가 눌려도 출력하게 된다.
		// 그럼 대응하는 키가 눌렸을 경우만 출력한다면?
		// 폭탄을 설치하고 이동을 하게되면 사라질 것이다.
		// 어떻게할까?
		// 일단 배열 바깥인 -1,-1에 생성되게 만들었음.
		Bomb::FirstBomb.Render();
		// 폭탄이 없는 상태를 표현할 방법.
		Bullet::FirstBullet.Render();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();           // 화면 출력.

		Player::MainPlayer.CH = 0; // 받은 키 초기화. 받은키가 계속 남아있어서 그 키가 반복되는 현상이 생김

		Player::MainPlayer.InputKey();  // 기다리고 키를 받는것.

		Player::MainPlayer.Move(ConsoleGameScreen::GetMainScreen(), NewBlock0);   // 위에서 받은 키를 통해 이동.

		Bomb::FirstBomb.CreateBomb();

		Bullet::FirstBullet.FireBullet();

		Bullet::FirstBullet.BulletMove();

		// 폭탄을 터트리는 로직을 isOverscreen 체크해서 배열내에 있다면 i값을 증가 시킨다.
		// i 가 3이된다면 폭탄이 터진다. 계속 i 값은 증가하며 i 가 증가할수록 폭발이 옆으로 전이된다.
		// 전이된 폭발이 배열밖으로 나가게 된다면 폭발이 있던 위치를 맵과 같은 문자로 초기화 시킨다.
		// 폭발이 끝나면 폭탄으 배열을 화면 밖으로 이동 시킨다.

		// 배열내에 폭탄이 없다면 실행하지 않는다.

		// 폭탄 개체내에 폭발효과 개체가 있어야한다.
		// 그럼 폭발효과가 없는 폭탄 개체는 만들어 질수 없다.
		// 그럼 폭발효과가 먼저 존재하고 폭탄에 폭발효과가 들어가야하는 구조인가?
		// class 폭탄{ class 폭발}  인지  class 폭발 {class 폭탄}  인지
		// 폭발하려면 폭탄의 위치를 알아야 하기 때문에 getpos를 그냥 쓸수있는 전자가 좋겟다.


		// 총알은 따라다녀야한다.
	}

}
