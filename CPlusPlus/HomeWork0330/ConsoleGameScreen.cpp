#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;  // �ֿܼ� ��ũ���� �ϳ���� �����ϰ� ����.

void ConsoleGameScreen::ScreenClear()            // ��ũ���� x y ũ�� ��ŭ�� �迭�� 'a'�� ���� �ʱ�ȭ.
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const     // ���� �̹� �ٵ� �ִ� ��ũ���� ��¸� �ϸ�Ǳ� ������
{                                                 // ���� �ٲ��� �������̶�� const�� �Ͻ����ش�.
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)    // �ش� �迭�� ���ڸ� ����Ѵ�.
		{
			// Arr[y][x] = 'b';
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

// �̳༮�� ������ ����ؼ� �÷��̾ �ٱ����� �������� ���弼��.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const   // x y���� ���� int2�� �޾Ƽ� 
{                                                           // ��ũ���� x y���� ���Ͽ� ��µǴ� �迭���� 
	if (0 > _Pos.X)                                        // �ٱ��̸� true�� ��ȯ, �ƴϸ� false.
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

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch) // ��ũ���� ���ڸ� �ִ� �Լ�.
{                                       
	if (true == IsScreenOver(_Pos))   // ��ũ�� �迭 �̳��� �ִ��� Ȯ���ϰ�  true��� �迭�̳��� ���ٴ� ��.
	{                                 // ������ �ƹ����� ��ȯ���� �ʰ� ����.
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Ch;      // �迭 �̳��� �ִٸ� �ش� ���� ����. ����� ���� ScreenPrint�Լ���.
}



ConsoleGameScreen::ConsoleGameScreen()  // �ְܼ��� ��ũ���� �������Լ�.
{
}

int2 ConsoleGameScreen::GetScreenSize()  // ��ũ���� x yũ�⸦ int2�ڷ������� ��ȯ���ִ� �Լ�.
{
	return int2{ ScreenXSize, ScreenYSize };
}