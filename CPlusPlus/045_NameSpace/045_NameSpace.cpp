#include <iostream>

// 범위 확인
namespace AProgramer  // 네임스페이스 Aprogramer 안에있는 클래스 item 과
{
    class Item
    {

    };
}

namespace BProgramer  // 네임스페이스 Bprogramer 안에있는 클래스 item은 서로 다르다.
{
    class Item
    {

    };

    namespace UseEl   // 네임스페이스 안에 또 네임스페이스 할수있다.
    {
    }
}

namespace BProgramer  // 같은 네임스페이스를 떨어트려서 쓸수는 있으나.
{                     // 같은 네임스페이스 안에 선언되는 변수명들은 같을수 없다.
    class Player
    {
    };
}

namespace std    // C++ 스탠다드인 std를 네임스페이스로 사용할수있으나 절대하면 안된다.
{
    void TestFunction()
    {

    }
}

// 실제적으로 플레이어의 스펙이나 만들어질대의 내용들은 코드영역에 들어가 있게 된다.
// 플레이어가 만들어지면 내부에 int Att를 하나 가지고 있어야 해... 라는 명령이 코드영역에 있는것.
class Player
{
public:
    int Att;
};

class Monster
{
public:
    int Att;
};

void Test()
{
    int Att;
};

// 절대로 사용하지 않습니다.
using namespace AProgramer;
// Namespace를 생략할수 있다면 생략해라.
using namespace BProgramer;
// 네임스페이스를 사용하여 구분하는 의미가 사라지므로 해야할 이유가 전혀 없다.

int main()
{

    // ::      Namespace 안에 있는 변수를 불러올때 사용하게 된다.

    // Player::Att;    Player안에있는 Att
    // Monster::Att;   Monster안에있는 Att

    // 
    //BProgramer::Item NewItemB;
    //AProgramer::Item NewItemA;

    BProgramer::Item NewItemA;
    AProgramer::Item NewItemB;

    int Value = 20;
    // std c++ 스탠다드의 약어
    // c++공인이다.
    // c++만든 사람들이 품질 보증한 객체 혹은 클래스 혹은 모든 코드적 요소들

    // std::TestFunction();

    std::cout << "Hello World!\n";
}
