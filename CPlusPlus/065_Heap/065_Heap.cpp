#include <iostream>
#include <crtdbg.h>

class Monster
{

};

int main()
{
    // 외우셔야 합니다.
    // 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시. include <crtdbg.h>
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //  Dumping objects ->
    //  {76} normal block at 0x00000205893E68E0, 1 bytes long.  이런식으로 표시해줌.


    // new 로 힙에 메모리를 만들었다면 반드시 delete하는 코드를 먼저치고 생각하라.

    // 힙영역에 선언은 new를 통해서 선언하게 됨.
    Monster* PtrMonster = new Monster();

    while (true)
    {
       
    }

    // 강제 종료의 경우에는 어쩔수없이 릭이 남을수 있지만 
    delete PtrMonster;

    // 연산자   자료형 생성자
    // new     자료형  ();

    // 힙은 가장 자유롭게 메모리를 할당할수 있는 영역입니다.
    // 몇개든 선언만하면 만들어 질수 있어서 게임에서는 몬스터나 총알 갯수처럼
    // 몇개가 만들어질지 모르는 때에 사용되곤 한다.

    int Value = 20;

    // 받지 않으면 힙에 만들어진 메모리를 잃어버리므로
    //  힙은 주소값으로 받아야한다.
    // int* Ptr = new int();
    // new int(); // 잃어버린 힙.
    // 무조건 받아야한다.    (받아주더라도 delete하지않으면 잃어버린 메모리가 된다.)
    int* Ptr = /*operator new()*/ new int();

    *Ptr = 20;

    // 힙영역을 할당하고 지우지 않으면
    // Leck 혹은 메모리 누수라고 부르는데
    // 그것때문에 프로그램을 종료해도 느려지는 경우는 없다.

    // 내 게임이 느려지지 않게 하기 위해서 무조건 지워줘야 합니다.
    delete Ptr;
    // 위의 주소값을 받지 않은 녀석은 절대로 지울수 없다.

    // 초당 10000회 20000회 실행이 될겁니다.
    //while (true)
    //{
    //    
    //}

}
