
#include <iostream>


void MyPrintf(char* _ptr) // const가 아니여서 들어간 값이 변경이 된다.
{
	*_ptr = 'a';
}

void MyPrintf_s(const char* _ptr)
{

}

void MyPrintf_s1(const char* const _ptr)
{

}

int main()
{
	char Arr[10] = {};

	MyPrintf(Arr);

	// MyPrintf("test Print"); // 코드영역에 있는 "test Print" 는 값이 변경 불가능해서 인자로 사용 못해.

	MyPrintf_s("test Print"); // 코드영역에 있는 "test Print" 또한 넣을수 있게 된다. 
	//               <=   const char[11]  암시적 형변환.
	const char* Ptr = "test Print";
	MyPrintf_s1(Ptr);
	MyPrintf_s1("test Print"); // 세 함수의 차이를 이해하라.

	// 포인터 문법중 하나인
	// random index access
	char Ch0 = Ptr[0];
	char Ch1 = Ptr[1];
	char Ch2 = Ptr[2];
	char Ch3 = Ptr[3];
	char Ch4 = Ptr[4];
	char Ch5 = Ptr[5];
	char Ch6 = Ptr[6];
	char Ch7 = Ptr[7];
	char Ch8 = Ptr[8];
	char Ch9 = Ptr[9];
	char Ch10 = Ptr[10];
	char Ch11 = Ptr[11];
	char Ch12 = Ptr[12];
	char Ch13 = Ptr[13];
	char Ch14 = Ptr[14];
	// "test Print" 는 코드영역에 있는데  그 뒤까지 읽어봤지만 0이었을뿐.
	
	{
		const char ArrTest[2] = { 'a', 'b' };
		// 'a', 'b' 자체는 코드영역에 존재하지만 ArrTest배열은 스택영역에 있다.
		const char* Ptr = ArrTest;

		char Ch0 = Ptr[0];
		char Ch1 = Ptr[1];
		char Ch2 = Ptr[2];
		char Ch3 = Ptr[3];
		char Ch4 = Ptr[4];
		char Ch5 = Ptr[5];
		//  ArrTest[2] = {'a', 'b'} 는 스택 영역에 있는데 뒤에값들은 쓰레기 값들이 나오게되는.

	}
}
