#include <iostream>

// 구현이라고 하는 문법은
// 선언과 함수체를 같이 놓은 문법을 구현된 함수라고 부릅니다.
// 함수 선언만 따로 놓을수가 있다.


// 이러이러한 함수가 있을거야.
// 일단 믿고 호출하고 컴파일해줘.
// 구현은 분명히 나중에 있을거야.
void Function0(/*int _Value*/);
void Function1();

// 전역함수의 경우에는 선언은 몇개를 해도 상관 없다.
void Function2();
void Function2();
void Function2();
void Function2();
void Function2();
void Function2();
void Function2();

// 클래스는 문법상 선언과 구현이 내부에서 혼재되어있을수도 있고
// 아닐수도 있는 특이한 놈이라서
// 클래스 자체는 2개를 선언할수는 없습니다.
class Player
{
public:
    // static 맴버 변수의 경우에는 const가 붙으면 구현체를 따로 둘수 없어요
    // 리터럴 초기화가 가능하다.
    // 상수로 생각해서 코드영역에 위치시키기 때문이다.
    // 앞으로 Player::GValue0은 다 0으로 바꾼다.

    // 어차피 내가 지금 읽었을대 0이라는걸 읽었으니 이건 앞으로 절대 안바뀔거잖아?
    // const고? 그러니까 앞으로 GValue 이 보면 그냥 0인거네
    // 그럼 컴파일러인 나는 다 exe파일 만들때 GValue 0이 보면 다 0으로 만들어버려야지.
    static const int GValue0 = 3;
    int Arr[GValue0];
    // static 맴버 변수의 경우에는 const가 안붙으면 이녀석은 데이터영역에 위치하게 되고
    // 선언으로만 치게 되고 리터럴 초기화가 불가능해진다.
    // Player에 속한 static 전역변수인 GValue1가 있을거야...
    // 선언만 한다음에 초기화는 따로 진행하도록.
    static int GValue1 /*= 0*/;

private:
    // static함수의 경우 맴버함수와 동일한 규칙을 적용한다.
    static void GlobalFunction()
    {

    }

public:
    // 일반적인 맴버변수는 이미 그자체로 선언이면서 구현입니다.
    // 따로 실체를 둘 필요가 없다.
    int Hp;

public:
    // 클래스 내부에서 구현을 해버리면
    // 이 함수는 구현까지 끝난것으로 보고
    // 외부에서 구현해주면 똑같은 함수를 2개 구현한것으로 봅니다.
    void StatusRender()
    {

    }

    // 클래스내부의 함수는 별개로 선언만 놔둘수 있다.
    void Damage();

public:
    // 클래스내부의 함수는 별개로 선언만 놔둘수 있다.
    Player();

   // Monster* NewMonster;
};

// 이게 실체라는 겁니다.
// const가 아닌 static 데이터영역에 마련되고 문법적으로 실체를 마련해줘야 한다는겁니다.
// 그놈이 여기있어...  클래스에서 선언한 static int GValue1 값의 초기화.
int Player::GValue1 = 10;

// const int Player::Value = 0;

//void Player::StatusRender()
//{
//
//}

// 맴버함수의 FullName은 무조건
// 클래스명::함수이름 으로 인식해야 한다.
void Player::Damage()
{

}

// 
Player::Player()
{

}

class Monster
{

};

int main()
{
    int a = 0;
    Player::GValue1 = 20;

    Function0();

    Player::GValue1 = 30;
    Function1();
    Function2();

    std::cout << "Hello World!\n";
}

void Function1()
{
}
void Function2()
{
}
void Function0()
{
}
