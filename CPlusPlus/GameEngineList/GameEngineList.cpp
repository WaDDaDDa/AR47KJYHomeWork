

// 4월 13일 HomeWork  list에서 push_front가 어떤기능을 하는지 메모리적으로 고려하기/
// vector에도 push_front 기능이 있나 없나 확인하고 없다면 왜 없는지의 이유를 메모리적으로 생각하기.

#include <iostream>
#include <list>
#include <crtdbg.h>
// 자료구조의 구분

// 메모리 형태로서의 구분 => 노드형 배열형
// 데이터 처리 방식으로서의 구분 => 시퀸스 연관 어댑터
// 배열형 시퀸스 자료구조가 vector였다.
// 
// 상황에 따른 너무나도 커질수 있는 재할당과 복사 연산의 위험성이 벡터의 문제점입니다.
// 10만개 짜리 벡터에서 10만 1개짜리 
// 벡터가 되는순간 벌어지는 일을 생각해봐라.  (자료를 추가하고 삭제하는데에 연산속도가 느리다.)
// 그외에는 빠르다.

// 메모리는 연속되어있을때 가장 빠릅니다.
// 컴퓨터 친화적 코딩이라고 합니다.
// 할수있다면 최대한 벡터로 짜는게 좋다.
// 그 단점을 해결하기 위한게 리스트
// 대부분의 연산에서 느립니다.
// 리스트의 가장큰 장점은 편의성입니다.

typedef int DataType;

class GameEngineList  // 제공되는 인터페이스 list를 본따만든 나만의 리스트.
{
private:
    class ListNode  // 클래스 내부의 클래스 선언. 내부에 있지만 서로다른 클래스이다. (연관이없음) 네임스페이스를 사용한것처럼 사용.
    {
    public:
        ListNode* Prev = nullptr;    // 이전주소를 지니고있고.
        ListNode* Next = nullptr;    // 다음주소를 지니고있다.
        DataType Value;              // 값을 가진다.  ( 나중에 클래스가 될수있고 뭐든 될수있다. DataType)


    public:
        ~ListNode()    // 소멸자.
        {
            if (nullptr != Next)  // 안전삭제를 한다.
            {
                delete Next;
                Next = nullptr;
            }
        }
    };

public:
    class iterator  // 이터레이터라는 클래스를 또 만든다.
    {
        friend GameEngineList;   // friend 키워드는 GameEngineList의 접근제한자를 무시하고 접근할수있게 해준다.

    public:
        iterator()
        {

        }

        iterator(ListNode* _CurNode) // 이터레이터 생성자. 현재노드의 주소를 인자로 해서 curnode에 대입.
            : CurNode(_CurNode)
        {

        }

        bool operator !=(const iterator& _Other) // 오퍼레이터 재정의 !=  현재노드의 주소와 비교노드의 주소를 != 재정의.
        {
            return CurNode != _Other.CurNode;
        }

        iterator& operator ++() // ++재정의 현재노드주소에 ++하면 next의 주소를 받게끔하고 그자신의 값을 리턴한다.
        {
            CurNode = CurNode->Next;

            return *this;
        }

        DataType& operator*() // *포인터 재정의 현재노드가 가진 Value를 리턴하도록 재정의.
        {
            return CurNode->Value;
        }

    private:
        ListNode* CurNode = nullptr;  // 현재노드의 주소는 nullptr로 초기화 된 상태.
    };

    GameEngineList()
    {
        StartNode->Next = EndNode;
        EndNode->Prev = StartNode;
    }

    ~GameEngineList()
    {
        if (nullptr != StartNode)
        {
            delete StartNode;
            StartNode = nullptr;
        }
    }

    iterator begin()
    {
        return iterator(StartNode->Next);
    }

    iterator end()
    {
        return iterator(EndNode);
    }

    iterator erase(iterator& _DeleteNode)
    {
        ListNode* DeleteNode = _DeleteNode.CurNode;

        ListNode* PrevNode = DeleteNode->Prev;
        ListNode* NextNode = DeleteNode->Next;

        DeleteNode->Prev = nullptr;
        DeleteNode->Next = nullptr;

        if (nullptr != DeleteNode)
        {
            delete DeleteNode;
            DeleteNode = nullptr;
        }

        PrevNode->Next = NextNode;
        NextNode->Prev = PrevNode;

        return iterator(NextNode);

        // 절대로 Node존재를 외부에 공개하고 싶지 않아.
        // _DeleteNode
    }

    void push_back(const DataType& _Data)
    {
        ListNode* NewListNode = new ListNode();
        NewListNode->Value = _Data;

        ListNode* PrevNode = EndNode->Prev;

        // 연결을 끊고.
        //PrevNode->Next = nullptr;
        //EndNode->Prev = nullptr;

        PrevNode->Next = NewListNode;
        EndNode->Prev = NewListNode;
        NewListNode->Next = EndNode;
        NewListNode->Prev = PrevNode;
    }

    void push_front(const DataType& _Data)
    {

    }

private:



    // 더미노트
    ListNode* StartNode = new ListNode();
    ListNode* EndNode = new ListNode();


};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //{

    //    GameEngineList NewList;

    //    NewList.push_back(999);
    //    NewList.push_back(888);
    //    NewList.push_back(777);
    //    NewList.push_back(123156456);

    //    {
    //        //                    999
    //        GameEngineList::iterator Delete = NewList.begin();
    //        ++Delete; // 888

    //        NewList.erase(Delete);

    //    }


    //    //// Node들을 기억해보면
    //    //// Node형태의 자료들을 순회를 돌려면
    //    //// 그중 한 지점의 노드의 주소를 알아야만 돌수 있다.
    //    //// 그걸 Node를 직접 외부에 공개하지 않습니다.

    //    GameEngineList::iterator Start = NewList.begin();
    //    GameEngineList::iterator End = NewList.end();

    //    // NewList[1]

    //    for (; Start != End; ++Start)
    //    {
    //        printf_s("%d\n", *Start);
    //    }

    //}

    //return 1;

    {
        std::list<int> NewList;

        NewList.push_back(999);
        NewList.push_back(888);
        NewList.push_back(777);
        NewList.push_back(123156456);
        

        {
            //                    999
            std::list<int>::iterator Delete = NewList.begin(); // start노드의 next를 의미함.  999
            ++Delete; // 888   오퍼레이터 재정의를 통해서 next를 cur노드에 대입하는것이 됨. 888

            NewList.erase(Delete);  // 888을 삭제하고 888의 이전노드와 이후노드를 연결시켜줌.

        }
        NewList.push_front(2000); // start의 next노드에 자료를 추가하는 push_front. vector에도 있을까?

        // Node들을 기억해보면
        // Node형태의 자료들을 순회를 돌려면
        // 그중 한 지점의 노드의 주소를 알아야만 돌수 있다.
        // 그걸 Node를 직접 외부에 공개하지 않습니다.

        std::list<int>::iterator Start = NewList.begin();
        std::list<int>::iterator End = NewList.end();

        // NewList[1]

        for (; Start != End; ++Start) // 리스트의 순회.
        {
            printf_s("%d\n", *Start);
        }

    }



}
