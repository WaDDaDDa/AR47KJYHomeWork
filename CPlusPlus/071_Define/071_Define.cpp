
#include <iostream>
#include <assert.h>

#define TEN 10     // 앞으로 TEN은 오른쪽에 엔터가 나오기전까지 전부로 치환시킨다.

// 함수형으로 사용하는 것
// 매크로함수라고 하는데 
// 매크로함수는 무조건 그냥 복붙입니다.
#define PLUS(Value1, Value2) Value1 + Value2

#define MYTEST(Value1) Value1 = 0;

// 함수의 경우에는 일반적으로 형에 대한 검사나
// 자료형에 의한 컴파일 체크를 하지만
inline void Test(int _Value)
{
    _Value = 0;
    assert(false);
}

// inline 함수와의 차이는 자료형을 컴파일러가 체크해주냐 안해주냐의 차이로 안전하게 사용할수
// 있는것은 inline쪽이지만 define은 그것대로 다른 활용이 가능하기 때문에 둘다 알아야 한다.


int main()
{
    int* Ptr;

    MYTEST(Ptr)

        // Test(Ptr);

        // 대부분 디파인 보다 인라인을 사용하라고 합니다.
        // _Value = 20;

        // PLUS("aaaaa");

        // "aaaaa" + "aaaaa";

        //int* Ptr;
        //Test(Ptr);

        TEN* TEN;
    // TEN * TEN
    // 10; * 

    std::cout << "Hello World!\n";
}
