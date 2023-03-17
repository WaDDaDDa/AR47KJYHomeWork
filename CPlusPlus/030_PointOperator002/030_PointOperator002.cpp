#include <iostream>

int main()
{

    int Value = 0;   //  4바이트 정수 

    __int64 Address = 0;  //  8바이트 정수

    // 100번지
    int* Ptr = &Value;    

    // 나의 주소값을 100번지 + sizeof(int) * 1;
    // 포인터 변수에 + - 연산을 하면 랜덤인덱스 형태로 쓸수있다.

    Address = (__int64)Ptr;
    Ptr = Ptr + 1;               //  Ptr[0] + 1 의 형태인것.
    Address = (__int64)Ptr;
    Ptr = Ptr - 1;
    Address = (__int64)Ptr;
    Ptr += 1;
    Address = (__int64)Ptr;
    Ptr = Ptr + 5;
    Address = (__int64)Ptr;
}
