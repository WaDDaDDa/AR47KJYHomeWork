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

	if (false >= --BoomCount)
	{
		Off();
	}

}