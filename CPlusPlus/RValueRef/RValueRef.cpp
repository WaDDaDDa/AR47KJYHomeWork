

#include <iostream>
#include <string>
#include <vector>

// RValue Ref 
// 동적 할당에서 함수에 동적할당을 생성하고 그거를 그대로 받을때
// 두번 힙영역에 생성하고 삭제하고 하는것은 비효율적이므로
// 한번만 생성하고 그 생성한곳을 포인터로 가르키고 스택이 해제되면서 사라지면 효율적이다.

class A
{
    // private
public:
    std::string Name;
    std::vector<int> Values;

    void operator=(const A& _Other)
    {
        Name = _Other.Name;
        Values = _Other.Values;
    }

    A()
    {

    }

    A(const A& _Other)
    {
        Name = _Other.Name;
        Values = _Other.Values;
    }

};

void Test(const A& NewA)
{
    if (NewA.Name == "Fighter")
    {
        int a = 0;
    }
    int a = 0;
}

class NewTest
{
public:
    int Value;
    int* Ptr = nullptr;

public:
    void CreateBuffer()
    {
        Ptr = new int[500];
    }

    NewTest()
    {

    }

    ~NewTest()
    {
        if (nullptr != Ptr)
        {
            delete[] Ptr;
            Ptr = nullptr;
        }

    }

    NewTest(const NewTest& _Other)
    {
        int a = 0;
    }

    // 이동생성자
    NewTest(NewTest&& _Other) noexcept
    {
        int a = 0;
    }

    NewTest& operator=(const NewTest& _Other)
    {
        int a = 0;
        return *this;
    }

    // 지역변수에서 곧 사라질 변수를 인자로 받았다는것을 구분할수 있게 해주는
    // 함수가 곧 RValue 레퍼런스
    // &&는 RValue 
    // 이동대입
    // 상대의 권한을 이동받는다고 합니다.
    NewTest& operator=(NewTest&& _Other) noexcept
    {
        Ptr = _Other.Ptr;

        _Other.Ptr = nullptr;

        // 얕은 복사입니다.

        return *this;
    }

};

NewTest TestNew()
{
    NewTest NewValue;
    // NewValue.Value = 300;

    NewValue.CreateBuffer();
    return NewValue;
}


int Function()
{
    return 10;
}

std::vector<int> TestInt()
{
    return std::vector<int>{ 1, 2, 3 };
}

int main()
{
    {
        if (Function())
        {

        }

        // LValue RValue;

        int Test1 = 20;
        int Test2 = 20;
        Test1 = 30;

        Test1 = Test2;

        // int&& Test = Function();

        // &를 LValue Ref라고 부르고
        // RValue
        // 명확하게 위치가 있고 메모리를 특정할수 있어야 하는데.
        // int& Test = Function();

        // RValue 레퍼런스는 
        int&& Test = Function();


        // 대입할수 있고 메모리 영역을 특정할수 있는 메모리들을
        // LValue라고 합니다
        // LValue는 쉽게 RValue;

        // 사용하거나 참조할수만 있는 메모리들을 RValue라고 합니다.



        // RValue
        // Function() = 30;
    }

    {
        A NewA;
        NewA.Name = "Fighter";
        NewA.Values = { 1, 2, 3 };

        A NewA0;
        NewA0 = NewA;

        Test(NewA0);
    }

    {
        NewTest Test;
        Test = TestNew();

        NewTest TestRValue = TestNew();

        Test.Value = 3000;

        int a = 0;
    }

    {
        NewTest Test = NewTest();




    }

    {
        // RValue가 작동한다는 겁니다.
        std::vector<int> Test = TestInt();


        int a = 0;
    }

    std::cout << "Hello World!\n";
}
