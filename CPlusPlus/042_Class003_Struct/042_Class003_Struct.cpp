#include <iostream>

class Player
{
    // private: 디폴트 접근제한 지정자
private:
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
};

struct Monster
{
    // public: 디폴트 접근제한 지정자
private:
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
};

// class   와   struct 의 차이는 오로지 기본 접근제한 지정자가
// private 인지 public 인지의 차이 밖에 없다.   
// 그외의 모든것이 동일 하다.

int main()
{
    Player NewPlayer;

    Monster NewMonster;

}
