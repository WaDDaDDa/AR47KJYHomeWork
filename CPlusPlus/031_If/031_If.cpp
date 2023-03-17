#include <iostream>

int ReturnValue()
{
	return 10;
}


int main()
{
	// if (메모리영역)    메모리 영역이 참이면 실행코드 실행. 거짓이면 실행 하지 않는다.
	// {
	//    실행코드
	// }


	int Value = ReturnValue();
	if (Value)
	{
		printf_s("실행됩니다");
	}

	if (ReturnValue())
	{
		printf_s("실행됩니다1");
	}

	// 한줄치기 극혐
	if (ReturnValue())
		printf_s("실행됩니다1");

	if (0);

	{
		printf_s("실행됩니다1");
	}


	if (printf_s("10"), 0)
	{
		printf_s("실행됩니다0");
	}
	else if (0)
	{
		printf_s("실행됩니다1");
	}
	else if (0)
	{
		printf_s("실행됩니다2");
	}
	else if (0)
	{
		printf_s("실행됩니다1");
	}
	else if (0)
	{
		printf_s("실행됩니다2");
	}
	else
	{
		// 모든 if문들이 실패하면 무조건 else내부의 코드가 실행됩니다.
		printf_s("다 실패해서 실행됩니다");
	}
	// if를 여러개쓸때엔 else if 를 여러개만들어서 쓸수있으며.
	// else if는 먼저나온것이 통과가 된다면 if함수를 종료
	// 통과되는 if  else if문이 없다면 else로 넘어가서 실행하고 종료.

}
