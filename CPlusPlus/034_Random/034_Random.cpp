#include <iostream>
#include <conio.h>

int Seed = 0;

void SeedChange(int _Seed)
{
    Seed = _Seed;
}

int Randomint()
{
    // 수학공식을 통해서 랜덤한듯한 수를 뽑아내는 것.
    // 그에따른 알고리즘(ex well 512 등)이 존재 하므로 seed값이 바뀌지 않는다면 랜덤한 값도
    // 동일하게 나타나게 된다.

    return ++Seed;
}

int main()
{
    // SeedChange(5000);

    // int Value;
    // srand((int)&Value);   <-- 8바이트 정수인  Value의 주소값을 4바이트 정수로 변환.

    // time(0)  <<= 현재 시간(세계 기준시를 기준으로 흘러간 scend)을 리턴해줍니다.
    // 시간은 보통 8바이트 정수로 줍니다.
    unsigned int Test = time(0);
    srand(Test);

    while (true)
    {

        printf_s("%d\n", rand() % 29);
        
        _getch(); // 해당 함수는 키가 눌릴때 까지 프로그램을 정지시킨다.는 함수.
         // 다른 말로 키를 누르면 실행되는 함수.
    }

    std::cout << "Hello World!\n";
}
