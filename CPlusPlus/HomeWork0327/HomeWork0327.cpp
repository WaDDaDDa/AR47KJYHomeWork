// HomeWork0324.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
// 운영체제가 도와줄수밖에 없다.
#include <Windows.h>

// 이게 0단계
// 근본오브 근본 수학 물리 
class int2      //  x, y좌표를 가진 클래스
{
public:
	int X = 0;
	int Y = 0;

public:
	int2 Half()     //  x,y 좌표의 반절위치의 좌표값을 반환해주는 멤버함수.
	{
		return { X / 2, Y / 2 };
	}

public:
	// 이건 내일 합니다.
	//int2() 
	//{
	//}

	int2(int _X, int _Y)  // int2클래스의 생성자. 
		: X(_X), Y(_Y)
	{

	}
};

// 이게 1단계  주로 플랫폼같은 화면 띄우는 것.
// 근본오브 근본 수학 물리 
class ConsoleGameScreen            // 콘솔에 화면을 띄우는 클래스.
{
	// 메모리 영역 자체가 달라졌다고 봐야합니다.
public:
	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	// 멤버변수에 static을 붙임으로써 클래스 내부에 전역변수를 선언할수있다.
	static const int ScreenYSize = 4;
	static const int ScreenXSize = 4;

	// 같은 방법으로 멤버함수또한 클래스 내부에 전역함수로 선언할수있다.
	static int2 GetScreenSize() // x,y 좌표 클래스를 받아서 screen의 크기를 뱉어내는 함수.
	{
		return int2{ ScreenXSize, ScreenYSize }; // x,y값을 가지는 int2생성자를 통한 in2클래스를 반환.
	}

	// 해당함수를 통해 값이 변할 수 있기 때문에 const 미사용.
	void ScreenClear()   // 스크린에 전부 'a'값을 넣는 스크린 클리어.
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}
	}
	// 해당함수를 통해 값이 변하면 안되기 때문에 const를 사용.
	void ScreenPrint() const  // 스크린을 출력하는 스크린프린트 함수.
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				// Arr[y][x] = 'b';  <== 이처럼 화면출력하는데 값이 변하면 안되므로 const로 제어.
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}
	}

	// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
	// 아래 함수가 트루라면 x,y 좌표값이 배열을 벗어났다는 뜻을 의미.
	bool IsScreenOver(const int2& _Pos) const// int2클래스의 x,y 값을 특정조건이면 트루를 리턴시키는 bool형 함수.
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

	// 스크린에 캐릭터를 띄우는 함수. 캐릭터로 지정할 문자도 같이 입력가능.
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
/////////////////////////////////////////////////////////////////// 엔진


// 2단계 컨텐츠
// 클래스가 다른 클래스를 알아야 합니다.
class Player
{
public:
	static char Ch;

	int2 GetPos() const         // 플레이어가 가진 x,y값을 리턴하는 함수.  받는함수
	{
		return Pos;
	}

	void SetPos(const int2& _Value)   // 받은 int2클래스를 플레이어의 pos에 대입하는 함수.  세팅함수.
	{
		Pos = _Value;
	}

	static char GetKey()
	{
		Ch = _getch();
		return Ch;
	}

	// 화면바깥으로 못나가게 하세요. 
	// 못가게 하려면 키입력 받은걸 체크해서 트루면 이동 => 입력전 자리를 기준으로 해버려서 넘어가버림.
	// 이동한후 체크해서 넘어갔다면 되돌아오기.
	// 입력받고 체크해서 움직이지 않게 하기.
	void Input(char Value) // 키입력 받은거에 따라 움직이는 함수.
	{
		if (0 == _kbhit())
		{
			// 0.5초간 멈춘다.
			Sleep(InterFrame);
			// 일부러 멈추게 만들겁니다.
			// continue; 반복문 내부에서만 사용가능
			return;
		}

		Ch = GetKey();

		switch (Ch)
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

	void MoveCheck(char Value, bool _Value)
	{
		if (_Value)
		{
			Ch = GetKey();

			switch (Ch)
			{
			case 'a':
			case 'A':
				Pos.X += 1;
				break;
			case 'd':
			case 'D':
				Pos.X -= 1;
				break;
			case 'w':
			case 'W':
				Pos.Y += 1;
				break;
			case 's':
			case 'S':
				Pos.Y -= 1;
				break;
			default:
				break;
			}

			Sleep(InterFrame);
		}
		return;
	}

protected:

private:
	static const int InterFrame = 200;
	//static char Ch;

	int2 Pos = int2(0, 0);
};


int main()
{
	ConsoleGameScreen NewScreen;
	Player NewPlayer;

	// int2 NewPos = int2{ 5, 5 };

	int2 ScreenSize = NewScreen.GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		NewScreen.ScreenClear();

		NewScreen.SetScreenCharacter(NewPlayer.GetPos(), '*');

		NewScreen.ScreenPrint();

		NewPlayer.Input(NewPlayer.GetKey());
		
		NewPlayer.MoveCheck(NewPlayer.GetKey(), NewScreen.IsScreenOver(NewPlayer.GetPos()));

	}


}
