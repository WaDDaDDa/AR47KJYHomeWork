#pragma once
#include "Position.h"

class ConsoleGameScreen
{

private:
	ConsoleGameScreen();
public:
	static ConsoleGameScreen MainScreen;     // Ŭ���� ���ο� ������ Ŭ���� ���� ����.
	// ������ Ŭ������ �������� ������
	//��� ������ ���������� �ִµ� ���⼭ ������ MainScreen�� �������� ���� �־��ټ�����.

public:
	// �޸� ���� ��ü�� �޶����ٰ� �����մϴ�.
	static ConsoleGameScreen& GetMainScreen();

	// Ŭ���� ���ο� ���������� �����Ҽ��� �ֽ��ϴ�.
	// Map ũ��/
	static const unsigned int ScreenYSize = 20;
	static const unsigned int ScreenXSize = 10;

	static Position GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	// �̳༮�� ������ ����ؼ� �÷��̾ �ٱ����� �������� ���弼��.
	// �迭 �ٱ��̸� true�� ��ȯ�Ѵ�.
	bool IsScreenOver(const Position& _Pos) const;

	void SetScreenCharacter(const Position& _Pos, const char _Ch);

private:
	static char Arr[ScreenYSize][ScreenXSize];

};
