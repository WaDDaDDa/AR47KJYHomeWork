#include <iostream>

// 0 전사
// 1 마법사
// 2 궁수

// 라고 할때 숫자를 넣어서 보는게아니라 전사, 궁수, 이렇게 넣어서 그 직업을 바로 알수있게 하고싶음.
// enum을 사용한다.   컴파일 되면 int로 변형된다.
// 그냥 enum은 정수로 취급되는데
// 그것을 막기위해 enum class를 사용.
enum class GameJobType
{
    Fighter = 5,  //  0 값을 넣을수도 있음.  값을 넣었으면 다음순번그대로 따르게됨.
    Mage,     //  1     6 
    Archer,   //  2      7
    Paladin,  //  3       8
};

class FightUnit 
{
    // 직업
    // 앞으로 몇개 생길지 알수도없음.
    GameJobType JobType; // 
public:

    void SetJobType(GameJobType _JobType) // GameJobType의 형을 인자로 받는다.
    {
        JobType = _JobType;
    }

};


int main()
{
    // 직업이라는게 있다고 쳤을때,
    FightUnit NewUnit;

    // 보자마자 이유닛의 직업을 바로 알기 쉬움.
    NewUnit.SetJobType(GameJobType::Archer);

    int Value = Archer;   // enum의 단점은 int로의 형변이 아주 손쉽게 일어나기 때문에 문제야기할수있다
    // euum class 사용 하면 더 명시적으로 형을 따질수 있게된다.

}
