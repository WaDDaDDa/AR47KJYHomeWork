#include <iostream>

class Number
{
private:
	int Value;

public:
	// 맴버 이니셜라이저.
	Number(int _Value)
		: Value(_Value)
	{

	}

	int operator[](size_t _Value)
	{
		return Value;
	}


	bool operator==(int _Value)
	{
		return false;
	}


	// 클래스가 연산자를 사용할수 있게 만들어주는 것.
	// 내 마음대로 만드는 자료형에 연산자 멤버함수를 새로 만들어내는 것이기때문에 
	// 그 기능과 작동은 내가 의도한대로 실현되게 해주면 된다.
	int operator+(int _Value)
	{
		return Value + _Value;
	}
};

int main()
{
	{
		int Value = 10;
		Value + 10;
	}

	{
		// 자신이 논리적으로 이 연산자를 이렇게 만들면 되겠다 할수 있는 

		Number Value = 10;
		Value + 10;

		if (Value == 10)
		{
			int a = 0;
		}

		int Test = Value[2000];
	}

	// 예를 들어 Player + Player를 내가 기능을 넣어주면 가능하게 되고 
	// 그결과 또한 내가 의도한 결과를 뱉어낼수있게 코드를 만들어주면 되는 것이다.


}
