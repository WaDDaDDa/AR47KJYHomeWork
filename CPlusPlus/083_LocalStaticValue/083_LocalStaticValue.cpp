
#include <iostream>

// 함수내부에 static을 선언할수있다.

void TestStatic()
{
	static int Value = 0;
	++Value;
}

// 아래의 의미처럼 바뀐다.

static int Value = 0;

void TestFunction()
{
	std::cout << Value << std::endl;
	++Value;
}

// 왜사용 하느냐?
// 해당 함수내에서만 사용 하지만 전역으로 해야할 필요가 있을경우에 사용하게 된다.
// 다른 곳에서의 접근이 쉽지않아서 방어적인 면도 있다.


int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		TestFunction();
	}

	std::cout << "Hello World!\n";
}
