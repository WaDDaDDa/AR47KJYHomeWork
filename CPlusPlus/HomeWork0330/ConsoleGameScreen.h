#pragma once
#include "ConsoleGameMath.h"

// �̰� 1�ܰ�
// �ٺ����� �ٺ� ���� ���� 
class ConsoleGameScreen
{
public:
	// Ŭ���� ���ο� ���������� �����Ҽ��� �ֽ��ϴ�.
	static const int ScreenXSize = 20;            // ��ũ���� x ��
	static const int ScreenYSize = 10;            // ��ũ���� y ��     

	inline static ConsoleGameScreen& GetMainScreen()  // ���ν�ũ���� ȣ���ϴ� �Լ�. 
	{  
		return MainScreen;
	}

	static int2 GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, }; // �迭�� ũ�⿡ ���� �Ժη� �������� ���ϵ��� ����.

	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen; // �̷������� main��ũ���� �������� �����ϰ�
	// �����ڸ� private�� ������ ���̻� �������ϰ��Ѵ�.
	// �̷��� �ֿܼ��� ��ü�� �� 1���� �����Ҽ��ְԵǴµ�
	// �̰��� ���������� ��Ī���δ� �̱��� �����̶�� ��Ī�� �ִ�.
};