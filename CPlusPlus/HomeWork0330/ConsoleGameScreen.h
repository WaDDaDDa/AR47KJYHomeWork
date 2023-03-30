#pragma once
#include "ConsoleGameMath.h"

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{
public:
	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static ConsoleGameScreen& GetMainScreen()
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
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	ConsoleGameScreen();

	// 싱글톤 패턴이라고 합니다.
	// 패턴이란 => 클래스를 짤때 이러이러한 구조가 정말 많이 사용된다.
	// 갱스오브포라고 불리는 프로그래머 동호회가 있었다.
	// 클래스간의 관계나 구조를 짜는 방식이 비슷한 녀석들을 모아서 이름을 붙였는데.
	// 그걸 디자인 패턴이라고 하고.
	// 아무도 안써요.
	static ConsoleGameScreen MainScreen;
};