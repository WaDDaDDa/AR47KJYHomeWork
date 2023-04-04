#include <iostream>

// 함수의 포인터.
// 이 함수도 프로세스로 메모리에 올라갈것이기 때문에.
// 위치가 있을수밖에 없다. (주소값이 존재)
// 이 위치는 정해져 있어요.
void PlayerAttack()
{
	printf_s("플레이어가 공격합니다.");
}

void PlayerMove()
{
	printf_s("플레이어가 이동합니다.");
}

// 문법적으로도 어려워하는 부분이고.
// 행동을 변수로 만드는 것입니다.

class PlayerMoveButton     // 플레이어가 움직이는것밖에 수행하지못한다.
{
public:
	// void(*Ptr)();

	void Click()
	{
		PlayerMove();
	}
};

class PlayerAttackButton    // 플레이어가 공격하는것밖에 수행하지 못한다.
{
public:
	// void(*Ptr)();

	void Click()
	{
		PlayerAttack();
	}
};

class UIButton       // 플레이어의 이동이든 공격이든 수행시켜줄수있다.
{
public:
	void(*Ptr)() = nullptr;

	void Click()
	{
		if (nullptr == Ptr)  // 포인터를 사용한다면 반드시 해야할 null체크
		{
			return;
		}

		Ptr();   // 함수의 주소값에 있는 함수를 사용한다.
	}
};



int main()
{
	{
		// void(*)();            함수 포인터의 기본형.

		void(*Ptr)();

		// void PlayerAttack()
		// PlayerAttack 주소값을 의미하게 되니까.
		// 둘의 자료형은 완전히 동일하다.
		// void(*)() == void PlayerAttack();
		//    int  ==  10;

		// 모든 자료형은 배열로 사용할수 있습니다.   함수또한 배열로 사용할수있다.
		// int 변수명[상수] => int Arr[10]        int인 Arr을 10개 만든다.
		// void(*변수명[상수])() = void(*ArrFunctions[10])()    함수인 ArrFunctions를 10개 만든다.

		// int Arr[10];  
		// int* Ptr = Arr;  암시적 형변형.
		
		// int* Arr[10]; 
		// int** Ptr = Arr;  암시적 형변형.
		
		// 함수의 배열도 똑같다.
		// void(*ArrFunctions[10])();  
		// void(**FunctionsPtr)() = ArrFunctions;  암시적 형변형.

		// 포인터와 배열의 암시적 형변형이 이루어지는 관계에대한 이해가 필요하다.
		// 이해만 한다면 몇개의 포인터가 어디에 붙든지 상관이없다.
		{
			int* Arr[10];
			int** Ptr = Arr;
		}

		{
			void(*ArrFunctions[10])();
			void(**FunctionsPtr)() = ArrFunctions;
		}

		{
			int****** Arr[10];
			int******* Ptr = Arr;
		}

		// Ptr = 특정한 함수의 이름을 넣어줌으로
		// Ptr 이 변수가 그 함수를 호출할수 있게 된다.

		int* intPtr;        // int[ ] 형으로 암시적 형변형 가능 .
		int* intPtrArr[10];  // int** 형으로 암시적 형변형 가능.

		// int
		intPtrArr[0];       // int**의 값을 불러오는것이므로 int*으로 볼수있다.
		// *intPtrArr 과 같다.

		int intArr[10];     // int*형으로 암시적 형변형 가능.

		// int Value = 10;

		// main()
		// int main()
	}

	{
		// 함수를 포인터로 사용하게 된다면 변수를 쓰는것처럼 쓸수있게 된다.
		UIButton PlayerAttackButton;
		UIButton PlayerMoveButton;

		PlayerAttackButton.Ptr = PlayerAttack; //UI버튼 클래스의 함수주소를받는Ptr에 어택함수를 넣게됨.
		PlayerMoveButton.Ptr = PlayerMove;

		PlayerAttackButton.Click();  // 그에 해당하는 클릭을 사용한다.
		PlayerMoveButton.Click();
	}

	{
		int ArrValue[20];
		int* Ptr = ArrValue;
		*Ptr;

		// ArrValue = int[]
		// Ptr = int*
		// *Ptr = int
		// Ptr[0] = int
		// Ptr[1] = int



		int* ArrTest[20];
		int** PtrAAA = ArrTest;
		*PtrAAA;

		// ArrTest = int*[]
		// PtrAAA = int**
		// *PtrAAA = int*
		// PtrAAA[0] = int*
		// PtrAAA[1] = int*



	}

	{
		// void(*Ptr)();

		// void(*)()

		void(*ArrFunction[20])();
		ArrFunction[0] = PlayerAttack;
		void(**PtrTest)() = ArrFunction;
		PtrTest[0]();
		int Size = sizeof(PtrTest);

		// ArrTest = void(*[])()
		// PtrTest = void(**)()
		// *PtrTest = void(*)()
		// PtrTest[0] = void(*)()
		// PtrTest[1] = void(*)()

		// sizeof(PtrTest) == 8

	}

	// 리턴값 (* 함수포인터명 ) (인자) 
	//void(*Ptr)() = PlayerAttack;
	//Ptr();
	//Ptr = PlayerMove;
	//Ptr();

}
