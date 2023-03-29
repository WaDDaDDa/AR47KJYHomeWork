#pragma once
class Position
{
public:

	int X = 0;
	int Y = 0;

	inline Position Half() const
	{
		return { X / 2, Y / 2 };
	}

	inline Position Half3() const
	{
		return { X / 3, Y / 3 };
	}

	inline Position(int _X, int _Y)    // 생성자 함수도 분리가 가능하다.
		: X(_X), Y(_Y)
	{

	}
};

