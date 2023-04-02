#pragma once

// 헤더에만 다 만든다.
class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	inline int2 Half()
	{
		return { X / 2, Y / 2 };
	}

	bool Check(const int2& _Other)
	{
		return X == _Other.X && Y == _Other.Y;
	}

	bool operator==(const int2& _Other) 
	{
		return X == _Other.X && Y == _Other.Y;
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