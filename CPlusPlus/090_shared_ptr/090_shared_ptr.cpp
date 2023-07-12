

#include <iostream>
#include <memory>

class Monster 
{
public:
    int Value0;
    int Value1;
};

// 동적할당한 포인터 1개당
// int를 1개 쌍으로 만들어주는것.

// 약식으로 구조를 만들어 보겠습니다.
// std::shared_ptr

// 만들줄 안다고 말하거나
// 내부구조를 

// 포인터를 사용할때 new와 delete구조를 안전하게 사용할수있게 도와주는 std::문법이다.

template<typename PtrType>
class myshared_ptr 
{
public:
    //함수도 friend걸수 이씁니다.
    // 근데 안함 템플릿 함수 friend 걸기 싫음
    // friend myshared_ptr<PtrType> mymake_shared();

public:
    int* RefCount = 0;
    PtrType* Ptr = nullptr;

    ~myshared_ptr() 
    {
        --(*RefCount);
        if (0 >= *RefCount)
        {
            delete RefCount;
            delete Ptr;
        }
    }

    myshared_ptr()
    {

    }

    void operator=(nullptr_t _Ptr) 
    {
        --(*RefCount);
        if (0 >= *RefCount)
        {
            delete RefCount;
            delete Ptr;
        }

        RefCount = nullptr;
        Ptr = nullptr;
    }

    myshared_ptr(const myshared_ptr<PtrType>& _Other)
    {
        Ptr = _Other.Ptr;
        RefCount = _Other.RefCount;
        ++(*RefCount);
    }
};

template<typename PtrType>
myshared_ptr<PtrType> mymake_shared()
{
    myshared_ptr<PtrType> Return;
    Return.Ptr = new PtrType();
    Return.RefCount = new int();
    (*Return.RefCount) = 1;
    return Return;
}

class A
{
public:
    std::shared_ptr<class B> Ptr;
};

class B
{
public:
    std::shared_ptr<class A> Ptr;
};

// 순환 참조의 문제입니다.
// 헤더 순환참조랑 동일하다.
// A를 빌드하려면 B의 헤더필요한데
// B를 빌드하려면 A의 헤더가 필요하다.

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 당연히 릭이 남게된다.
    // Monster* Ptr = new Monster();

    // 이제 포인터를 사용하는것이 아니다.
    // Monster*
    // std::shared_ptr<Monster>

    // new Monster
    // => std::make_shared<Monster>();

    // 어떤 특정 동적할당된 주소값을 가지고 있는 포인터가 없어진다면
    // 알아서 지워주고
    // 문제아닌 문제인데 단 1개의 std::shared_ptr<Monster>남아있다면
    // 절대로 지워지지 않는다. 
    std::shared_ptr<Monster> MonsterPtr0 = std::make_shared<Monster>();


    myshared_ptr<Monster> MonsterPtr1 = mymake_shared<Monster>();
    // 1
    myshared_ptr<Monster> MonsterPtr2 = MonsterPtr1;
    // 2

    // 더이상 사용하지 않겠다고
    // delete를 한것이고 이상황에서 레퍼런스 카운트가 0이되면 
    MonsterPtr2 = nullptr;
    MonsterPtr1 = nullptr;

    // 1
    std::shared_ptr<A> PtrA = std::make_shared<A>();
    // 1
    std::shared_ptr<B> PtrB = std::make_shared<B>();

    // PtrB = 2
    PtrA->Ptr = PtrB;
    // PtrA = 2
    PtrB->Ptr = PtrA;

}
