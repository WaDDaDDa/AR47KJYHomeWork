
#include <iostream>

int main()
{
	// 어떤 자료형을 봤다면 그것은 추가적인 문법으로 모두 배열이 될수 있다.
	{}
	{
	int Value = 10;
	// 자동으로 전부다 0으로 초기화 됩니다.
	int ArrValue[5] = {}; 

	int ArrValue2[5] = {0, };

	int ArrValue3[5] = {0, 1, 2, 3, 4};
	// 값을 한개라도 써놓고 난 다음에 써놓지 않은 부분은 자동으로 0으로 초기화 해준다.

	// int형에서 만약 위의 ArrValue[0]이 100번지라고 한다면
	// ArrValue[1]은 104번지가 됩니다.
	}

	{
		// bool 형이라고 한다면 ArrValue[0]이 100번지라고 한다면
		// ArrValue[1]은 101번지가 됩니다.

		bool Value = 10;
		// 자동으로 전부다 0으로 초기화 됩니다.
		bool ArrValue1[5] = {};
		
		bool ArrValue2[5] = { 0, };
		
		bool ArrValue3[5] = { 0, true, true, true, true };
		// C++에서는 0을 false로 두는것의 습관을 가지면 좋을듯
	}

	{
		// 문자의 배열은 축약형 표현을 사용할수있다.

		char ArrValue[5] = { 'a', 'b', 'c' };
		// 의 형태를
		char ArrValue1[5] = "abc";
		// 로 만들수있다.
	}



	{
		// 초기화 제발 부탁합니다.
		int ArrValue[5];
		// 이상태로 냅두면 초기화가 안된 상태라 쓰레기 값들이 가득 차있는 상태이다.

	}


	// 모든 이름은 시작위치를 표현하게 됩니다.
	// => 자료형을 선언하고 그 뒤에 이름을 붙였어
	// [] <= 랜덤인덱스 연산자

	// V <= 이런 이름은 무조건 메모리의 시작 위치를 표현하게 됩니다.
	char V;

	// V[0]

	// 배열의 경우에는 랜덤인덱스 연산자를 통해서
	// ArrValue2  100번지라고하면
	ArrValue[0];
	// ArrValue[정수]
	// ArrValue 시작위치 + (sizeof(자료형) * 정수)
	// 위치(주소)의 데이터(비트값)에 접근하겠다는 뜻이 됩니다.

	char ArrValue2[3];
	// ArrValue2 == 100번지라고 가정하면
	// 100 + sizeof(char) * 3
	// 100 + 1 * 3
	// 103 번지





}

