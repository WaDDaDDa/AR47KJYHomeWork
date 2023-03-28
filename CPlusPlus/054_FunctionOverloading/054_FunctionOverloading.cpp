#include <iostream>

// 함수 오버로딩이란.
// 함수의 이름이 같아도 뒤따라오는 인자에따라 이름이 다른것으로 취급한다.
// 인자까지 합쳐서 이름이라고 생각하면 편하다.

void Function()
{
    printf_s("void Function()\n");
}

// Functionint
void Function(int _Value)
{
    printf_s("void Function(int _Value)\n");
}

void Function(short _Value)
{
    printf_s("void Function(short _Value)\n");
}

void Function(int _Value, int _Test)
{
    printf_s("void Function(int _Value, int _Test)\n");
}

// 저는 이런 오버로딩을 좋아하지 않지만 
void Function(short _Value, int _Test)
{
    printf_s("void Function(short _Value, int _Test)\n");
}

// 함수라고 불리는 녀석들에게는 모두 적용된다.
// 클래스 내부의 생성자 함수또한 적용할수있다.
class Player
{
public:

    void Function()
    {
        printf_s("void Function()\n");
    }

    // Functionint
    void Function(int _Value)
    {
        printf_s("void Function(int _Value)\n");
    }

    void Function(short _Value)
    {
        printf_s("void Function(short _Value)\n");
    }


    void Function(int _Value, int _Test)
    {
        printf_s("void Function(int _Value, int _Test)\n");
    }

    // 저는 이런 오버로딩을 좋아하지 않지만 
    void Function(short _Value, int _Test)
    {
        printf_s("void Function(short _Value, int _Test)\n");
    }

public:
    Player()
    {
    }

    Player(int Value0)
    {
    }

    Player(int Value0, int Value1)
    {
    }

    //Player(int Value0, int Value1)
    //{
    //}
};

int main()
{
    int A = 'a';
    short B = 'a';

    Function('a');

    Function();
    Function((short)10, 10);

    Player NewPlayer0 = Player(10, 20);
    Player NewPlayer1 = Player();
    Player NewPlayer2 = Player(10);

    NewPlayer0.Function(10, 20);
    NewPlayer0.Function(10);
    NewPlayer0.Function();
}
