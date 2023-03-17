#include <iostream>

void MyPrintf_Test1(const char* const _ptr)
{
    putchar(_ptr[0]);   // putchar 문자 1개를 출력하는 함수.
    putchar(_ptr[1]);
    putchar(_ptr[2]);

}

void MyPrintf_Test2(const char* const _ptr)
{
    int Count = 0;
    while (0 != _ptr[Count])
    {
        char Ch = _ptr[Count];
        // 바로 putchar(_ptr[Count]) 하지 않는 이유는
        // 변수를 만들어서 _ptr[Count]에 실제 어떤값이 들어오나
        // 직접 눈으로 확인하는 습관을 만들어 놓는게 좋다.
        putchar(Ch);
        Count += 1;
    }
}

void MyPrintf_Test3(const char* const _ptr, ...) //가변인자에 접근 하려면 8바이트 단위로
// 읽어 내야한다.
{
    int count = 0;
    char CH = 0;
    while(CH = _ptr[count], 0 != CH)
    {
        putchar(CH);
        ++count;
    }
    CH = _ptr[25]; 
    putchar(CH);
}




int main()
{
    
    MyPrintf_Test1("ads235"); // 이경우엔 정해진 문자수만큼 putchar 함수를 계속 써놔야하며 
    // 써놓은 putchar 함수의 수보다 많은 글자를 받지 못하게 된다.

    MyPrintf_Test2("ads154"); // while 반복문을 적용시켰을때.

    MyPrintf_Test3("abcdefgh", "12345678"); // 100번지에 a가 있다면. 
    // 101번지 a
    // 102번지 b
    // 103번지 c
    // 104번지 d
    // 105번지 e
    // 106번지 f
    // 107번지 g
    // 108번지 h
    // 109번지 0   < -- while문 종료.  다음인자를 찾으려면 8바이트 떨어진 117번지에서 3이 시작
    // 되어야 맞다고 생각했는데. 없음.  
    // 추측 1 : 코드영역에 abcdefgh가 만들어져서 
    // 추측 2 : 애초에 인자에 접근하는 바이트 계산을 잘못해서.

    int a = 0;
    
}

