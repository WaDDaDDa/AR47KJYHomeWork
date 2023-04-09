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

void ConsoleGameObject::Update() {}