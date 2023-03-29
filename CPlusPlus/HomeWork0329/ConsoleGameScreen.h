#pragma once
#include "Position.h"

class ConsoleGameScreen
{

private:
	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;     // 클래스 내부에 본인의 클래스 선언 가능.
	// 본인의 클래스를 전역으로 선언함
	//얻는 이점은 여러가지가 있는데 여기서 선언한 MainScreen을 여기저기 값을 넣어줄수있음.

public:
	// 메모리 영역 자체가 달라졌다고 봐야합니다.
	static ConsoleGameScreen& GetMainScreen();

	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	// Map 크기/
	static const int ScreenYSize = 20;
	static const int ScreenXSize = 10;

	static Position GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
	// 배열 바깥이면 true를 반환한다.
	bool IsScreenOver(const Position& _Pos) const;

	void SetScreenCharacter(const Position& _Pos, const char _Ch);

private:
	static char Arr[ScreenYSize][ScreenXSize];

};
