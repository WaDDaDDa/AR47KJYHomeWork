#pragma once

// ������� �� �����.
class int2
{                          // int2 �� x���� y���� ������ 2���� ��ǥ
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

	// �����ڿ� 
	inline int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};