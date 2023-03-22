#include <iostream>

// 램의 메모리는 모두 램의크기만큼의 바이트를 가진 1차원 배열임.

int main()
{
    // 궁극적으로 모든 배열은 결국 1차원 배열입니다.

    // [1][2]
    // [3][4]

    // 0  0  1  1      
    // 0  1  0  1
    // [1][2][3][4]

    int ArrT[3][2] = { {}, {}, {} }; // 초기화.
        // 2개의 방을 가진 배열을 3개 만드는 것.  오른쪽에서 왼쪽으로 읽기

    int ArrTT[4][3][2] = {}; // 2개의방을 가진 배열이 3개있는 배열을 4개만들기.

    int Arr[2][2] = { {1, 2}, {3, 4} };

    __int64 Address00 = (__int64)&Arr[0][0];
    int Value00 = Arr[0][0];
    __int64 Address01 = (__int64)&Arr[0][1];
    int Value01 = Arr[0][1];
    __int64 Address10 = (__int64)&Arr[1][0];
    int Value10 = Arr[1][0];
    __int64 Address11 = (__int64)&Arr[1][1];
    int Value11 = Arr[1][1];
    int a = 0;
}
