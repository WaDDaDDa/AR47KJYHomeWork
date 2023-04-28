
#include <iostream>

// Main함수의 인자의 의미.

int main(int _Count, const char** _InitText)
{
	// CWindow NewWindow = new CWindow();
	// NewWindow.Open();
	// 
	// 

	// 내 프로세스가 다른 프로세스를 실행할수도 있습니다.
	// 내가 실행하는 곳에 따라서 위치가 달라진다.
	int Result = system("D:\\Project\\AR47\\CPlusPlus\\x64\\Debug\\078_BitTest.exe");

	for (size_t i = 0; i < _Count; i++)
	{
		// char*
		std::cout << _InitText[i] << std::endl;
	}

	return 1;
}
