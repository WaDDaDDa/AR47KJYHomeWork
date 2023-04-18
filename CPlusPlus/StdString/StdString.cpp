
#include <iostream>
#include <vector>


// 그냥 char는 멀티바이트로 한글은 2바이트 영어는1바이트 이런식으로 다르게 적용시키고
// wchar_t는 모두 동일하게 2바이트를 지정한다.
// 속도는 wchar_t이 더빠르지만 절대적인 메모리의 크기도 더 크다.

class MyString
{
public:
	void operator+(const MyString& _Other)
	{
		std::vector<char> NewBuffer;

		NewBuffer.reserve(Buffer.size() + _Other.Buffer.size());

		for (size_t i = 0; i < Buffer.size(); i++)
		{
			NewBuffer.push_back(Buffer[i]);
		}

		for (size_t i = 0; i < _Other.Buffer.size(); i++)
		{
			NewBuffer.push_back(_Other.Buffer[i]);
		}

		Buffer = NewBuffer;
	}


	MyString(const char* _Text)
	{
		int i = 0;
		while (0 != _Text[i])
		{
			Buffer.push_back(_Text[i]);
		}
	}

private:
	std::vector<char> Buffer;
};

//  200
void Function(std::string _Value)
{

}

void FunctionRef(const std::string& _Value)
{

}

// &&

int main()
{
	// 문자라고 하는건 굉장히 많이 사용된다.
	// "C:\Program Files (x86)"
	// "C:\Program Files (x86)\Steam"
	// 특히나 파일입출력이나 경로를 표현할때 문자를 잘 편집할수 있어야 하기 때문에
	// 문자열을 편집하는 기술이나 알고리즘 함수들에 대해서 많이 알면 알면 알수록 편해집니다.

	// 인코딩 
	// 숫자 == 어떤 글자나 의미를 매칭하는 것을 의미한다.
	// 1바이트 인코딩 아스키 ANSI 
	// 1~2바이트 멀티바이트 인코딩 <= 65536 특정 한 국가의 문자 정도는 표현할수 있게 되었다.
	// 2바이트 와이드 바이트 
	// 2바이트 인코딩까지는 국가별로 달라지는 매칭형식입니다. 한국에서의 가
	// 가 == 5001
	// ㏂ == 5001

	// 우리나라에서 저장한 텍스트파일이 다른 나라에서 열면 
	// 3바이트 문자형 및 4바이트 문자형들이 나왔습니다.
	// UTF 인코딩 시리즈들.
	// 프로그래밍은 국가 코드를 따릅니다.
	{
		// 국가코드에 따른 문자열로 해석됩니다.
		"Hello World!\n"; // 

		char Arr0[6] = "하 호";

		L"하하하 호호호";

		wchar_t Arr1[4] = L"하 호";
	}

	{
		//   300
		char Arr0[256] = "안녕하세요";

		//   400
		char Arr1[256] = "안녕하세요";

		// 주소값을 비교한것이기 때문에 같다고 생각한다면 굉장히 잘못된 개념을 가지고 있는 것이다.

		// char 배열형[]
		if (reinterpret_cast<char*>(Arr0) == reinterpret_cast<char*>(Arr1))
		{
			int a = 0;
		}

		// 100       20
		if (Arr0 == "안녕하세요")
		{
			int a = 0;
		}

		int a = 0;

	}
	// Arr0 + Arr1;

	// std::string vector형태의 자료구조입니다.

	// std::vector<char>

	// std::string내부에는 다음과 같은 함수들이 있습니다.
	{
		// char이고
		std::string Text0 = "안녕하세요";

		Text0.append("cccc");

		/*if (Text0 == "cccc")
		{

		}*/


		int a = 0;

		// "안녕" => "오늘"로 바꿔줘.
		// Text0.replace()

		// + 는 내부에서 append를 호출하고 있는 것.
		// Text0.append()

		// 사용해보서요
		// Text0.find

		// Text0.rfind

		// Text0.find_last_not_of

		// Text0.find_first_of

	}

	{
		// char이고
		std::string Text0 = "안녕하세요";
		std::string Text1 = "○반갑습니다";
		std::string Result = Text0 + Text1;

		std::cout << Result << std::endl;

	}

	{
		// 국가 코드를 변경해주는 함수를 사용해야 출력이 가능하다.
		setlocale(LC_ALL, "KOR");

		// 기본적으로 비주얼 스튜디오의 출력 국가 코드는 미국
		// 와이드 바이트는 국가 코드에 영향을 받기 때문입니다.

		// char이고
		std::wstring Text0 = L"안녕하세요";
		std::wstring Text1 = L"반갑습니다";
		std::wstring Result = Text0 + Text1;

		std::wcout << Result << std::endl;
	}



	// std::cout << "Hello World!\n";
}
