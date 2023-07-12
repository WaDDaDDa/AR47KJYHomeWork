// 086_UnionAndDataPadding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>

//typedef union _MyClass {
//} MyClass;


//typedef union _LARGE_INTEGER {
//    struct {
//        int LowPart;
//        int HighPart;
//    };
//    struct {
//        DWORD LowPart;
//        LONG HighPart;
//    } u;
//    LONGLONG QuadPart;
//} LARGE_INTEGER;

union LARGE_INTEGER 
{
    // 곧바로 변수화 시켜서 내부에서 사용하는 문법.
    struct {
        int LowPart;
        int HighPart;
    } u;
    __int64 QuadPart;
};

class Player
{
public:
    struct MyCalss 
    {
        int LowPart;
        int HighPart;
    };

    MyCalss u;
    __int64 QuadPart;
};

class tPlayer
{
public:
    // 300 번지부터 304
    int LowPart;
    // 304 번지부터 308
    int HighPart;
    // 308 번지부터 316
    __int64 QuadPart;
};

// 메모리의 구성을 변수가 존재한다면
union UPlayer
{
public:
    // 내부에 의미있는 변수가 있다면
    // 그중 가장 큰 변수를 중심으로 같은 위치에 다른 이름을 준다.
    // [][][][]

    // 300번지 308
    __int64 C = 0;
    // 300번지 304
    int A;
    // 300번지 304
    int B;
};

class MyUniCalss 
{
public:
    union 
    {
        int a;
        int b;
    };

    class 
    {
    public:
        int x;
        int y;
    }; 
};

struct TestStruct
{
    int a;
    int b;
};


union LastUnion
{
    // 300번지 8바이트
    TestStruct ValueAB;

    // 300번지 8바이트
    __int64 Test;
};



int main()
{
    // GetCurrentDirectory();
    // getcurrentdirector

    {
        LastUnion New;

        New.ValueAB.a = 10;

        int size = sizeof(LastUnion);


        int a = 0;
    }



    {
        MyUniCalss New;

        New.a = 10;

        int size = sizeof(MyUniCalss);


        int a = 0;
    }

    {
        // 200번지에 만들어졌다고 칠께요.
        Player NewPlayer;

        // 200번지 부터 204번지 까지 사용하겠다.
        NewPlayer.u.LowPart;

        // 204번지 부터 208번지 까지 사용하겠다.
        NewPlayer.u.HighPart;

        // 208번지 부터 216번지 까지 사용하겠다.
        NewPlayer.QuadPart;

        int Value = sizeof(Player);

        int a = 0;
    }

    {
        // 300번지.
        UPlayer NewPlayer;
        
        // 00000001 00000000 00000000 00000000 00000000 00000000 00000000 00000000

        // 300번지 304번지를 사용하겠다.
        NewPlayer.A = 1;

        // 300번지 304번지를 사용하겠다.
        NewPlayer.B;

        NewPlayer.C;

        int Value = sizeof(UPlayer);

        int a = 0;
    }


    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
