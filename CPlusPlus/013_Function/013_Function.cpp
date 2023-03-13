#include <iostream>

// 함수의 선언 방법
// 1. 함수는 다른 함수 내부에서는 선언하지 못한다.
// 2. 함수는 리턴값이 무조건 존재해야 한다.
// 3. 

//    리턴값      이름           함수의 인자 (인자에 _부터 시작하는 코딩습관)
        void     Function      (                      )
        {// 함수의 시작

        }// 함수의 끝

// 인자의 의미
// 무조건 적으로 그 실행흐름의 지역변수입니다.

//함수는 만들면 만들수록 느려진다.
// 리턴값의 의미 
        // 이 함수의 결과를 외부로 보내겠다.
        // void는 아무것도 보내지 않겠다. 라는 의미.
        // 자신을 호출한 외부 메모리 영역에 전달하는 메모리 값.
int Plus(int Left, int Right)
{
    // return 반환한다.

    return Left + Right;
}
// void에서의 return은
// 사용한 즉시 자신을 포함한 실행흐름을 끝낸다.
// void는 sizeof 할수없다.

// 함수를 실행하는데 필요한 메모리 비용은 언제나
// 인자 전체 크기 + 알파
void Test(int Value)
{
    // Test Value
    return;
}


int main()
{
    int Result = Plus(20, 30);

    // main Value
    int Value = 20;
    Test(Value);
}