

#include <iostream>
#include <GameEngineConsole/GameEngineArray.h>
#include <conio.h>

// 배열형
//      노드형
//   노드형에서 2가지가 있는데.
//    선형                           트리형

// 노드 형태라고 부르는 굉장히 많이 
// 사용되는 방식이 존재하는데

// 어떤 클래스가 자신내부에 자기자신의 
// 참조형(보통은 포인터)을 n개 들고 있으면
// 그걸 노드형식이라고 합니다.

// 자신과 같은 자료형의 주소를 알고있으면 다른 자료형과 얽히는게 아닌 
// 자기 자신가 얽히는 것이기에 충돌의 의미가 적다.

// 맵의 한 지역
// 여섯 갈래 길
// 슬리피우드
// 헤네시스
// 엘리니아
// 커닝시티
// 페리온

class MapZone
{
public:
    // 선택된 번호의 주소를 찾아간다.
    MapZone* SelectNext()
    {
        system("cls");
        printf_s("현재 이곳은 %s 입니다.\n", GetName());
        printf_s("어디로 가시겠습니까?\n");

        for (int i = 0; i < LinkZone.Count(); i++)
        {
            printf("%d. %s\n", i + 1, LinkZone[i]->GetName());
        }

        int Select = _getch();
        int SelectIndex = Select - '1';

        if (SelectIndex >= LinkZone.Count())
        {
            return this;
        }

        return LinkZone[SelectIndex];

    }

    const char* GetName()
    {
        return Name;
    }

    void SetName(const char* _Name)
    {
        Name = _Name;
    }

    void Link(MapZone* _OtherZone)
    {
        if (nullptr == _OtherZone)
        {
            return;
        }

        LinkZone.ReSize(LinkZone.Count() + 1);
        LinkZone[LinkZone.Count() - 1] = _OtherZone;

        _OtherZone->LinkZone.ReSize(_OtherZone->LinkZone.Count() + 1);
        _OtherZone->LinkZone[_OtherZone->LinkZone.Count() - 1] = this;

    }

private:
    const char* Name = nullptr;
    // MapZone*로만 가지고있으면 MapZone의 주소를 1개 알고있는 것
    // 게임엔진Array를 통해 MapZone*를 여러개가지는 배열로 들고있다면
    // 동적할당이기때문에 언제든지 맵을 추가해나갈수 있다.
    GameEngineArray<MapZone*> LinkZone;
};


// 이런 구조를 Node라고 하는데
// 노드는 일방적 통행인 단방향과   
// 이전과 다음 모두 알고있는 양방향으로 나눌수있다.
// 단방향은 Next로 넘어가면 Prev로 다시 갈수없는 구조이고
// 양방향은 내부에 주소값으로 Next와 Prev모두 지니고 있어서 
// 왔다갔다 할수있는 구조이다.

typedef int DataType;

class Node
{
public:
    Node(const DataType& _Value)
        : Value(_Value)
    {
    }

    int GetValue()
    {
        return Value;
    }

    Node* GetNext()
    {
        return Next;
    }

    Node* GetPrev()
    {
        return Prev;
    }

    // 포인터와 레퍼런스의 차이.
    // 포인터를 인자로 사용하면 사용할 값이 들어있는 자료의 주소값을 넣어줘야하고
    void NextLinkPointer(Node* _Next)
    {
        Next = _Next;
        _Next->Prev = this;
    }
    //레퍼런스를 인자로 사용한다면 그값이 들어있는 자체를 넣어줄수 있다.
    void NextLinkRef(Node& _Next)
    {
        Next = &_Next;
        _Next.Prev = this;
    }

private:
    // 단방향 노드
    Node* Next = nullptr;
    // 양방향
    Node* Prev = nullptr;

    DataType Value;
};

int main()
{
    {
        Node Node1 = 0;
        Node Node2 = 1;
        Node Node3 = 2;
        Node Node4 = 3;
        Node Node5 = 4;

        Node1.NextLinkRef(Node2);
        Node2.NextLinkRef(Node3);
        Node3.NextLinkRef(Node4);
        Node4.NextLinkRef(Node5);

        Node* CurNode = &Node5;
        while (nullptr != CurNode)
        {
            printf_s("%d\n", CurNode->GetValue());
            CurNode = CurNode->GetPrev();


            //const char* Name = CurMap->GetName();
            //printf_s("%s\n", CurMap->GetName());
            //CurMap = CurMap->GetLink();
        }

        return 1;

    }

    {
        // 100
        MapZone Map1;
        // 200
        MapZone Map2;
        // 300
        MapZone Map3;
        // 400
        MapZone Map4;

        MapZone Map5;
        MapZone Map6;


        Map1.SetName("여섯 갈래 길");
        Map2.SetName("슬리피우드");
        Map3.SetName("헤네시스");
        Map4.SetName("커닝시티");
        Map5.SetName("엘리니아");
        Map6.SetName("페리온");

        Map1.Link(&Map2);
        Map1.Link(&Map4);
        Map1.Link(&Map3);

        Map2.Link(&Map5);

        // 100번지
        MapZone* CurMap = &Map1;
        while (nullptr != CurMap)
        {
            CurMap = CurMap->SelectNext();

            //const char* Name = CurMap->GetName();
            //printf_s("%s\n", CurMap->GetName());
            //CurMap = CurMap->GetLink();
        }
    }

}
