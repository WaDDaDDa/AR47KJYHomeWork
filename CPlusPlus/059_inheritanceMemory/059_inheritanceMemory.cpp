﻿#include <iostream>



class A
{
public:
    __int64 Test;

public:
    // 생성자
    A()
        : Test(10)
        // 초기화 메모리가 만들어지는 순간에 값을 입력하는 것이다.
        // 맴버이니셜라이저의 문법의 의미
        // 맴버변수의 메모리 생성을 여기서 하는 거에요.
    {
        printf_s("A 생성자\n");
    }

    // 소멸자
    ~A()
    {
        printf_s("A 소멸자\n");
    }
};

// 생성자호출에서 부모부터 생성되고 자식이 생성된다.
// 자식안에는 부모가 생성되어 있는것과 다름없다.
// 때문에 부모에서 선언한 값을 자식에서 이용할수있다.

// 반대로 소멸자호출에서는 자식이 먼저 사라지고 
// 부모가 사라지게 된다.

//  A생성자가 먼저 호출 -> B생성자 호출 -> B소멸자 호출 -> A소멸자 호출

class B : public A
{
public:
    char Value;
    // 생성자
    B()
        // : Test(20)
    {
        // 만들어지고 나서는 이용밖에 안됩니다.
        Test = 30;
        printf_s("B 생성자\n");
    }

    // 소멸자
    // 소멸자는 ~클래스 이름입니다. <= 다른 이름은 소멸자로 인정되지 않습니다.
    // 생성자와 비교해보면 직접 호출이 가능하지만 아무도 하지 않고
    // 무조건 이게 호출되면 이게 지워졌다고 생각할 것이기 때문에
    // 직접 호출한다고 메모리가 파괴되느냐? 안된다.
    // 소멸자에는 인자를 넣어줄수 없다.
    ~B()
    {
        Test = 20;
        printf_s("B 소멸자\n");
    }
};

int main()
{
    B NewB = B();

    // 호출할수는 있지만 메모리가 파괴되는것은 아닙니다.
    // 이걸 쓸수있는데 쓰는 사람은 못봤다.
    // 상식을 벗어난 행위로 봅니다.
    NewB.~B();

    int Value = sizeof(B);

    // 나머지 클래스 디폴트(아무것도 안했는데 되는것들)
    // 추상화 virtual 1차
    // 힙
    // 추상화 2차는 나중에 배울겁니다.
} // <= 실행흐름의 끝에서 벌어지는 일은?
