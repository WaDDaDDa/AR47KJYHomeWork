#include <iostream>

// virtual이 붙어있는 클래스가 존재한다면
// 이 클래스의 객체가 생성될때.
// void(*__vfptr[???])() <= 가상함수 테이블이라고 합니다.
// 
// 함수포인터의 배열을 만들어내고 그걸 함수포인터의 포인터로 저장합니다.
// void(**__vfptr)()

// 가상함수는 주소값을 받는다.
// 가상함수를 사용한다는 것은 함수포인터를 사용하고 있는것이다.
// 가상함수를 선언하게 되면. 주소값을 가지는 배열형으로 공간을 만들어서 할당하게 된다.
// 그래서 클래스내에 가상함수가 1개있든 여러개가 있든 8바이트의 크기를 가지게 된다.
class FightUnit
{
public:
    virtual void Damage()
    {

    }

    virtual void FightStatusRender()
    {

    }

public:
    FightUnit()
        // [0]FightUnit::Damage
        // [1]FightUnit::FightStatusRender
    {
        this;
        int a = 0;
    }
};

class Player : public FightUnit
{
public:
    void Damage() override
    {

    }

    virtual int Heat()
    {
        return 1;
    }

    //void FightStatusRender() override
    //{

    //}

public:
    Player()
        // [0]Player::Damage
        // [1]FightUnit::FightStatusRender
    {
        this;
        int a = 0;
    }
};

class Fighter : public Player
{
    // public:
    // Fighter() {
        // [0]Player::Damage
        // [1]FightUnit::FightStatusRender
    // 

};

int main()
{
    int Value = sizeof(Player);

    Player NewPlayer;

}
