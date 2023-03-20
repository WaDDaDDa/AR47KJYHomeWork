#include <iostream>
#include <conio.h>

int main()
{
	int Count = 0;
	while (Count <= 10)
	{
		++Count;
	}


	// 비교문의 조건이 false가 되면 for문이 종료된다.
	for (int i = 0; i < 100; i++)
	{

	}

	// 이렇게 사용하는 경우는 거의 없다.
	for (;/*true*/;)  // 무한 반복하게 된다.
	{
		int a = 0;
	}

	for (
		int i = 0; // 초기화문      1번
		i < 5;  // 비교문           2번
		i++ // 증감문               4번
		)
	{
		int a = 0; // 실행코드      3번
	}
	
	// 1 -> 2 -> 3-> 4의 순서로 진행하고   2번의 비교문이 거짓이 나올때까지
	// 2번 3번 4번을 반복하게 된다.


	for ( /*초기화문*/; /*비교문*/; /*증감문*/)
	{
		//실행코드
	}



}
