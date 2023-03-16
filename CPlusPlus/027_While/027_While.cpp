
#include <iostream>

int main()
{

	// 반복문 while

	// while (메모리영역, 조건문)
	//{
	//    실행 코드    조건문이 true면 실행코드 실행.  false면 탈출.
	//}

	
	// while (특정 메모리영역이 참인가 거짓인가)

	// while (내부에는 , 를 통해서 여러가지 조건을 넣을수 있습니다.)
	// , 다음의 가장 오른쪽에 있는 메모리 영역의 값만을 조건으로 칩니다.
	while (printf_s("조건문\n"), true) // <= 무한반복
	{
		printf_s("실행코드\n");
	}
	
	int Value = 5;
	while (Value)
	{
		--Value;
		printf_s("실행코드\n"); 
	}

	do
	{
		--Value;
		printf_s("실행코드\n");
	} while (printf_s("조건문\n"), Value);

}
