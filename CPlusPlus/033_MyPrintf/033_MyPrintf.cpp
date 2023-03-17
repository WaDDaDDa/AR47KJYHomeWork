#include <iostream>

//              100       108
inline void Test(int Value, ...)
{
	__int64 Address = (__int64)&Value;   // 8바이트로 변환.
	int* Ptr = (int*)Address;            // 4바이트 int로 변환.

	int Value0 = Ptr[2];                // 다음 인자에 접근하기위해 4바이트x2만큼해서 8바이트 접근.
	int Value1 = Ptr[4];
	int Value2 = Ptr[6];

	int a = 0;

}

inline int MyPrintf(const char* const _Value, ...)
{
	__int64 Address = (__int64)&_Value;  // 인자의 주소값을 8바이트 정수로 변환
	char* Ptr = (char*)Address;         // 그렇게받은 8바이트 정수값을 1바이트char형으로 변환.
	Ptr += 8;                           // 다음 인자에 접근하기위해 char(1) x 8 = 8바이트 접근.
	int* IntPtr = (int*)Ptr;           // 다시 4바이트 정수로 변환.
	int Value0 = *IntPtr;              // 해당 주소에 있는 비트값에 접근.

	return 0;

	int Count = 0;

	while (0 != _Value[Count])
	{
		char Value = _Value[Count];
		if ('%' == Value)
		{
			++Count;
			char Format = _Value[Count];

			switch (Format)
			{
			case 'd':
			{

				break;
			}
			case 's':
			{

				break;
			}
			default:
				break;
			}
		}
		else
		{
			putchar(Value);
		}

		Count++;
	}

	return 0;
}

int main()
{
	Test(10, 1, 2, 3, 4);

	// printf_s("abcdefg %s", 321312);

	MyPrintf("abcdefg %d fasdfasdfasdf", 111);
}
