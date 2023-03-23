#include <iostream>

class Player
{
public:
    Player()    //  생성자
    {
    }

    void Damage(/*Player* const this*/ int _Att)  // 멤버 함수
    {
        // __int64 Address = (__int64) & Hp;
        // 눈에 보이지 않지만 맴버함수에는 
        // 첫번째 인자로 무조건 적으로 자기자신의 클래스의 포인터가 들어가게 됩니다.
        //  ( 생략이 되어서 눈에는 보이지 않을뿐.)
        // 이말은 멤버함수는 무조건 1개 이상의 인자가 포함되어있는 함수가 된다.

        // * const이기 때문에 this가 가리키는 대상은 바꿀수 없다.
        // this = nullptr; this의 값을 null로 바꾸는것인데 *const라서 오류.
        this->Hp -= _Att;  // 클래스의 포인터내의 값을 끌어낼때는 -> 사용한다.
    }

    inline int GetHp()   // 여기에도 눈에는 안보이지만. Player* const this 가 인자로 있는것.
    {
        return Hp;
    }

    inline void SetHp(int _Value)
    {
        Hp = _Value;
    }

    inline int GetAtt()
    {
        return Att;
    }

    inline void SetAtt(int _Value)
    {
        Att = _Value;
    }


protected:

public:
    int Hp = 100;
    int Att = 10;

};

// 300번지가 들어간다.
void GlobalDamage(Player* _this, int _Att)   // 전역함수를 만들었다.
{
    // 클래스를 포인터로 사용할때는
    // 내부에 있는 맴버변수에 접근하는 방식이
    // .이 아니고 ->로 변경된다.

    // 300번지에 있는 hp
    _this->Hp -= _Att;
}


// 200번지에 새로운 플레이어를 만든다.
// 포인터를 사용하지않고 그값만을 대입할 경우.
// 이 전역함수 내부에서 인자에 주어진 값을 대입한 완전히 새로운 Player를 생성하게 되고
// 이 전역함수 내부에서만 데이터가 변경되고 함수가 끝나는순간 사라지는 상황이 된다.
//void GlobalDamageValue(Player _NewPlayer, int _Att)
//{
//    // 클래스를 포인터로 사용할때는
//    // 내부에 있는 맴버변수에 접근하는 방식이
//    // .이 아니고 ->로 변경된다.
//    _NewPlayer.Hp -= _Att;
//}    // 함수에 갇힌 플레이어가 만들어진다.


// 500번지에 있는 4바이트 30 
void Test(int _Value)   // int와 Player는 다를것이 하나도 없다.
{                       // Player도 자료형의 일종이며 int가 되는데 Player로 안되는것은.
                        // 내가 만든 Player 자료형에 해당 기능을 구현을 시켜놓지 않은것뿐이다.
    _Value = 30128;
}

int main()
{
    // 700 번지에 있는 4바이트 30이죠?
    int Value = 30;
    Test(Value);  // 전역함수에 새로운 번지의 int에 30을넣고 함수를 실행시키때문에
    // main에 있는 Value에는 어떠한 영향도 줄수 없다.
    // 그렇기 때문에 주소값을 받아서 주소값에 접근하여 값을 주고 받는 포인터를 사용하는것.

    // 300
    Player NewPlayer0 = Player(); // NewPlayer0에 Player생성자를 통해 생성하고 대입한것.
    // NewPlayer0.Hp -= 20;

    Player(); // Player 생성자를 통해 생성만 한것.

    // 350
    Player NewPlayer1 = Player();

    // GlobalDamageValue(NewPlayer0, 20);
    // GlobalDamage(&NewPlayer0, 20);
    // 어떻게 각 객체들이 함수를 호출해서 자신의 멤버변수들을 알아서 잘찾아서 바꿀수 있을까?
    // 80
    NewPlayer0.Damage(/*&NewPlayer0,*/ 20); // 그이유는 멤버함수 인자에 주소값이 생략되어 있었기 때문.

    // GlobalDamage(&NewPlayer1, 50);
    // 50
    NewPlayer1.Damage(/*&NewPlayer1,*/ 50);

    //NewPlayer.SetAtt(100);
    //NewPlayer.SetHp(100);


}
