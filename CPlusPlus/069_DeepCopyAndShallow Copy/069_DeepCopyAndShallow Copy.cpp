
#include <iostream>

class A
{
public:
    int* NewInt = nullptr;

    void Create()
    {
        NewInt = new int();
    }

    void operator = (const A& _Other)
    {
        // 이걸 얕은 복사라고 하게 된다.
        // NewInt = _Other.NewInt;
        if (nullptr == _Other.NewInt)
        {
            //if (nullptr != NewInt)
            //{
            //    delete NewInt;
            //    NewInt = nullptr;
            //}
            return;
        }

        if (nullptr == NewInt)
        {
            // 딥카피의 준비를 한것.
            Create();
        }

        // 각클래스가 자신만의 메모리를 만들어야 한다는 것이다.
        *NewInt = *_Other.NewInt;

        return;
    }


public:
    ~A()
    {
        if (nullptr != NewInt)
        {
            delete NewInt;
            NewInt = nullptr;
        }
    }
};

int main()
{
    {
        A NewInt0;
        A NewInt1;

        NewInt0.Create();

        NewInt0 = NewInt1;
    }

    //           100
    int* NewInt0 = new int();

    //           100
    int* NewInt1 = NewInt0;

    if (nullptr != NewInt0)
    {
        delete NewInt0;
        NewInt0 = nullptr;
    }

    // ???????? NewInt1

    if (nullptr != NewInt1)
    {
        delete NewInt0;
        NewInt0 = nullptr;
    }

    std::cout << "Hello World!\n";
}
