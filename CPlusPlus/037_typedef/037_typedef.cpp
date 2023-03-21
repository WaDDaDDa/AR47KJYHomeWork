#include <iostream>

// typedef는 자료형의 이름을 내가 원하는 이름으로 바꿔서 사용할수 있게 해주는 것.
// 예를 들어 자료형의 이름이 너무 길거나 알아보기가 힘들다고 생각될때 사용해서 
// 편의성을 증진 시킬수 있지만. 컴파일 시간에 더욱 할애되는 단점 또한 존재한다.

// 이제부터 자료형  unsigned __int64를 size_t라고 부르겠다.
// typedef         unsigned __int64 size_t;
// unsigned __int64 == size_t

// 유저가 정의한 자료형이라고 부릅니다.
// 사용자 정의 자료형의 일종입니다.
// 모든 문법은 인간이 편해지기 위해서 만든것이다.

//typedef __time64_t time_t;
//typedef __int64                       __time64_t;


typedef int myint;   // int를 myint로도 사용하겠다고 선언함.

typedef myint mymyint;  // 위의 myint마저도 mymyint로도 사용하겠다고 선언함.

// int == myint == mymyint 가 되는 것.

// 둘의 효과는 똑같고 using 
// using 또한 typedef와 같으며 사용 법은 아래와 같다.
using MMInt = int;

int main()
{
    MMInt Ma = 30;

    // 지역변수 선언
    // 최초로 만들어진 시점.
    int Value = 20; 

    time_t DTime = time(0);
    Value = 20;
}
