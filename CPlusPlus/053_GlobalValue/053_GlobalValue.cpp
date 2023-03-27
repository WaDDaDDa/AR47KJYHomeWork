#include <iostream>

// C++은 객체지향 언어가 아니라는걸 확실히 설명할수 있다.
// 전역의 존재 때문입니다.

// 오직 클래스와 객체로만 코딩해야하는것이 객체지향이다.
// 객체를 지향하지 않으면 객체지향이 아니다.

// 플레이어만 사용해야함
// 다른클래스에서 쓰지마.
int Value = 0;            // 전역 변수를 사용하지 않는다면 위와 같은 주석은 필요가 없다.


// 클래스는 선언이고 어떻게 어떻게 이 객체가 쓰일거다라고 하는 설계도라고 했습니다.
int MonsterAllCountFunction()
{
    return 19;
}


class Monster
{
public:
    // 클래스에 속한 전역 함수가 된다.
    // 스태틱 맴버함수가 존재하고
    // static이 붙으면 클래스에 속한 전역 함수가 된다는 뜻.
    static int GetAllMonsterCount()
    {
        return MonsterCount;
    }

    int Hp;

    // 실체는 없고 선언만 둔것
    // void Print();

    Monster()
    {
        Value = 20;
        MonsterCount++;
    }


private:
    // static맴버변수라고 합니다.
    // 데이터 영역에 들어가야 하기 때문에
    // 현재까지 만들어진 모든 몬스터의 수 
    // 접근제한 지정자 private 몬스터만 사용할수 있는 전역변수가 됐다.

    // const를 붙이고 초기화까지 해주는 순간 이녀석은 완전한 변하지 않는 수가 된다.
    static int MonsterCount = 0;

    int Arr[3][3];
};

// 실체를 둔다.
// const int Monster::MonsterCount = 0;

class Player
{
public:
    void Damage()
    {
        Value = 20;
    }
};

// 

int main()
{
    // 몬스터가 관리하는 전역변수다.
    // 몬스터라는 속성에 속한 전역변수
    // Monster::MonsterCount = 3000;

    // 예를 들어 몬스터 객체를 생성할때마다 MonsterCount가 증가해야 한다면.
    // static을 통해 클래스 내부의 전역변수로 지정하지 않고 int MonsterCount = 0으로 선언한다면
    // 새로 생성되는 Monst객체마다 MonsterCount가 0인채로 생성될것이다.
    Monster NewMonster0;
    Monster NewMonster1;
    Monster NewMonster2;
    Monster NewMonster3;

    int Count = Monster::GetAllMonsterCount();

    // 사용하는데 일반맴버함수는 결국에는 객체가 필요하다. 
    // int Count = NewMonster3.GetAllMonsterCount();

    //NewMonster3.Print();

    std::cout << "Hello World!\n";
}
