// 091_String_view.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string_view>

class Player {

};

// 레퍼런스를 붙이는 이유는 => 복사 비용때문에 무조건 레퍼런스로 받는게 좋다.
// const 를 붙이는 이유는 의도를 보여주기 위함이다 => 함수안에 니가 넣어준 인자가 변형되지 않을거야.
// 속력과 의도를 전부다 잡는것.
void Function(const Player& _Data)
{

}

void StringFunction(const std::string& Value)
{

}

void StringPtrFunction(const char* Value)
{

}

// 힙을 사용하지 않습니다.
void StringViewFunction(const std::string_view& Value)
{
	// std::string Text = Value.data();
}


int main()
{
	// string은 내부에 std::vector<char>를 들고 있는 자료형

	// const char*

	const char* Ptr = "aaaaaaaaaa";
	// std::vector<char> Inner;
	// Inner.Resize(strlen("aaaaaaaaaa"));
	const std::string Str = Ptr;

	// 내부에 const char*
	int size = sizeof(std::string_view);

	std::string_view Test = "fasdfasdfas";

	const char* Ptr1 = Test.data();

	StringFunction("aaaaaaaaaa");

}