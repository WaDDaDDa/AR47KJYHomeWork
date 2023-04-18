#pragma once
#include "ConsoleGameMath.h"
#include <vector>

// �̰� 1�ܰ�
// �ٺ����� �ٺ� ���� ���� 
class ConsoleGameScreen
{
public:
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	//static int2 GetMainScreenSize()
	//{
	//	return MainScreen.GetScreenSize();
	//}

	int2 GetScreenSize();

	void SetScreenSize(int2 _Size);

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, wchar_t _Ch);

	wchar_t GetScreenChar(const int2& _Pos) const;

	wchar_t GetMainScreenChar()const;


protected:

private:
	// char Arr[ScreenYSize][ScreenXSize] = { 0, };

	// char** ArrScreen = nullptr;

	// GameEngineArray<char> ArrPtr ������ 
	// char�� ������ ������ �ִ� �༮
	std::vector<std::vector<wchar_t>> ArrScreen;

	int2 Size;
	wchar_t MainScreenChar = L'��';
	// ĳ������ �迭�� ���� �Ǵٸ� �迭�̶�� �Ҽ� �־��.


	ConsoleGameScreen();
	~ConsoleGameScreen();

	// �̱��� �����̶�� �մϴ�.
	// �����̶� => Ŭ������ ©�� �̷��̷��� ������ ���� ���� ���ȴ�.
	// ������������� �Ҹ��� ���α׷��� ��ȣȸ�� �־���.
	// Ŭ�������� ���質 ������ ¥�� ����� ����� �༮���� ��Ƽ� �̸��� �ٿ��µ�.
	// �װ� ������ �����̶�� �ϰ�.
	// �ƹ��� �Ƚ��.
	static ConsoleGameScreen MainScreen;
};