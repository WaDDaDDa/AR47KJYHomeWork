// 070_Assert.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include <assert.h>

inline void MsgBoxAssert(const char* _Text)
{
    MessageBoxA(nullptr, _Text, "Error", MB_OK);  // 메세지박스를 띄우는 함수.
    assert(false);                                // 의도적으로 오류를 만들어서 확인하는 명령.
}

//  #define은 텍스트를 그대로 복붙해서 사용하는 문법.
// #define MsgBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false);


int main()
{
    std::cout << "Hello World!\n";
}
