#include <iostream>

int main()
{
	// const char[8]
	"aaaaaaa";

	// const char* const 인자에 <= const char[8]형이 암시적 형변환을 통해 들어가게 된것.
	printf_s("aaaaaaa");



	{
		// 자료형은 그저 해석하는 방식의 차이이다.
		// 같은 비트값을 두고 어떤자료형으로 해석하느냐에 따라
		// 출력값이 달라지는것일 뿐이다. (비트값이 변하는게 아니다)

		bool bValue = true;
		int aValue = 0b11111111111111111111111111111111;
		// true 가 1이면 결과가
		//      0b000000000000000000000000000000000001; 로 나와야하는데
		// 1바이트인 bool이 int로 형변환 될때에는 연산이 이루어지는 것이다.
		// ( 비트값이 변동 된다.)
		aValue = bValue;  // bool(1바이트) -> int(4바이트)로

		{
			// 아예 변환을 허용하지 않는 자료형 관계또 존재한다.
			int Value = 0;
			int* Ptr = nullptr;

			Ptr = Value;  // 형변환이 불가능.
		}

		{
			// 모든건 메모리가 생기면 자료형이 존재합니다.

			// int[10] 형이라는 자료형
			int Arr[10];
			
			int Value = Arr; // 형변환이 불가능.

			// int*   int[10]
			int* Ptr = Arr; // 변환 가능. 
			// 자료형이 다른데 대입이된다.
			// => 암시적 형변환이 된다고 한다.

		}


	}


}
