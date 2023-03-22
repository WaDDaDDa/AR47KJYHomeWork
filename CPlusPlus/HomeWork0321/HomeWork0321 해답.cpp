#include <iostream>
#include <conio.h>


// 때린순간 스테이터스가 바로 반영이 되도록 적용해보아라.
// 대미지를 입히는 순간 Hp가 깎엿다는것을 바로 반영할 수 있도록 만들어라.
// 순서대로 잘 생각해 보아라.

// system("cls")를 잘 이용해 보아라.

// Damage 함수에서 스테이터스를 동시에 출력하도록 하였음.

void StatusRender(
    const char* const _Name, // 때리는 쪽의 이름
    const int& _Att,  // 때리는 쪽의 공격력
    const int& _Hp // 맞는 쪽의 체력
)
{
    printf_s("%s 의 스테이터스 ------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _Hp);
    printf_s("---------------------------\n");
}
// 클래스를 적용해서 인자를 플레이어랑 몬스터만 받아서 진행 시킬수 있을까
void Damage(
    const char* const _AttName, // 때리는 족의 이름
    const char* const _DefName, // 맞는 쪽의 이름
    const int& _AttkerAtt,  // 때리는 쪽의 공격력
    int& _AttkerHp, // 때리는 쪽의 체력
    int& _DefenderAtt, // 맞는 쪽의 공격력
    int& _DefenderHp// 맞는 쪽의 체력
)
{
    _DefenderHp -= _AttkerAtt;
    StatusRender("Player", _AttkerAtt, _AttkerHp);
    StatusRender("Monster", _DefenderAtt, _DefenderHp);
    printf_s("%s가 공격을 시작합니다\n", _AttName);
    printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefName, _AttkerAtt);

}

int main()
{
    int PlayerHp = 100;
    int PlayerAtt = 10;

    int MonsterHp = 100;
    int MonsterAtt = 10;

    system("cls");

    StatusRender("Player", PlayerAtt, PlayerHp);
    StatusRender("Monster", MonsterAtt, MonsterHp);
    _getch();

    while (true)
    {
        system("cls");

        Damage("Player", "Monster", PlayerAtt, PlayerHp, MonsterAtt, MonsterHp); //플레이어 공격.
        _getch();

        if (0 >= MonsterHp)
        {
            printf_s("몬스터가 죽었습니다.");
            printf_s("플레이어의 승리입니다.");
            _getch();
            break;
        }

        system("cls");

        Damage("Monster", "Player", MonsterAtt, MonsterHp, PlayerAtt, PlayerHp); // 몬스터 공격
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
