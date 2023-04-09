#pragma once
#include "ConsoleGameMath.h"
#include "GameEngineArray.h"

// 이게 1단계
// 근본오브 근본 수학 물리 
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

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private:
	// char Arr[ScreenYSize][ScreenXSize] = { 0, };

	// char** ArrScreen = nullptr;

	// GameEngineArray<char> ArrPtr 여러개 
	// char를 여러개 가질수 있는 녀석
	GameEngineArray<GameEngineArray<char>> ArrScreen;

	int2 Size;

	// 캐릭터의 배열을 가진 또다른 배열이라고 할수 있어요.


	ConsoleGameScreen();
	~ConsoleGameScreen();

	// 싱글톤 패턴이라고 합니다.
	// 패턴이란 => 클래스를 짤때 이러이러한 구조가 정말 많이 사용된다.
	// 갱스오브포라고 불리는 프로그래머 동호회가 있었다.
	// 클래스간의 관계나 구조를 짜는 방식이 비슷한 녀석들을 모아서 이름을 붙였는데.
	// 그걸 디자인 패턴이라고 하고.
	// 아무도 안써요.
	static ConsoleGameScreen MainScreen;
};