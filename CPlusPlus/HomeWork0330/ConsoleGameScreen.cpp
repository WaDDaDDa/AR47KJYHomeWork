#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;  // 콘솔에 스크린은 하나라고 상정하고 선언.

void ConsoleGameScreen::ScreenClear()            // 스크린의 x y 크기 만큼의 배열에 'a'로 값을 초기화.
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const     // 값이 이미 다들어가 있는 스크린을 출력만 하면되기 때문에
{                                                 // 값이 바뀌지 않을것이라는 const로 암시해준다.
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)    // 해당 배열의 문자를 출력한다.
		{
			// Arr[y][x] = 'b';
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const   // x y값을 가진 int2를 받아서 
{                                                           // 스크린의 x y값과 비교하여 출력되는 배열보다 
	if (0 > _Pos.X)                                        // 바깥이면 true를 반환, 아니면 false.
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

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch) // 스크린에 문자를 넣는 함수.
{                                       
	if (true == IsScreenOver(_Pos))   // 스크린 배열 이내에 있는지 확인하고  true라면 배열이내에 없다는 뜻.
	{                                 // 때문에 아무값도 반환하지 않고 리턴.
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Ch;      // 배열 이내에 있다면 해당 문자 대입. 출력은 위의 ScreenPrint함수로.
}



ConsoleGameScreen::ConsoleGameScreen()  // 콘솔게임 스크린의 생성자함수.
{
}

int2 ConsoleGameScreen::GetScreenSize()  // 스크린의 x y크기를 int2자료형으로 반환해주는 함수.
{
	return int2{ ScreenXSize, ScreenYSize };
}