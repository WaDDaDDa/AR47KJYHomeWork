#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < Size.Y; y++)
	{
		for (size_t x = 0; x < Size.X; x++)
		{
			ArrScreen[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < Size.Y; y++)
	{
		for (size_t x = 0; x < Size.X; x++)
		{
			// Arr[y][x] = 'b';
			printf_s("%c", ArrScreen[y][x]);
		}
		printf_s("\n");
	}
}

ConsoleGameScreen::~ConsoleGameScreen()
{
	//for (size_t i = 0; i < Size.Y; i++)   // �̿� ���������� �����Ҵ�� Ŭ������ ����ϸ鼭 �������� �ʾƵ�
	//{                                     // GameEngineArray ���ο��� �Ҹ��ڷ� �Ͼ�� �ȴ�.
	//	if (nullptr == ArrScreen[i])
	//	{
	//		continue;
	//	}
	//	delete[] ArrScreen[i];
	//	ArrScreen[i] = nullptr;
	//}

	//if (nullptr != ArrScreen)
	//{
	//	delete[] ArrScreen;
	//	ArrScreen = nullptr;
	//}
}

void ConsoleGameScreen::SetScreenSize(int2 _Size)
{
	Size = _Size;
	// ArrScreen == GameEngineArray<GameEngineArray<char>> 
	// 
	ArrScreen.ReSize(Size.Y);  // **GameEngineArray

	for (size_t i = 0; i < Size.Y; i++)
	{
		// ArrScreen[i] == GameEngineArray<char>
		ArrScreen[i].ReSize(Size.X);  // *GameEngineArray
	}
}

// �̳༮�� ������ ����ؼ� �÷��̾ �ٱ����� �������� ���弼��.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}
	
	if (0 > _Pos.Y)
	{
		return true;
	}

	if (this -> Size.X <= _Pos.X)
	{
		return true;
	}

	if (this -> Size.Y <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}



ConsoleGameScreen::ConsoleGameScreen()
{

}

int2 ConsoleGameScreen::GetScreenSize()
{
	return Size;
}