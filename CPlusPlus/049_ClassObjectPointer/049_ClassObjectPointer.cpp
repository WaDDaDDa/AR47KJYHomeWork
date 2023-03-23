#include <iostream>

class Player
{
public:
    void Damage(/*Player* const this*/)
    {
        // 
        // this

        /*this->*/Hp -= 20;  // 생략이 되어있던것들.
        printf_s("맞았습니다");
    }

public:
    int Hp = 100;
    int Att = 10;
};

//void Player::Damage(Player* const this)
//{
//    // 
//    // this
//
//    this->Hp = 20;
//    printf_s("맞았습니다");
//}



int main()
{

    // int가할수있는건 Player도 가능하다.
    // 안된다면 기능을 만들어주지 못한것. (자신이 원하는 대로 만들수있는 자료형인것이다.)
    // 없으면 없는데로 그것이 의도된 자료형인것.
    int Value = int();
    Player NewPlayer = Player();

    int* ValuePtr = nullptr;
    Player* NewPlayerPtr = &NewPlayer;

    // NewPlayerPtr = nullptr;
    NewPlayerPtr->Damage(/*NewPlayerPtr*/);

    // bPlayer::Damage(/*NewPlayerPtr*/);

    // ValuePtr = nullptr;
    // nullptr 익셉션이 납니다.
    // *ValuePtr = 20;      당연히 null에 값을 대입하려고 했기 때문에.

    // 단순히 NewPlayerPtr을 nullptr로 바꿔줫다고 에러가 나지는 않는다.
    // NewPlayerPtr = nullptr;
    // nullptr로 변한 NewPlayerPtr에 값을 넣어주려고하면 에러가 나는 것 이다.
    // NewPlayerPtr->Hp = 20;

}
