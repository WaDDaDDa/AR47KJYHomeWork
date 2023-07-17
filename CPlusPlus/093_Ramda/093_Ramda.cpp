// 093_Ramda.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

void Function()
{

}

int main()
{

	{
		// 이것 자체로 이미 함수포인터가 된다.
		// 이름없는 함수가 된다.

		// 주소값이 같은 메모리 만이 둘이 완전히 같은 메모리를 증명하는 수단입니다.

		// 100번지에 있는 int B;

		// int* int& 를 받았다고 칠께요.
		// int B일 가능성이 있나요 없나요?



		int A = 20;
		int B = 20;

		int* PtrA = &A;
		int* PtrB = &B;

		// TestAddRess(&A);

		std::function<void()> Ptr = [= /* const int A = A*/]()
		{
			const int* PtrAInner = &A;

			int a = 0;
		};

		Ptr();
	}

	std::function<void()> Ptr;

	{
		int A = 20;
		int B = 20;

		int* PtrA = &A;
		int* PtrB = &B;

		Ptr = [& /* int& A = A*/]()
		{
			int* PtrAInner = &A;

			int a = 0;
		};
	}

	Ptr();

	{
		int A = 20;
		int B = 20;

		int* PtrA = &A;
		int* PtrB = &B;

		std::function<void()> Ptr = [A, &B]()
		{

		};

		Ptr();
	}

}
