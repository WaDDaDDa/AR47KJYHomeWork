// 32_Switch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // case n:   <- n에는 상수 메모리만 올수 있습니다.

    int Check = 0;

    // if(메모리) 메모리영역이 참인지 거짓인지를 판단해서 코드를 실행해주는 
    // 조건문이에요.

    // switch(메모리)영역과 완전히 같은 상수 메모리가 있는지 비교해주는 
    // 조건문이고.

    const int CheckValue = 0; // 상수화를 통해 변수도 넣어줄수는 있습니다.

    int Value = 0;
    switch (Value)
    {
        // case Check:
    case CheckValue:
    {
        int a = 0;
        printf_s("Value 0");
        break;      //break를 만나면 switch문에서 탈출하게 됩니다.
    }               //break가 없으면 그다음 case도 실행하게 되므로 상황에 맞게 사용할것
    case 1:
    {
        printf_s("Value 1");
        break;
    }
    case 2:
    {
        printf_s("Value 2");
        break;
    }
    case 3:
    {
        printf_s("Value 3");
        break;
    }
    default:
    {
        printf_s("Value not");
        break;
    }
    }

    char InputKey = 'A';

    switch (InputKey)
    {
    case 'a':
    case 'A':
        printf_s("에이를 쳤습니다."); // a, A어떤것을 치든 실행되게하는 방법.
        break;
    default:
        break;
    }
}
