#include <iostream>
#include <conio.h>
#include <Windows.h>

// 자체 HomeWork.   저번 숙제를 클래스의 전방선언과 함수 의 선언과 분리를 적용시켜 보자.
// 보통 함수의 선언은 main 위에서 하고 구현은 main아래에 표현하게 된다.
// 클래스 전방선언
class int2;
class ConsoleGameScreen;
class Player;
class Block;
class Bomb;

class int2
{
public:
	int2(int _X, int _Y);

	int X = 0;
	int Y = 0;

	int2 Half() const;

	int2 Half3() const;
};

class ConsoleGameScreen
{

private:
	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;     // 클래스 내부에 본인의 클래스 선언 가능.
	// 본인의 클래스를 전역으로 선언함
    //얻는 이점은 여러가지가 있는데 여기서 선언한 MainScreen을 여기저기 값을 넣어줄수있음.

public:
	// 메모리 영역 자체가 달라졌다고 봐야합니다.
	static ConsoleGameScreen& GetMainScreen();
	
	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	// Map 크기/
	static const int ScreenYSize = 20;
	static const int ScreenXSize = 10;

	static int2 GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
	// 배열 바깥이면 true를 반환한다.
	bool IsScreenOver(const int2& _Pos) const;
	
	void SetScreenCharacter(const int2& _Pos, const char _Ch);

private:
	static char Arr[ScreenYSize][ScreenXSize];

};


class Block
{
public:
	Block();

	int2 GetPos() const;

	void SetPos(const int2& _Value);

	bool IsBlockOver(const int2& _Pos) const;

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);
};

class Bomb
{
public:
	Bomb();

	static Bomb FirstBomb;

	int2 GetPos() const;

	void SetPos(const int2& _Value);

	bool IsBlockOver(const int2& _Pos) const;

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);
};

/////////////////////////////////////////////////////////////////// 엔진

// 2단계 컨텐츠
// 클래스가 다른 클래스를 알아야 합니다.
class Player
{
public:

	char CH = 0;

	int2 GetPos() const;

	void SetPos(const int2& _Value);

	void InputKey(const Player& _Player);

	void Move(Player& _Player, ConsoleGameScreen& _Screen, Block& _Block);

	void CreateBomb(Bomb& _Bomb);

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);
};

//ConsoleGameScreen내부에 선언된 MainScreen을 전역에 ConsoleGameScreen자료형으로 선언한것.
// 클래스 내부에 static으로 선언한 전역변수나 함수를 
// 전역에 선언을 해주어야 다른 곳에서도 전역함수처럼 사용이 가능하고.
// 전역에 따로 선언을 해주지 않으면 클래스 내부에서만 전역함수로 작용한다.
ConsoleGameScreen ConsoleGameScreen::MainScreen;
char ConsoleGameScreen::Arr[ConsoleGameScreen::ScreenYSize][ConsoleGameScreen::ScreenXSize] = { 0, };
Bomb Bomb::FirstBomb;

int main()
{
	Player NewPlayer;
	Block NewBlock0;          // 새로운 블럭개체를 선언하지 않고 블럭을여러개 만들 방법
	Block NewBlock1;
	Block NewBlock2;

	int2 ScreenSize = ConsoleGameScreen::GetScreenSize();

	NewPlayer.SetPos(ScreenSize.Half());
	NewBlock0.SetPos(ScreenSize.Half3());



	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();  // 맵을 a으로 초기화.

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*'); // 플레이어 생성

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewBlock0.GetPos(), 'O');  // 장애물 생성

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Bomb::FirstBomb.GetPos(), '@');  // 초기 폭탄위치값을 어떻게 해야하나.
		// 폭탄이 없는 상태를 표현할 방법.

		ConsoleGameScreen::GetMainScreen().ScreenPrint();           // 화면 출력.

		NewPlayer.CH = 0; // 받은 키 초기화. 받은키가 계속 남아있어서 그 키가 반복되는 현상이 생김

		NewPlayer.InputKey(NewPlayer);  // 기다리고 키를 받는것.

		NewPlayer.Move(NewPlayer, ConsoleGameScreen::GetMainScreen(), NewBlock0);   // 위에서 받은 키를 통해 이동.

		NewPlayer.CreateBomb(Bomb::FirstBomb);

	}

}


int2 int2::Half() const
{
	return { X / 2, Y / 2 };
}

int2 int2::Half3() const
{
	return { X / 3, Y / 3 };
}

int2::int2(int _X, int _Y)    // 생성자 함수도 분리가 가능하다.
	: X(_X), Y(_Y)
{

}

ConsoleGameScreen::ConsoleGameScreen()
{

}

ConsoleGameScreen& ConsoleGameScreen::GetMainScreen() // 멤버 내부에 static으로 선언된건 static을떼줘야한다.
{
	return MainScreen;
}

int2 ConsoleGameScreen::GetScreenSize()
{
	return int2{ ScreenXSize, ScreenYSize };
}

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			/*if (Arr[y][x] == '@')  // 폭탄 위치가 트루면 a 넣지않는다 == 폭탄 여러개 생성 가능.
			{
				continue;
			}*/
			Arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenXSize <= _Pos.X)
	{
		return true;
	}

	if (ScreenYSize <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, const char _Ch)
{
	if (true == IsScreenOver(_Pos))  //배열 바깥에는 반환하지 않는다.
	{
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Ch;  // 그 배열에 문자를 넣는다.
}

Block::Block()
{

}

int2 Block::GetPos() const
{
	return Pos;
}

void Block::SetPos(const int2& _Value)
{
	Pos = _Value;
}

bool Block::IsBlockOver(const int2& _Pos) const
{
	if (Pos.X == _Pos.X && Pos.Y == _Pos.Y)
	{
		return true;
	}

	return false;
}

Bomb::Bomb()
{

}

int2 Bomb::GetPos() const
{
	return Pos;
}

void Bomb::SetPos(const int2& _Value)
{
	Pos = _Value;
}

bool Bomb::IsBlockOver(const int2& _Pos) const
{
	if (Pos.X == _Pos.X && Pos.Y == _Pos.Y)
	{
		return true;
	}

	return false;
}

int2 Player::GetPos() const
{
	return Pos;
}

void Player::SetPos(const int2& _Value)
{
	Pos = _Value;
}

void Player::InputKey(const Player& _Player)
{
	if (0 == _kbhit())
	{

		Sleep(InterFrame);

		return;
	}

	this->CH = _getch();
}

void Player::Move(Player& _Player, ConsoleGameScreen& _Screen, Block& _Block)
{
	int2 NextPos = { 0, 0 };
	switch (_Player.CH)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == (_Screen.IsScreenOver(NextPos) || _Block.IsBlockOver(NextPos)))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == (_Screen.IsScreenOver(NextPos) || _Block.IsBlockOver(NextPos)))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == (_Screen.IsScreenOver(NextPos) || _Block.IsBlockOver(NextPos)))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == (_Screen.IsScreenOver(NextPos) || _Block.IsBlockOver(NextPos)))
		{
			Pos.Y += 1;
		}
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}

void Player::CreateBomb(Bomb& _Bomb)  // 폭탄 생성 함수로 만들려던거.
{
	switch (CH)
	{
	case 'f':
	case 'F':  //누를 때 마다 새로운 폭탄개체를 만들 방법
		Bomb::FirstBomb.SetPos(GetPos());
		break;
	default:
		break;
	}
}