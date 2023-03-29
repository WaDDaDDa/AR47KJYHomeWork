#include "ConsoleGameScreen.h"

#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;
char ConsoleGameScreen::Arr[ConsoleGameScreen::ScreenYSize][ConsoleGameScreen::ScreenXSize] = { 0, };

ConsoleGameScreen::ConsoleGameScreen()
{

}

ConsoleGameScreen& ConsoleGameScreen::GetMainScreen() // 멤버 내부에 static으로 선언된건 static을떼줘야한다.
{
	return MainScreen;
}

Position ConsoleGameScreen::GetScreenSize()
{
	return Position{ ScreenXSize, ScreenYSize };
}

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			/*if (Arr[y][x] == '@')  // 폭탄 위치가 트루면 a 넣지않는다 == 폭탄 여러개 생성 가능.
			{
				continue;
			}*/
			Arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

bool ConsoleGameScreen::IsScreenOver(const Position& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenXSize <= _Pos.X)
	{
		return true;
	}

	if (ScreenYSize <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const Position& _Pos, const char _Ch)
{
	if (true == IsScreenOver(_Pos))  //배열 바깥에는 반환하지 않는다.
	{
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Ch;  // 그 배열에 문자를 넣는다.
}
