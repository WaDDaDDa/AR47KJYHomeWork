#include <iostream>

int main()
{
    int Left = 0b00000000000000000000000000000010;
    int Right = 0b00000000000000000000000000000001;
    int Result = 0b00000000000000000000000000000000;

    // 비트단위 연산자.
    // Not (비트 반전)
    Result = ~0;
    // and
    Result = Left & Right;  // 결과는 0
    // or
    Result = Left | Right;
    // xor 둘이 다를때만 true
    // 둘이 1로같든 0으로같든 같으면 false가 된다.
    Result = Left ^ Right;

    Result = Result << 3; // 비트를 왼쪽으로 3칸 밀어라
    
    // 이런식의 어떤일이 발생할지 알 수 없는 코드는 애초에 쓰지 않도록 합니다.
    Result = 1 << 33;
    Result = 1 >> 1;

    // CPU마다 결과가 다르게 나오는 코드는 생각도 하지말아라.

    // true와 false 참과 거짓의 명확한 의미.
    // 특정 메모리 영역의 비트가 전부 0이라면 false 와 거짓.
    // 특정 메모리 영역의 비트중 단 1개라도 1이 있다면 true 와 참.
    // 0 이외의 값은 모두 true가 됩니다.
    bool bResult = 2; // 참을 출력함.

    int Value = 20;
    // 복합 할당 연산자.
    // 특정 메모리 영역의 값을 기반으로 하는 이항 연산자.
    // 아래 두 코드는 같은 의미이다.
    Value = Value + 10;
    Value += 10;

}
