#pragma once

// 헤더에만 다 만든다.
class int2
{                          // int2 는 x값과 y값을 가지는 2차원 좌표
public:
	int X = 0;
	int Y = 0;

public:
	inline int2 Half()
	{
		return { X / 2, Y / 2 };
	}

public:
	inline int2()
	{

	}

	// 생성자에 
	inline int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};