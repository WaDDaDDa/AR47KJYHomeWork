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

	int2 Half4()
	{
		return { X / 4 , Y / 4 };
	}

	int2 Half5()
	{
		return { X / 5 + 3, Y / 5 + 3};
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
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

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
		if (true == IsScreenOver(_Pos))
		{
			return;
		}

		Arr[_Pos.Y][_Pos.X] = _Ch;
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
			// 0.5초간 멈춘다.
			Sleep(InterFrame);
			// 일부러 멈추게 만들겁니다.
			// continue; 반복문 내부에서만 사용가능
			return;
		}

		this->CH = _getch();
	}

	void Move(Player _Player)
	{
		switch (_Player.CH)
		{
		case 'a':
		case 'A':
			Pos.X -= 1;
			break;
		case 'd':
		case 'D':
			Pos.X += 1;
			break;
		case 'w':
		case 'W':
			Pos.Y -= 1;
			break;
		case 's':
		case 'S':
			Pos.Y += 1;
			break;
		default:
			break;
		}

		Sleep(InterFrame);
	}

	void BlanckCheck(ConsoleGameScreen _NewScreen, Player _Player) // 콘솔의 여부
	{
		if (true == _NewScreen.IsScreenOver(_Player.GetPos()))
		{
			switch (_Player.CH)
			{
			case 'a':
			case 'A':
				this->Pos.X += 1;
				break;
			case 'd':
			case 'D':
				this->Pos.X -= 1;
				break;
			case 'w':
			case 'W':
				this->Pos.Y += 1;
				break;
			case 's':
			case 'S':
				this->Pos.Y -= 1;
				break;
			default:
				break;
			}

			Sleep(InterFrame);
		}
	}

	void BlockCheck(Block _Block, Player _Player) //블록의 여부
	{
		if (true == _Block.IsBlockOver(_Player.GetPos()))
		{
			switch (_Player.CH)
			{
			case 'a':
			case 'A':
				this->Pos.X += 1;
				break;
			case 'd':
			case 'D':
				this->Pos.X -= 1;
				break;
			case 'w':
			case 'W':
				this->Pos.Y += 1;
				break;
			case 's':
			case 'S':
				this->Pos.Y -= 1;
				break;
			default:
				break;
			}

			Sleep(InterFrame);
		}
	}

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);
};


int main()
{
	ConsoleGameScreen NewScreen;
	Player NewPlayer;
	Block NewBlock0;             // 새로운 블럭개체를 선언하지 않고 블럭을여러개 만들 방법
	Block NewBlock1;
	Block NewBlock2;
	Block NewBomb;
	// int2 NewPos = int2{ 5, 5 };

	int2 ScreenSize = NewScreen.GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());
	NewBlock0.SetPos(ScreenSize.Half3());
	NewBlock1.SetPos(ScreenSize.Half4());
	NewBlock2.SetPos(ScreenSize.Half5());

	

	while (true)
	{
		system("cls");

		NewScreen.ScreenClear();  // 맵을 기본값으로 초기화.

		NewScreen.SetScreenCharacter(NewPlayer.GetPos(), '*'); // 그후 플레이어 생성
		
		NewScreen.SetScreenCharacter(NewBlock0.GetPos(), 'O');  // 장애물 생성
		NewScreen.SetScreenCharacter(NewBlock1.GetPos(), 'O');
		NewScreen.SetScreenCharacter(NewBlock2.GetPos(), 'O');

		NewScreen.SetScreenCharacter(NewBomb.GetPos(), '@');  // 폭탄 설치


		NewScreen.ScreenPrint();           // 화면 출력.
		 
		NewPlayer.CH = 0; // 받은 키 초기화. 받은키가 계속 남아있어서 현상이 생김

		NewPlayer.InputKey(NewPlayer);  // 기다리고 키를 받는것.

		NewPlayer.Move(NewPlayer);   // 위에서 받은 키를 통해 이동.

		NewPlayer.BlanckCheck(NewScreen, NewPlayer);  // 이동한곳이 막혔다면 받은키를 바탕으로 원상복구.
		NewPlayer.BlockCheck(NewBlock0, NewPlayer);   // 블럭개체를 만들때마다 코드를 추가하지않고
		NewPlayer.BlockCheck(NewBlock1, NewPlayer);   // block 클래스 전체를 체크할 방법?
		NewPlayer.BlockCheck(NewBlock2, NewPlayer);

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
