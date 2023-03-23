#include <iostream>

class Weapon
{
public:
	int Att = 200;

public:
	Weapon()
	{
		int a = 0;
	}
};

class Potion
{
public:
	int Heal = 100;

public:
	Potion()
	{
		int a = 0;
	}
};


class Player
{
public:
	// 리터럴 초기화라고 부르는 초기화 방식을 이용할수 있다.
	// 11 이전에는 안됐던 방식이고 회사에서 사용하지 않을수도 있습니다.
	int Hp = 20;
	int Maxatt = 20;
	int MinAtt = 20;
	int PDef = 20;
	int MDef = 20;
	int Crit = 20;
	Weapon PlayerWeapon = Weapon();
	Potion PlayerPotion = Potion();

	void TestFunction()
	{

	}

public:
	// 생성자는 무조건 클래스 이름과 완전히 동일해야 합니다.
	// 생성자는 객체를 만들어 내는 멤버함수인데 여러가지 일반함수와는 다른 예외점이 존재한다.
	// 1. 리턴값이 없다. => 리턴값이 당연히 그 클래스의 객체이기 때문
	// 2. 객체없이 호출가능하다. => 일반적인 클래스의 함수는 무조건 객체가 필요한다.
	//                          객체를 만들어내야하는 함수가 객체를 필요로하면 모순.
	// 맴버이니셜라이저라는 문법을 사용할수 있습니다.
	// 리터럴 초기화와 맴버이니셜라이저 중에서
	// 리터럴이 먼저 적용되고 그 후에 멤버이니셜라이저가 적용되기 때문에
	// 멤버이니셜라이저 값이 있다면 그 값이 최종적으로 적용된다.
	
	// 아래와 같은 문법이 멤버이니셜라이저 이다.
	///*Player*/ Player(int Value)
	//	//: Hp(30)
	//	//, Maxatt(30)
	//	//, MinAtt(30)
	//	//, PDef(30)
	//	//, MDef(30)
	//	//, Crit(30)
	//{  
	//	// 이건 대입 이다. 생성과 대입의 차이는 프로그래머들이 정말 꼼꼼하게 신경쓰는 차이이기 때문에
	//	Hp = 30;        // 대입과 생성은 완전히 다른것이다.
	//}

	Player(int _Value0, int _Value1)
	{

	}
};

void Test(const Player& _Player)
{

}

int main()
{
	// 생성자는 기본적으로 함수로 인식됩니다.

	// 클래스를 내가 만들었는데
	// 내가 정의하지 않는 행동을 할수 있다면 그건 컴파일러가 그렇게 한거다.
	//  = ) 생략되어서 일어나는 일들이 존재 한다는 것.
	// 그리고 그건 내눈에 생략된거다.
	// Player NewPlayer = Player(20, 30);

	// 이걸 리스트 이니셜라이저 문법이라고 합니다.
	Player NewPlayer = { 20, 30 };

	// Player NewPlayer = Player{ 20, 30 };

	// int Value = int(20);

	// 아래와 같이 사용할수가 없다.
	// Player::TestFunction();

	// 전역함수처럼 그냥 함수쓰듯이 사용할수는 없어요.
	// 클래스의 맴버함수는 무조건 객체를 필요로 합니다.   ---- 중요
	// 하지만 이 제약에서 벗어난 함수가 2종이 존재하는데
	// 그중 1종이 생성자이다.
	// 생성자는 객체를 만들어내는 전역함수를 의미합니다.
	NewPlayer.TestFunction();

	// 닭이먼저냐 달걀이먼저냐 문제가 생긴다.


}
