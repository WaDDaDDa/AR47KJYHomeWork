#include <iostream>
#include <conio.h>

// HomeWork0321에서 만든것을 클래스를 적용해보기.
// 클래스를 적용해서 인자를 플레이어랑 몬스터만 받아서 진행 시킬수 있을까
// 미완성 질문 있음.

class Player
{
public:
    const char* Name;
    int Att;
    int Hp;
    
    void GetDamage(int _Att) 
    {
        Hp = Hp - _Att;
    }
};

void StatusRender(
    Player _Attker
)
{
    printf_s("%s 의 스테이터스 ------------\n", _Attker.Name);
    printf_s("공격력 : %d\n", _Attker.Att);
    printf_s("체력 : %d\n", _Attker.Hp);
    printf_s("---------------------------\n");
}
void Damage(
    Player _Attker,
    Player _Defnder
)
{
    _Defnder.GetDamage(_Attker.Att);

    //_Defnder.Hp -= _Attker.Att; // 함수가 끝남과동시에 값이 날라가는데 이유가 뭘까
    _Defnder.Hp;
}

void DamageRender(
    Player _Attker,
    Player _Defnder
)
{
    printf_s("%s가 공격을 시작합니다\n", _Attker.Name);
    printf_s("%s가 %d의 데미지를 입었습니다.\n", _Defnder.Name, _Attker.Att);
}


int main()
{
    Player NewPlayer = Player();
    const char* PlayerName = "Player";
    NewPlayer.Name = PlayerName;
    NewPlayer.Att = 10;
    NewPlayer.Hp = 100;
    
    Player NewMonster = Player();
    const char* MonsterName = "Monster";
    NewMonster.Name = MonsterName;
    NewMonster.Att = 10;
    NewMonster.Hp = 100;


    system("cls");

    StatusRender(NewPlayer);
    StatusRender(NewMonster);
    _getch();

    while (true)
    {
        system("cls");

        Damage(NewPlayer, NewMonster); //플레이어 공격.
        int Hpstatus = NewMonster.Hp;
        StatusRender(NewPlayer);
        StatusRender(NewMonster);
        DamageRender(NewPlayer, NewMonster);
        _getch();

        if (0 >= NewMonster.Hp)
        {
            printf_s("몬스터가 죽었습니다.");
            printf_s("플레이어의 승리입니다.");
            _getch();
            break;
        }

        system("cls");

        Damage(NewMonster, NewPlayer); // 몬스터 공격
        StatusRender(NewPlayer);
        StatusRender(NewMonster);
        DamageRender(NewMonster, NewPlayer);
        _getch();

        if (0 >= NewPlayer.Hp)
        {
            printf_s("플레이어가 죽었습니다.");
            printf_s("몬스터의 승리입니다.");
            _getch();
            break;
        }
    }
}
