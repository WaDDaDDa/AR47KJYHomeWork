#include <iostream>


// class 내부에는 아래처럼 보이지않지만 자동적으로 기능하도록 되어있는것들이 있다.
class MyValue
{
public:
    MyValue(int Value) {} // 디폴트 생성자.
    ~MyValue() {} // 디폴트 소멸자

    MyValue& operator=(const MyValue& _Other) = delete; // 디폴트 대입 연산자
    MyValue& operator=(const MyValue&& _Other) = delete; // 디폴트 대입 연산자
    MyValue(const MyValue& _Other) = delete; // 디폴트 복사 생성자
    MyValue(const MyValue&& _Other) = delete; // RValue 복사 생성자
    //  delete를 통해 자동으로 만들어진기능들을 사용하지 않겠다고 할수있다.

    //  현 수업에 있어서 class 디폴트를 해당 처럼 할 것이며.
    //  class를 활용함에 있어 필요해진다면 필요할때 직접 만들어서 사용하는것으로 모두와 합의.
protected:

private:

    // public:
    // A& operator=(const A& _Other) {}
    // 디폴트 대입연산자가 존재합니다.
    // A& operator=(const A&& _Other) {} // RValue 대입연산자가 존재합니다.

    // public:
    // A() {} // 디폴트 생성자.
    // A(const A& _Other) {} // 디폴트 복사 생성자
    // A(const A&& _Other) {} // RValue 복사 생성자
    // ~A() {} // 디폴트 소멸자
};

class A
{
    // private: // 디폴트 접근제한 지정자
    int A;

    // public:
    // A& operator=(const A& _Other) {}
    // 디폴트 대입연산자가 존재합니다.
    // A& operator=(const A&& _Other) {} // RValue 대입연산자가 존재합니다.

    // public:
    // A() {} // 디폴트 생성자.
    // A(const A& _Other) {} // 디폴트 복사 생성자
    // A(const A&& _Other) {} // RValue 복사 생성자
    // ~A() {} // 디폴트 소멸자
};

int main()
{
    // 디폴트 생성자.
    {
        A NewA0 = A();
        A NewA1 = A(NewA0);
        NewA1 = NewA0;
        NewA0.~A();
    }

    {
        MyValue NewA0{ 1 };


        // MyValue NewA0 = MyValue();
        //MyValue NewA1 = MyValue(NewA0);
        //NewA1 = NewA0;
    }

}
