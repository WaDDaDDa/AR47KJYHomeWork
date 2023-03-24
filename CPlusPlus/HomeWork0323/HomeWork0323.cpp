
#include <iostream>


// 연산자를 가능한한 적용시켜 보자.
// 리턴값은 중요하지 않음. 빌드가 가능한지가 중요.


class Number
{
private:
	int Value;  // private로 직접 접근 못하게 함.

public:
	// 맴버 이니셜라이저.
	Number(int _Value) // 생성자에 int값 선언.
		: Value(_Value)
	{
		Value = _Value;
	}



	int operator[](size_t _Value)
	{
		return Value;
	}



	//  연산자 뒤에 나오는 것에 대하여 인자로 받는다.
	// ex NewNumber + 4 라고한다면 +에 4의인자를 받는 식.
	// 따라서 operator++ 를 지정하면 ++ 뒤의 것을 인자로 받기때문에
	//  후위에 ++ 를 연산시키는것이 아직 논리가 부족함.
	// 후위는 예외규칙이 적용된다.
	int operator+(int _Value)     
	{
		return Value + _Value;
	}

	int operator-(int _Value)     
	{
		return Value - _Value;
	}

	int operator*(int _Value)    //  * 곱셈  포인터와 구분은?
	{
		return Value * _Value;
	}

	Number& operator*()        // *는 주소값에 있는 실제 값을 끌어내야함.
	{
		return *this;          // this는 Number* const 라는 주소값을 뜻함. *this를 하면 실제 값을끌어낸다.
	}

	int operator/(int _Value)    
	{
		return Value / _Value;
	}

	int operator%(int _Value)   
	{
		return Value % _Value;
	}

	bool operator!()
	{
		return !Value;
	}

	int operator~()
	{
		return ~Value;
	}

	int operator= (int _Value)
	{
		return Value = _Value;
	}

	bool operator== (int _Value)
	{
		return Value == _Value;
	}

	int operator-= (int _Value)
	{
		return Value -= _Value;
	}

	int operator+= (int _Value)
	{
		return Value += _Value;
	}

	int operator*= (int _Value)
	{
		return Value *= _Value;
	}

	int operator /= (int _Value)
	{
		return Value /= _Value;
	}

	int operator %= (int _Value)
	{
		return Value %= _Value;
	}

	bool operator!= (int _Value)
	{
		return Value != _Value;
	}

	bool operator&= (int _Value)
	{
		return Value &= _Value;
	}

	bool operator|= (int _Value)
	{
		return Value |= _Value;
	}

	bool operator^= (int _Value)
	{
		return Value ^= _Value;
	}

	int operator<< (int _Value)
	{
		return Value << _Value;
	}

	int operator>> (int _Value)
	{
		return Value >> _Value;
	}

	int operator<<= (int _Value)
	{
		return Value <<= _Value;
	}

	int operator>>= (int _Value)
	{
		return Value >>= _Value;
	}

	bool operator< (int _Value)
	{
		return Value < _Value;
	}

	bool operator> (int _Value)
	{
		return Value > _Value;
	}

	bool operator<= (int _Value)
	{
		return Value <= _Value;
	}

	bool operator>= (int _Value)
	{
		return Value >= _Value;
	}

	bool operator& (int _Value)     //   & 참조와의 구분은?
	{

		return Value & _Value;
	}

	Number* operator&()       //   참조     Number*를 반환하게 함.  & 는 주소값을 반환해야함.
	{
		return this;               // this 는 Number* const 는 Number 의 주소값.
	}

	int operator| (int _Value)
	{
		return Value | _Value;
	}

	int operator^ (int _Value)
	{
		return Value ^ _Value;
	}

	bool operator&& (int _Value)
	{
		return Value && _Value;
	}

	bool operator|| (int _Value)
	{
		return Value || _Value;
	}

	int operator++ ()  // 전위는 가능하나 후위에 지정하는 논리가 부족함.
	{
		return ++Value;
	} // 인자를 넣어주지만 사용할수는 없다.
	// 전위가 후위보다 변수를 1개덜 생성하기때문에 경제적이다. (의미가 크진않다) 자기가만든거아니면

	int operator-- ()
	{
		return --Value;
	}

	/*int operator ? :(int _Value)      ?  지정 불가.
	{

	}*/

	int operator()(int _Value)  // ()이 정의된게 아니라 다른 작용이 있는거 같은데...
	{
		return Value = _Value;
	}

	/*int operator((int _Value)   (  만 지정 불가.
	{

	}

	int operaotr)(int _Value)     )  만 지정 불가.
	{

	}*/

	/*int operator: (int _Value)   :  지정 불가.
	{

	}*/


	/*int operator!<(int_Value)   //내 마음대로 없는 연산자를 지정하는것은 불가능.
	{

	}*/

};


int main()
{

	Number NewNumber = Number(10);    //  Number.Value 에 10

	int Value = 0;
	Value = NewNumber + 3;          //  10 + 3   13
	Value = ++NewNumber;            //  ++10     11
	Value = NewNumber %= 5;         //  11 % 5    1
	
	Number* NPtr = &NewNumber;
	__int64 Adress = (__int64)NPtr;
	*NewNumber;

	int BValue = NewNumber < 4;
	BValue = NewNumber > 456;



	int a = 0;
}
