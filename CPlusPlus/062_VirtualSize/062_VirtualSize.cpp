#include <iostream>


class FightUnit
{
public:
	int GetAtt()
	{
		return Att;
	}

private:
	int Att = 10;
	int Hp = 100;
};

class Monster : public FightUnit
{

};

class BossMonster : public Monster
{

};

class Player : public FightUnit
{
public:
	int GetPlayerAtt()
	{
		return GetAtt() + Lv + Equip;
	}


private:
	int Lv = 1;
	int Equip = 1; // 장비
};

// 다형성을 표현하는 문법인 virtual은 보통 상속과 함께합니다.
// 다형성 == 상속 <= 쳐맞습니다.

// 내 게임에 있는 존재들끼리 싸울때 사용하는 함수
// 이런식으로 인자를 가지게 되면 추후에 새로운 class가 나온다거나 할때
// 그 클래스마다의 fightscene함수를 또 만들어야하고.
// 인자의 왼쪽 오른쪽에 따라 값이 바뀔수 있어지기 때문에
void FightScene(Player _Player, Monster _Monster)
{

}

// 이와 같은 문법으로 부모형의 주소를 받아서 사용하는 up캐스팅 을 사용하게된다.
void FightScene(FightUnit* _Player, FightUnit* _Monster)
{

}
//
//void FightScene(Player* _Player, Player* _Monster)
//{
//
//}
//
//void FightScene(Player* _Player, Npc* _Monster)
//{
//
//}
//
//void FightScene(Player* _Player, Boss* _Monster)
//{
//
//}
//


int main()
{
	Player NewPlayer;

	int A = NewPlayer.GetAtt();

	//int Value = sizeof(Test);

	//Test Arr[10];

	//Test* Ptr;

	//Ptr += 1;
}
