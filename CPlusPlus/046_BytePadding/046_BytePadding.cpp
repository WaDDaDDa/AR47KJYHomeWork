#include <iostream>

// short 2바이트 정수형;
// 클래스의 바이트 크기를 알아보자.
// 클래스 내부에 여러 자료형이 선언됨에 따라 클래스의 크기는 어떻게 달라지나를 확인해보기.
class Player0     // 16바이트 예상.    정답 : 16바이트.
{
public:
    int Hp;          // 4  int 
    short Value1;    // 4  short  //2바이트 남음.
    int Value2;      // 4  short와 int를 같이 4바이트에 담을수 없으므로 다시 int만 4바이트
    short Value3;    // 4  short와 char를 4바이트에 같이 담을수있으므로 둘이서 4바이트. //1바이트남음
    char TTT;                    

    // 8바이트 이하 가장큰 바이트의 자료형을 찾아요.
    // 4바이트
    // 먼저 4바이트를 할당했다고 쳐보자
    // 딱맞거나 들어갈수 있으면 그대로 픽스
    // 4바이트 할당한다.
    // char
    // 8바이트
};

class Player1  // 먼저 나오는 자료형의 바이트가 더 낮고 나중에 나오는 바이트가 큰 경우.
{              // 8바이트 예상.   정답 : 8바이트.
public:
    char i;    // 4바이트     빈공간 3바이트 빈공간을 패딩바이트라고 한다.
    int Hp;    // 4바이트
};

class Player2   // 위에 선언된 Player1과의 차이는?
{               // 16바이트 예상.   정답: 16바이트.
public:
    char i;       // 8   char과 int를 8바이트에 담고 패딩바이트 3만큼 발생.
    int Hp;
    __int64 Value; // 8
};

class Player3     //  16바이트예상  정답: 16바이트.
{
public:
    int A;      // 4
    char i;     // 4    패딩 바이트 3 발생.
    int Hp;     // 4
    short B;    // 4    패딩 바이트 2 발생.
};

class Player4     // 24바이트 예상.  정답 : 24바이트.
{
public:
    int A;        
    char i;        //  8    패딩바이트 3발생.
    int Hp;   
    short B;       //  8    패딩 바이트 2 발생.
    __int64 C;     //  8  
};

class Player5   // 클래스안에 클래스가 선언 된다면?
{                  //  24 바이트 예상.  정답 : 24 바이트.
public:
    int A;        
    char i;          // 8
    int Hp;
    short B;         // 8
    Player1 New;     // 8  8이하인 자료형 중 가장 큰 자료형에 class가 8바이트로 작용.
};

class Player6   // 클래스안에 클래스가 선언 된다면?
{                  // 48바이트 예상.    정답 : 40 바이트.
public:
    int A;
    char i;        // 8
    int Hp;
    short B;       // 8
    Player1 New;   // 8   8이하인 자료형 중 가장 큰 자료형에 player1가 8바이트로 작용.
    Player2 New1;  // 16    8보다큰 자료형을 가진 자료형은 자신이 가진 바이트를 할당.
};


int main()
{
    int Size0 = sizeof(Player0);
    int Size1 = sizeof(Player1);
    int Size2 = sizeof(Player2);
    int Size3 = sizeof(Player3);
    int Size4 = sizeof(Player4);
    int Size5 = sizeof(Player5);
    int Size6 = sizeof(Player6);

    printf_s("%d\n", Size0);
    printf_s("%d\n", Size1);
    printf_s("%d\n", Size2);
    printf_s("%d\n", Size3);
    printf_s("%d\n", Size4);
    printf_s("%d\n", Size5);
    printf_s("%d\n", Size6);


    // 그렇다면 패딩 바이트의 주소는 어떻게 될까?
    Player0 NewPlayer;

    NewPlayer.Hp = 0;            // int
    NewPlayer.Value1 = 1;        // sohrt
    NewPlayer.Value2 = 2;        // int
    NewPlayer.Value3 = 3;        // short
    NewPlayer.TTT = 4;           // char

    int* Ptr0 = &NewPlayer.Hp; // 주소값 찾아보기 .
    short* PtrS = &NewPlayer.Value1;

    __int64 address = (__int64)Ptr0;
    __int64 addressS = (__int64)PtrS;

    printf_s("%d\n", *Ptr0);       // NewPlayer.Hp 의 주소
    address = address + 4; 
    printf_s("%d\n", address);     // NewPlayer.Value1 의 주소를 계산하여 접근한 주소.
    printf_s("%d\n", addressS);    // Newplayer.Value1을 short로 직접 찾아간 주소.
    // 이 두개가 같다면 4바이트 이후에 왼쪽부터 바이트가 채워진다.
    // 4바이트 공간에 short는 왼쪽부터 채워지고 그 이후가 패딩바이트가 된다.

    // 그렇다면 NewPlayer.TTT의 char변수의 주소는
    // NewPlayer.Hp 의 주소에서 14번째다음 주소가 될것이다.

    //확인
    address = address + 10;
    char* PtrCH = &NewPlayer.TTT;
    __int64 addressCH = (__int64)PtrCH;

    printf_s("%d\n", address);
    printf_s("%d\n", addressCH);
    // 동일함을 확인.
    
    // 결론 : 클래스에서 남는 패딩 파이트는 오른쪽에 위치한다.



}