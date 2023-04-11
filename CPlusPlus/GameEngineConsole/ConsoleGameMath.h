#pragma once

// 헤더에만 다 만든다.
class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	inline int2 Half() const
	{
		return { X / 2, Y / 2 };
	}

	bool Check(const int2& _Other)const
	{
		return X == _Other.X && Y == _Other.Y;
	}

	bool operator==(const int2& _Other) const
	{
		return X == _Other.X && Y == _Other.Y;
	}

	int2 operator+(const int2& _Other)const
	{
		int2 NewInt = *this;
		NewInt.X += _Other.X;
		NewInt.Y += _Other.Y;
		return NewInt;
	}

	int2 operator*(const int _Value) const
	{
		int2 NewInt = *this;
		NewInt.X *= _Value;
		NewInt.Y *= _Value;
		return NewInt;
	}

	int2 Left() const
	{
		int2 NewInt = *this;
		NewInt.X -= 1;
		return NewInt;
	}

	int2 Left(int _speed)const
	{
		int2 NewInt = *this;
		NewInt.X -= 1 * _speed;
		return NewInt;
	}

	int2 Right()const
	{
		int2 NewInt = *this;
		NewInt.X += 1;
		return NewInt;
	}

	int2 Right(int _speed)const
	{
		int2 NewInt = *this;
		NewInt.X += 1 * _speed;
		return NewInt;
	}
	int2 Up()const
	{
		int2 NewInt = *this;
		NewInt.Y -= 1;
		return NewInt;
	}

	int2 Up(int _speed)const
	{
		int2 NewInt = *this;
		NewInt.Y -= 1 * _speed;
		return NewInt;
	}
	int2 Down()const
	{
		int2 NewInt = *this;
		NewInt.Y += 1;
		return NewInt;
	}

	int2 Down(int _speed)const
	{
		int2 NewInt = *this;
		NewInt.Y += 1 * _speed;
		return NewInt;
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