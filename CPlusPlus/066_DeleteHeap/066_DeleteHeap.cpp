
#include <iostream> // iostream 안에 crtdgb.h가 포함되어 있다.

void main()
{
	// 힙을 사용할 것이라면 실행코드 최상위에 아래 코드를 적어두고 확인해야한다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// 중복할당이라고함
	// 먼저 만들어진 heap의 int는 잃어버린것이다.
	{
		int* Newint = new int();
		Newint = new int();
	}
	// 아래와 같이 한번 할당한건 지우고 다시 받아서 사용하면 된다.
	{
		// delete는 가르키고 있는 주소에 있는 메모리를 지우는것인데
		// 가르키고 있는 주소 값 자체는 그대로 가지고 있기때문에
		// 어떠한 값이 남아있을지 알수없다.
		// 그렇기 때문에 delete하게 된다면 nullptr을 가르키도록 해주는것이
		// 정상적인 삭제 방법 이다.
		int* Newint = new int();
		delete Newint;
		Newint = new int();
	}

	{
		int* Newint = new int();
		// 습관적 null체크 하는것은 좋은 습관이다.
		if (nullptr == Newint)  // 힙 또한 주소값을 가지는것이기 때문에 null체크를 하는것이 좋다.
		{
			return;
		}

		delete Newint;
	}

	// 지운거 또지우기
	// 댕글링 포인터라고 합니다.
	{
		int* Newint = new int();
		// 메모리 크러쉬라고 합니다. (지운녀석을 또 지우면 일어나는 현상)
		delete Newint;
		// delete Newint;
	}

	{  // 안전한 삭제.
		// null이 아니라면 삭제하고 null로 만들어버리면.
		int* Newint = new int();
		if (nullptr != Newint)
		{
			delete Newint;
			Newint = nullptr;
		}
		// 두번 중복으로 한다 하더라도 null이기때문에 delete를 수행할수 없게 된다.
		// 가장 안전하고 누구나 사용하는 방식.
		if (nullptr != Newint)
		{
			delete Newint;
			Newint = nullptr;
		}

	}

	int test = 0;
	int* ptr = new int();
	delete ptr;
	ptr;
	int a = 0;

}
