#include <iostream>

// 어느 영역에도 속하지 않는
// 전역이라고 합니다

// 전역에 선언된 변수를 전역 변수라고 부릅니다.
int GlobalValue = 10;   // 전역 변수.

// Test 전역함수라고 부르게 됩니다.
void Test()
{
    int a = 0;  // 지역 변수.
}

// 사용자 정의 자료형 내부의 공간을 맴버공간이라고 합니다.
class Player
{
public:
    // 맴버 함수라고 부르고
    void Damage(int _Att)
    {
        // 여긴 그냥 다시 지역이라고 합니다.
        int Value = 20;
    }

private: // 명확하게 선언하는것을 좋아한다.
    int Hp; // <= 맴버 변수라고 부릅니다.
};

//void Damage(int _Att) 
//{
//
//}

// 이렇게 전역안에 선언된 함수를 전역함수라고 합니다.
int main()
{

    // c++에서 영역에 대한 구분은
    // 전역 지역 맴버 이름있는 NameSapce

    std::cout << "Hello World!\n";
}


