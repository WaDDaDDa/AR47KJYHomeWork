// 041_Class002_UserAccess.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{ // 클래스의 시작과
    // 클래스 문법에서는 속성이나 행동을
    // 내가 외부에 공겨할지 안할지를 결정할 수 있습니다.

// 접근제한 지정자라고 부릅니다.  (public: , protected: , private: )

// 접근제한 지정자는 만들어진 위치부터 아래까지 새로운 접근제한 지정자가
// 나올 때 까지 동일한 접근제한 권한을 가진다.

    //                 내부코드     자식코드     외부
public:                // 공개        공개      공개
    int Att = 10;
    int Def = 2;
protected:             // 공개        공개      비공개
    int Hp = 100;
private:               // 공개        비공개    비공개
    int Speed = 3;
}; // 클래스의 끝
// 이안에 안들어있으면 다 외부입니다.
// 자식코드는 다음시간에.
// 클래스 내부에있으면 내부코드
// 그외에 바깥은 외부로 이해하면 일단 OK.

class Monster
{
    //private: // class의 디폴트 접근제한 지정자는 private이다. == 내부코드 외에는 비공개.
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
};

int main()
{
    // 외부

    Monster NewMonster;

    NewMonster.Att; // 기본 접근제한 지정자가 private 이기에 외부인 main에서는 접근 불가. 

    Player NewPlayer = Player();

    NewPlayer.Att; // 기본 접근제한 지정자는 private이지만 내부에서 public인 Att와Def는 접근 가능.

    // NewPlayer.Speed
}
