#include "ConsoleGameScreen.h"

#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;
char ConsoleGameScreen::Arr[ConsoleGameScreen::ScreenYSize][ConsoleGameScreen::ScreenXSize] = { 0, };

ConsoleGameScreen::ConsoleGameScreen()
{

}

ConsoleGameScreen& ConsoleGameScreen::GetMainScreen() // ��� ���ο� static���� ����Ȱ� static��������Ѵ�.
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
			/*if (Arr[y][x] == '@')  // ��ź ��ġ�� Ʈ��� a �����ʴ´� == ��ź ������ ���� ����.
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
	if (true == IsScreenOver(_Pos))  //�迭 �ٱ����� ��ȯ���� �ʴ´�.
	{
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Ch;  // �� �迭�� ���ڸ� �ִ´�.
}
