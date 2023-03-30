#pragma once
#include "ConsoleGameMath.h"

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{
public:
	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	static const int ScreenXSize = 20;            // 스크린의 x 값
	static const int ScreenYSize = 10;            // 스크린의 y 값     

	inline static ConsoleGameScreen& GetMainScreen()  // 메인스크린을 호출하는 함수. 
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
	char Arr[ScreenYSize][ScreenXSize] = { 0, }; // 배열의 크기에 관해 함부로 접근하지 못하도록 제한.

	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen; // 이런식으로 main스크린을 전역으로 생성하고
	// 생성자를 private로 돌려서 더이상 생성못하게한다.
	// 이러면 콘솔에는 객체가 단 1개만 존재할수있게되는데
	// 이것을 디자인패턴 명칭으로는 싱글톤 패턴이라는 명칭이 있다.
};