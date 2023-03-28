#include <iostream>

class Player 
{
    // 맴버함수뒤에는 const를 붙일수 있다.
public:       
    void SetHp(int _Value)     // SetHp는 값을 넣어주는 함수이므로 const를 사용하면 값을 넣을수 없게된다.
    {
        Hp = _Value;
    }

    int GetHp() const       // 어디서나 const의 의미는 사용한 값이 변하지 않음을 뜻한다.
    {                        // GetHp 함수를 불러올때 그결과가 값을 변경하면 안될때에 const를 사용한다.
        return Hp;
    }

    // 이함수를 호출한다고 해도
    // 이 클래스를 통해서 만들어진 객체는 변화하지 않을거야.

    // Player* const this 가 생략되어 있는걸   const를 붙이면.
    // const Player* const this 가 되는것 
    void PrintStatus(/*const Player* const this*/) const
    {
        // this;
        // 맴버함수 뒤에 const를 고치면 맴버변수를 고칠수 없다.
        // this->Att += 100;

        printf_s("플레이어의 능력치 ------------------------\n");

        printf_s("공격력 : %d\n", Att);

        printf_s("체  력 : %d\n", Hp);

        printf_s("----------------------------------------\n");
    }


protected:

private:
    int Hp = 100;
    int Att = 10;
};

int main()
{
    Player NewPlayer = Player();

    NewPlayer.PrintStatus();
    NewPlayer.PrintStatus();
    NewPlayer.PrintStatus();
    NewPlayer.PrintStatus();
}
