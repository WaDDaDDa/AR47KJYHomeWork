
#include <iostream>

// typedef 문법 번외.
// typedef사용할 자료형에 *포인터를 하는게 아니라 변경될 키워드에 *를 붙이면 그게 해당자료형의 포인터다.

typedef int MYINT, * MYTEST;

// MYINT는 int,  MYTEST는 int*가 된다.

// c의 문법을 거의다 그대로 c++에서 사용할수 있다.
// C++은 C를 포함한다. <= 완 전 개소리

// 문법적으로는 c의 스타일을 거의 다 사용할수 있다.
// 99c를 거의다 사용할수 있다.

// c와 c++의 구조체의 차이는
// c는 맴버함수를 넣을수가 없다.
//struct __tagPlayer
//{
//    int HP;
//    int ATT;
//};
//
//typedef struct __tagPlayer Player;

// 선언과 동시에 typedef를 할수가 있다.
// 이경우에는 중괄호 뒤에 변경될 키워드 선언한다.
typedef struct __tagPlayer
{
    int HP;
    int ATT;
} Player, Test, * PPlayer;

int main()
{
    int Test;
    int* Ptr0 = nullptr;
    MYTEST Ptr1 = nullptr;

    {
        // 안그러면 컴파일에러나요.
        // struct Player NewPlayer;
        Player NewPlayer;


    }

    // wchar_t* LPWSTR;

    std::cout << "Hello World!\n";
}
