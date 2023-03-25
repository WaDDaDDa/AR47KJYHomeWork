#include <iostream>

class Player
{
public:
    int Value0;
    int Value1;
    int Value2;
    int Value3;
    int Value4;
    int Value5;
    int Value6;
    int Value7;

};

// 플레이어가 1마리도 없을 가능성이 있다면
void StatusRenderPtr(const Player* _Player)
{
    // 방어코드라고 합니다.
    if (nullptr == _Player)
    {
        return;
    }

    //_Player->Value0 = 20;

}

void Bomb(const int* _Bomb)
{
    if (nullptr == _Bomb)
    {
        return;
    }
}

// 플레이어가 1마리도 없을 가능성이 있다면
void StatusRenderRef(const Player& _Player)
{

}

int Value;

Player NewPlayer;

int ReturnFunction()
{
    return 10;
}

int& ReturnFunctionRef()
{
    int Value = 20;

    return Value;
}


Player NewPlayer;

void FunctionTest(int* _Ptr)
{

    NewPlayer.Value0 = 20;

    return;
}

int main()
{
    int TestValue = 20;

    FunctionTest(&TestValue);


    // ReturnFunctionRef() = 20;

    if (ReturnFunction())
    {

    }

    // 접근해서 수정할수 없다.
    int Value = ReturnFunction();
    if (Value)
    {

    }

    int Value = sizeof(Player);

    std::cout << "Hello World!\n";
}
