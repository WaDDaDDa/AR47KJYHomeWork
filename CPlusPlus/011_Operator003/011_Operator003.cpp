
#include <iostream>

int main()
{
    // 삼항 연산자.
    //  a ? b : c

    // 참 혹은 거짓? 참일때 메모리 : 거짓일때 메모리
    int Left = 7;
    int Right = 3;
    int Result = 0;

    // 조건에 대하여 참이라면 100을 거짓이라면 200을 Result에 대입하라 라는의미의 코드
    Result = (Left != Right) ? 100 : 200;
    Result = true ? 100 : 200;
    Result = false ? 100 : 200;

    // sizeof연산자(단항연산자)
    // sizeof(메모리 영역)
    // ()안에 있는 메모리 영역의 바이트 크기를 리턴 합니다.
    Result = sizeof(int);
    Result = sizeof(bool);



}
