// 055_ClassDeclaration.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 순환 참조라고 합니다.
// 조심해야 합니다.
// 순환참조를 해결하는 방법은
// 선언과 구현의 철저한 분리 입니다.

// Monster라는 클래스가 있을거야 믿고 써.
// 내용은 나중에 알려줄께.
// 클래스 전방선언이라고 부릅니다.
// 전방선언을 한다음에 이후에 클래스에 정보가 있을것이다.
// 단. 전방선언을 한 클래스를 사용함에 있어 그 클래스 내부의 정보를 알아야하는 코드가 있다면 
// 전방선언으로 해결이 불가능하다. (메모리 할당에 있어서 선언한 클래스의 크기를 알아야할때 문제가 됨.)
class Monster;
class Player
{
public:
    int Att = 10;
    int Hp = 100;

public:
    // 이건 몬스터가 있을거야.... 라는 뜻이 아니고
    // 몬스터를 알아야 한다
    // void Attack(Monster* _Monster);

    // 내부에서 Monster의 내용을 사용하게 되면
    // 전방선언으로도 해결이 안된다.
    // Monster가 Hp를 가지고 있는지 알아야겠다. <= 컴파일러가.
    void Attack(Monster _Monster);
    //{
    //    // 몬스터는 Hp를 가졌어?
    //    // 몬스터의 크기는 얼마야?
    //    // 몬스터는 어떤 생성자를 가지고 있어.
    //    _Monster->Hp -= 10;
    //}

    // 전방선언을 해도 해결이 되는 경우가 존재한다.

    // 8바이트 주소값을 받아서 외부로 8바이트주소값을 리턴하기만 하면 되는 함수다.
    // Monster 내부의 맴버변수나 맴버함수를 사용하지 않았기 때문에 필요가 없다.
    Monster* Test(Monster* _NewMonster)
    {
        return _NewMonster;
    }

    // 함수의 실행메모리를 정하려면? 함수의 인자의 크기를 알아야 합니다.
    // Monster의 크기를 알아야 한다.
    // Monster의 크기는 뭐에의해서 결정되죠? 맴버변수들의 개수와 종류로 결정된다.
    //Monster Test2(Monster _NewMonster)
    //{
    //    return _NewMonster;
    //}


};

class Player;
class Monster
{
public:
    int Att = 10;
    int Hp = 100;

public:
    void Attack(Player* _Player);
    //{
    //    _Player->Hp -= Att;
    //}

};

int main()
{
    Player NewPlayer;
    Monster NewMonster;

    NewPlayer.Attack(NewMonster);
    NewMonster.Attack(&NewPlayer);

    NewPlayer.Test(&NewMonster);

    //NewPlayer.Test2(NewMonster);

    std::cout << "Hello World!\n";
}

void Player::Attack(Monster _Monster)
{
    _Monster.Hp -= Att;
}

void Monster::Attack(Player* _Player)
{
    _Player->Hp -= Att;
}