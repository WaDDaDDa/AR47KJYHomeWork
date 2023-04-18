
#include <iostream>

// 이너 클래스. 
// 클래스안에 클래스를 만드는 것이다.

// 클래스 안에만 있을뿐 상속된것은 아니기때문에 둘은 어떠한 관련도 가지지 않는다.
// 하지만 이너클래스를 사용하면 
// 아래에 예시로는 Test클래스를 publicInner클래스의 네임스페이스처럼 사용할수있게 된다.


template<typename DataType>
class Test
{
public:
    // 이걸 이너클래스 문법이라고 하고.
    class publicInner
    {
    public:
        DataType InnerValue;

    public:
        publicInner()
        {
        }
    };

    //void Function() 
    //{
    //    InnerValue = 20;
    //}

private:
    // 이걸 이너클래스 문법이라고 하고.
    class privateInner
    {

    };

public:
    int Value = 0;
};

int main()
{
    Test<int>::publicInner Innter;
    // Test::publicInner

    std::cout << "Hello World!\n";
}
