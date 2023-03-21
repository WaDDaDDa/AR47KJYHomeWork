#include <iostream>
#include <conio.h>

// c++ => c를 기반문법으로 해서
// + 객체지향을 추가한 언어입니다.
// + 다른언어에서 좋다고 칭찬받은 문법들을
// 마구잡이로 흡수하기 시작했다.


// 아래의 코드는 절차지향식으로 작성한 코드이다.

// 특정대상이 다른 대상을 때린다.
// 데이터를 변화시켜서 목적을 이룬다.
void Damage(
    const char* const _AttName, // 때리는 족의 이름
    const char* const _DefName, // 맞는 쪽의 이름
    const int& _Att,  // 때리는 쪽의 공격력
    int& _Hp // 맞는 쪽의 체력
)
{
    printf_s("%s가 공격을 시작합니다\n", _AttName);
    printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefName, _Att);
    _Hp -= _Att;

}

void StatusRender(
    const char* const _Name, // 때리는 족의 이름
    const int& _Att,  // 때리는 쪽의 공격력
    const int& _Hp // 맞는 쪽의 체력
)
{
    printf_s("%s 의 스테이터스 ------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _Hp);
    printf_s("---------------------------\n");
}

int main()
{
    // 초기형 프로그래밍인 절차지향은 


    // 글자로 몬스터와 플레이어가 싸우는 게임을 만들고 싶다.
    // 플레이어를 만들어야 한다.

    // c는 데이터를 기반으로 시작한다.
    // 행동을 정의하기 시작합니다.
    int PlayerHp = 100;
    int PlayerAtt = 10;

    int MonsterHp = 100;
    int MonsterAtt = 10;

    while (true)
    {
        system("cls");
        // 추후설명
        // 콘솔 화면에 모든 글자를 지웁니다.

        StatusRender("Player", PlayerAtt, PlayerHp);
        StatusRender("Monster", MonsterAtt, MonsterHp);
        _getch();

        Damage("Player", "Monster", PlayerAtt, MonsterHp);
        _getch();

        if (0 >= MonsterHp)
        {
            printf_s("몬스터가 죽었습니다.");
            printf_s("플레이어의 승리입니다.");
            _getch();
            break;
        }

        Damage("Monster", "Player", MonsterAtt, PlayerHp);
        _getch();

        if (0 >= PlayerHp)
        {
            printf_s("플레이어가 죽었습니다.");
            printf_s("몬스터의 승리입니다.");
            _getch();
            break;
        }
    }
}
