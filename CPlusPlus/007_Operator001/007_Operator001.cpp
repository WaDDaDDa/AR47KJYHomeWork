

int main()
{
	int Left = 7;
	int Right = 3;
	int Result = 0;

	// 연산자에는 
	// 단항 연산자 = 메모리 영역이 1개만 필요하면 단항
	// 이항 연산자 = 메모리 영역이 2개만 필요하면 단항
	// 삼항 연산자 = 메모리 영역이 3개만 필요하면 단항

	// ex) '=' 연산자는 이항 연산자 입니다.
	// Left, 3을 사용해서 2개의 메모리 영역이 있어야만 동작하기 때문에 이항연산자 라고 한다.

	// 산술연산자는 보통 이항연산자가 많습니다.

	//        7       3
	Result = Left + Right; // 10
	Result = Left - Right; // 4
	Result = Left * Right; // 21
	// C++에서 정수의 나눗셈은 몫만 나온다.
	Result = Left / Right; // 2
	// 나머지 연산자는 아래 기호(%) 이다.
	Result = Left % Right; // 1

	//단항 연산자
	Result = -Left; // -7
	Result = +Left; // +7
	// 전위, 후위
	// 연산자의 연산순서에 따라 달라지게 됩니다.
	// 전위 : 연산이 되기전에 가장 먼저 처리하고 나머지 계산을 진행한다.
	// 후위 : 모든 계산이 끝나고 넘어갈때에 계산을 진행한다
	Result = ++Left; // Result 8 , Left 8
	Result = Left++; // Result 8,  Left 9
	Result = --Left; // Result 8,  Left 8
	Result = Left--; // Result 8,  Left 7

	// 연산자 순서.
	// 1. 전위 괄호 곱셈나눗셈 대입 후위 순으로 ---- 좀더 공부할것 정확하게
	Result = 1 + 2 * 3;
	// () 괄호 연산자
	Result = (1 + 2) * 3;

	// bool이라는 자료형은 논리형이라고 부른다.
	// 논리형은 true와 false로 이루어진 자료형이다.
	// true는 논리형 상수 참 == 0이아닌 다른수
	// false는 논리형 상수 거짓 == 0

	bool bResult = true;
	bResult = false;



}
