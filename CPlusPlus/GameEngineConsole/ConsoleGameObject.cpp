#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

void ConsoleGameObject::Render()
{
	if (false == IsUpdate())
	{
		return;
	}

	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, RenderChar);
}

void ConsoleGameObject::Update() //Player에 Update함수 오버라이드 하기위해 콘솔게임오브젝트에 함수뼈대만 가상함수로 만들어놓음.
{

}