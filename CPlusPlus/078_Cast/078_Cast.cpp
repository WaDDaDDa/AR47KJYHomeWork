
#include <iostream>

// 캐스팅에는 크게 4가지 종류가 있다.


class A
{
    virtual void Test() {}
};
// 1. 다향성을 이용한 virtual, override.
class B : public A
{
    int Hp;
    int Att;
    // virtual void Test() {}
};

class C : public A
{
    int Hp;
    int Def;
    // virtual void Test() {}
};


int main()
{
    // static_cast 메모리 크기만 다른 값대 값형식의 형변환에 사용된다.
    {

        // 2.  암시적 형변환, 명시적 형변환.
        short Test = 20;
        // c스타일 형변환
        int Value = (int)Test;
        // c++에서는 별로 권장하지 않는 방식이다.

        // 메모리 크기만 다를뿐 서로 값형태

        //  3. static cast 암시적, 명시적 형변환과 다르게 런타임이 빠르다.
        // C스타일의 형변환보다 빠르다.
        Value = static_cast<int>(Test);
        Value = /*static_cast<int>(*/Test/*)*/;
        Value = (int)Test; // <= static_cast<int>로 바꿉니다.
    }


    // 4. reinterpret_cast
    // 정수를 포인터로 포인터를 정수로 변경할때 사용한다.
    // 연관성이 없는 포인터 타입을 변환하기 위해서 사용.
    {
        int Value = 3;

        int* Ptr = &Value;

        __int64 Address = reinterpret_cast<__int64>(Ptr);

        __int64 Address3 = (__int64)Ptr;

        int* Ptr2 = reinterpret_cast<int*>(Address);
    }

    // dynamic_cast
    // 부모자식구조에서 사용됩니다. 다운캐스팅에 이용됩니다.
    {
        // 가상함수 테이블을 참조해서 다운캐스팅이 가능한지를 알아봐준다.
        //A NewA;
        //B NewB;

        //A* PtrA = &NewA;
        //B* PtrB = &NewB;

        {
            A* PtrB = new B();
            B* Test = dynamic_cast<B*>(PtrB);
            int a = 0;
        }

        {
            // 다운캐스팅을 안전하게 할수 있게 도와준다.
            A* PtrC = new C();
            B* Test = dynamic_cast<B*>(PtrC);

            // 이러면 심각한 오류가 생길수 있다.
            B* Test1 = (B*)PtrC;
            int a = 0;
        }

    }

    // const_cast 존재만 한다.
    {

    }



    std::cout << "Hello World!\n";
}
