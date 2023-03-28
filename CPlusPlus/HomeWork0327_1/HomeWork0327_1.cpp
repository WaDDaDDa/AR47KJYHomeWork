#include <iostream>
#include <conio.h>
// 운영체제가 도와줄수밖에 없다.
#include <Windows.h>

// 이게 0단계
// 근본오브 근본 수학 물리 
class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	int2 Half()
	{
		return { X / 2, Y / 2 };
	}

	int2 Half3()
	{
		return { X / 3, Y / 3 };
	}

public:
	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{
	// 메모리 영역 자체가 달라졌다고 봐야합니다.
public:
	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	// Map 크기/
	static const int ScreenYSize = 4;
	static const int ScreenXSize = 4;

	static int2 GetScreenSize()
	{
		return int2{ ScreenXSize, ScreenYSize };
	}


	void ScreenClear()
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

	void ScreenPrint() const
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				// Arr[y][x] = 'b';
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}
	}

	// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
	// 배열 바깥이면 true를 반환한다.
	bool IsScreenOver(const int2& _Pos)
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

	void SetScreenCharacter(const int2& _Pos, char _Ch)
	{
		if (true == IsScreenOver(_Pos))  //배열 바깥에는 반환하지 않는다.
		{
			return;
		}

		Arr[_Pos.Y][_Pos.X] = _Ch;  // 그 배열에 문자를 넣는다.
	}

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

};

class Block
{
public:
	int2 GetPos() const
	{
		return Pos;
	}

	void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	bool IsBlockOver(const int2& _Pos)
	{

		if (Pos.X == _Pos.X && Pos.Y == _Pos.Y)
		{
			return true;
		}

		return false;
	}

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

	int2 GetPos() const
	{
		return Pos;
	}

	void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	// 화면바깥으로 못나가게 하세요. 

	void InputKey(Player _Player)
	{
		if (0 == _kbhit())
		{

			Sleep(InterFrame);

			return;
		}

		this->CH = _getch();
	}

	void Move(Player _Player, ConsoleGameScreen _Screen, Block _Block)
	{
		switch (_Player.CH)
		{
		case 'a':
		case 'A':
			Pos.X -= 1;     
			if (_Screen.IsScreenOver(GetPos()) || _Block.IsBlockOver(GetPos()))
			{
				Pos.X += 1;
			}
			break;
		case 'd':
		case 'D':
			Pos.X += 1;
			if (_Screen.IsScreenOver(GetPos()) || _Block.IsBlockOver(GetPos()))
			{
				Pos.X -= 1;
			}
			break;
		case 'w':
		case 'W':
			Pos.Y -= 1;
			if (_Screen.IsScreenOver(GetPos()) || _Block.IsBlockOver(GetPos()))
			{
				Pos.Y += 1;
			}
			break;
		case 's':
		case 'S':
			Pos.Y += 1;
			if (_Screen.IsScreenOver(GetPos()) || _Block.IsBlockOver(GetPos()))
			{
				Pos.Y -= 1;
			}
			break;
		default:
			break;
		}

		Sleep(InterFrame);
	}

	/*void CreateBomb(Block _Bomb)  // 폭탄 생성 함수로 만들려던거.
	{
	switch (CH)
	{
	case 'f':
	case 'F':  //누를 때 마다 새로운 폭탄개체를 만들 방법
		_Bomb.SetPos(GetPos());
		break;
	default:
		break;
	}
	}*/

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);
};


int main()
{
	ConsoleGameScreen NewScreen;
	Player NewPlayer;
	Block NewBlock0;          // 새로운 블럭개체를 선언하지 않고 블럭을여러개 만들 방법
	Block NewBlock1;
	Block NewBlock2;
	Block NewBomb;       

	int2 ScreenSize = NewScreen.GetScreenSize();

	NewPlayer.SetPos(ScreenSize.Half());
	NewBlock0.SetPos(ScreenSize.Half3());

	

	while (true)
	{
		system("cls");

		NewScreen.ScreenClear();  // 맵을 a으로 초기화.

		NewScreen.SetScreenCharacter(NewPlayer.GetPos(), '*'); // 플레이어 생성
		
		NewScreen.SetScreenCharacter(NewBlock0.GetPos(), 'O');  // 장애물 생성

		NewScreen.SetScreenCharacter(NewBomb.GetPos(), '@');  // 초기 폭탄위치값을 어떻게 해야하나.
		                                                      // 폭탄이 없는 상태를 표현할 방법.

		NewScreen.ScreenPrint();           // 화면 출력.
		 
		NewPlayer.CH = 0; // 받은 키 초기화. 받은키가 계속 남아있어서 그 키가 반복되는 현상이 생김

		NewPlayer.InputKey(NewPlayer);  // 기다리고 키를 받는것.

		NewPlayer.Move(NewPlayer, NewScreen, NewBlock0);   // 위에서 받은 키를 통해 이동.

		//NewPlayer.CreateBomb(NewBomb);

		switch (NewPlayer.CH)
		{
		case 'f':
		case 'F':  //누를 때 마다 새로운 폭탄개체를 만들 방법
			NewBomb.SetPos(NewPlayer.GetPos());
			break;
		default:
			break;
		}

	}


}
