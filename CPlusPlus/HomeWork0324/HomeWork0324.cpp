// HomeWork0324.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
// 운영체제가 도와줄수밖에 없다.
#include <Windows.h>

// 숙제 0
// 상하좌우로 다 움직이게 해주세요.    // 해결

// 숙제 1
// 잔상 지우기                         // 해결

// 숙제 2                            // 1. unsigned로 음수를 없애려했더니 음수에 접근하게되면 터짐
// 화면 바깥으로 못나가게 하세요.    // 해결. 2차원배열이라도 사실 1차원적이다. 
// 배열을 arr[3][3] 으로 해두면
// (0,0) (0,1) (0,2) (1,0) (1,1) (1,2) (2,0) (2,1) (2,2) 이런식의 나열인데
// 여기에 (1,3)의 값이 들어오면 (2,0)이 호출되게 된다. 의도치않았기때문에
// 제어해줘야한다.

// 안해도 되는 숙제 
// 질문했을때 안받아줄겁니다.

// 숙제 3                               // 해결.
// 장애물 만들고 배치하세요 당연히 플레이어는 거기로 못갑니다.

// 숙제 4                              // 기능은 하는데 폭탄이 없는 초기상태가 불안함. (버퍼 오버런)
// 폭탄 f를 누를면 폭탄이 설치되고 눈에 보여야 합니다. 폭탄 @

// 숙제 5
// 일정시간이 지나고 폭탄이 터지면서
//     @
//     @
//     @
//  @@@@@@@
//     @
//     @
//     @

// bool 을 이용해서 1이면 a를 0이면 폭탄을 만들도록 지정한 다음에 만들 수있을까?
// 가능하면 nullptr을 폭탄으로 할수있을거 같은데. 

int main()
{
	const int ScreenYSize = 8;
	const int ScreenXSize = 8;

	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	/*for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}*/

	// 정수를 정수로 나오면 실수는 버리고 정수의 값만 나옵니다.
	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;
	// X Y가 Size 변수 값보다 작거나 커지지 않으면 된다.  == 테두리 바깥으로 나가는거 제어는 가능.
	// 하지만 텔레포트 하는 듯한 이동의 제어는 되지 않음.  다른 방법.
	// 텔레포트 제어는. 

	const int BlockY = ScreenYSize / 4;
	const int BlockX = ScreenXSize / 4;

	int BombY = ScreenYSize * 2;
	int BombX = ScreenXSize * 2;

	while (true)
	{
		system("cls");
		// 배열 크기만큼 a를 넣어주는것.  
		// if 를 사용해서 만약 nullptr이 아니라면 a를 넣어준다 가 된다면?
		// nullptr이라면 @ 근데 직접적인 대입은 불가능함.
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}
		Arr[PlayerY][PlayerX] = '*';
		Arr[BlockY][BlockX] = ' ';
		Arr[BombY][BombX] = '@';   // 버퍼 오버런 없이 초기에 폭탄을 안보이게 하는 방법?
		                           // nullptr일 경우 폭탄이 나오게 한다면?
		                           // 초반에 nullptr로 선언하고 그 배열이 nullptr이면 @폭탄

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}


		// 이건 내가 키를 눌렀다면 1
		// 아니라면 0을 리턴하는 함수고 정지하지 않습니다.
		// 키를 눌렀다는것을 체크해주는 함수
		if (0 == _kbhit())
		{
			// 0.5초간 멈춘다.
			Sleep(200);
			// 일부러 멈추게 만들겁니다.
			continue;
		}

		// 어떤키를 눌렀는지 알려주는 함수.
		char Ch = _getch();

		switch (Ch)   // wasd를 통한 이동
		{
		case 'a':
		case 'A':
			PlayerX -= 1;
			break;
		case 's':
		case 'S':
			PlayerY += 1;
			break;
		case 'd':
		case 'D':
			PlayerX += 1;
			break;
		case 'w':
		case 'W':
			PlayerY -= 1;
			break;
		case 'f':
		case 'F':
			BombY = PlayerY;
			BombX = PlayerX;
			break;
		default:
			break;
		}

		if (PlayerY >= ScreenYSize)   // 벽 넘나들지 못하게 하는것.
		{
			PlayerY -= 1;
			continue;
		}
		else if (PlayerY < 0)
		{
			PlayerY += 1;
			continue;
		}
		else if (PlayerX >= ScreenXSize)
		{
			PlayerX -= 1;
			continue;
		}
		else if (PlayerX < 0)
		{
			PlayerX += 1;
			continue;
		}

		if (Arr[PlayerY][PlayerX] == Arr[BlockY][BlockX])    // 장애물 못가게하는 것.
		{
			switch (Ch)
			{
			case 'a':
			case 'A':
				PlayerX += 1;
				break;
			case 's':
			case 'S':
				PlayerY -= 1;
				break;
			case 'd':
			case 'D':
				PlayerX -= 1;
				break;
			case 'w':
			case 'W':
				PlayerY += 1;
				break;
			default:
				break;
			}
		}
		Sleep(200);
	}


}
