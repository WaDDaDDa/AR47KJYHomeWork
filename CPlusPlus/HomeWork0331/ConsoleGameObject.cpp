#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

void ConsoleGameObject::Render() const
{
	if (false == IsUpdate())
	{
		return;
	}

	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, RenderChar);
}