#pragma once
#include <GameEngineBase/GameEngineDebug.h>

typedef int KeyType;
typedef int ValueType;

class GameEnginePair
{
public:
	KeyType first;
	ValueType second;

public:
	GameEnginePair()
	{

	}

	GameEnginePair(const KeyType& _Key, const ValueType& _Value)
		: first(_Key), second(_Value)
	{

	}
};

// 설명 :
class GameEngineMap
{
public:

	class MapNode
	{
	public:
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;
		GameEnginePair Pair;

		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}


		MapNode* OverParentNode()
		{
			MapNode* ParentNode = Parent;

			while (Pair.first > ParentNode->Pair.first)
			{
				ParentNode = ParentNode->Parent;

				if (nullptr == ParentNode)
				{
					return nullptr;
				}
			}

			return ParentNode;
		}

		MapNode* PrevNode()
		{
			if (nullptr != LeftChild)
			{
				return LeftChild->MaxNode();
			}

			if (nullptr != Parent)
			{
				return OverParentNode();
			}

			return nullptr;
		}

		MapNode* NextNode()
		{
			if (nullptr != RightChild)
			{
				return RightChild->MinNode();
			}

			if (nullptr != Parent)
			{
				return OverParentNode();
			}

			return nullptr;
		}

		MapNode* MaxNode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}

			return RightChild->MaxNode();
		}

		MapNode* MinNode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}

			return LeftChild->MinNode();
		}

		bool insert(MapNode* _NewNode)
		{
			if (Pair.first > _NewNode->Pair.first)
			{
				if (nullptr != LeftChild)
				{
					return LeftChild->insert(_NewNode);
				}

				LeftChild = _NewNode;
				_NewNode->Parent = this;
				return true;
			}
			else if (Pair.first < _NewNode->Pair.first)
			{
				if (nullptr != RightChild)
				{
					return RightChild->insert(_NewNode);
				}

				RightChild = _NewNode;
				_NewNode->Parent = this;
				return true;
			}

			return false;
		}

		MapNode* find(KeyType _Key)
		{
			if (Pair.first > _Key)
			{
				if (nullptr != LeftChild)
				{
					return LeftChild->find(_Key);
				}

				return nullptr;
			}
			else if (Pair.first < _Key)
			{
				if (nullptr != RightChild)
				{
					return RightChild->find(_Key);
				}

				return nullptr;
			}

			return this;
		}

		// 지워지기 직전에 해야할일
		void Release()
		{
			if (nullptr == Parent) // 부모가 null인경우 그대로 리턴. (루트노드일경우에 해당함). 
			{
				return;   // 그대로 리턴됨. (지워질 노드가 루트 노드라는뜻.)
			}

			if (this == Parent->LeftChild)   // 지워질 나와 내 부모의 왼쪽을 비교. (내가 왼쪽인지를 확인하기위함)
			{
				Parent->LeftChild = nullptr;  // 내가 왼쪽자식이라면 부모의 LeftChild연결을 null 로끊어버린다.
				return;
			}

			if (this == Parent->RightChild)   // 지워질 내가 오른쪽 자식이면
			{
				Parent->RightChild = nullptr;  // 부모의 RightChild 연결을 null로 끊어버린다.
				return;
			}

		}

	};

	class iterator
	{
		friend GameEngineMap;

	public:
		iterator()
			: Node(nullptr)
		{

		}


		iterator(class MapNode* _Node)
			: Node(_Node)
		{

		}

		GameEnginePair* operator->()
		{
			return &Node->Pair;
		}


		bool operator!=(const iterator& _Other) const
		{
			return Node != _Other.Node;
		}

		bool operator==(const iterator& _Other) const
		{
			return Node == _Other.Node;
		}

		iterator& operator++()
		{
			Node = Node->NextNode();

			return *this;
		}

		iterator& operator--()
		{
			Node = Node->PrevNode();

			return *this;
		}



	private:
		// 전방선언
		class MapNode* Node = nullptr;
	};



	iterator begin()
	{
		if (nullptr == Root)
		{
			return end();
		}

		return iterator(Root->MinNode());
	}

	iterator end()
	{
		return iterator();
	}

	iterator find(KeyType _Key)
	{
		if (nullptr == Root)
		{
			return end();
		}

		MapNode* FindNode = Root->find(_Key);

		return iterator(FindNode);
	}


	// 노드가 지워지는 경우의 수를 생각해보자.
	// 1. 자식이 하나도없는 노드가 지워질때.
	// 2. 자식이 왼쪽이든 오른쪽이든 한개 있는 노드가 지워질때.
	// 3. 자식이 왼쪽과 오른쪽 둘다 있는 노드가 지워질때.

	// 1. 의경우   자식이 하나도 없는건. 자신이 리프일때이다. 그냥 지워져도 상관이 없다.
	// 자신의 넥스트를 저장하고 자신은 지워지고 넥스트를 반환.

	// 2 에서 왼쪽에만 자식이 있는 경우.
	// 왼쪽자식을 자신의 위치에 대체되어 연결되게 만들어주고 자신은 지워진다. 그리고 왼쪽자식을 반환.
	// 왼쪽자식이던게 지워질 자신의 부모와 연결되게 만들어야함.
	// 지워질내가 부모의 오른쪽자식인지 왼쪽자식인지를 판별하고 왼쪽자식이면 왼쪽자식에 연결되게
	// 오른쪽이면 오른쪽 자식에 연결되게.

	// 자신을 지우고 자신의 nextnode가 자신의 자리를 대체시켜야함
	// 1. 지워질 자신의 부모에게 자신을 잊어달라고한다.
	// 2. 나의 next노드를 찾는다.
	// 3. 나의 next 노드의 부모에게 나의next노드를 잊어달라고한다.
	// 4. 나의 next 노드의 부모에게 나의 next노드의 자식을 알려준다.
	// 8. 나의 next의 노드의 자식의 부모를 나의 next노드의 부모로 알려준다
	// 5. 나의 next 노드에게 나의 부모를 알려준다.
	// 6. 나의 부모에게 나의 next노드를 자식으로 알려준다.
	// 7. 나의 next 노드에게 나의 자식을 알려준다.
	// 9. 나의 자식노드에 next노드를 부모로 알려준다.

	// 2에서 오른쪽에만 자식이 있는 경우.
	//


	// 3. 왼쪽 오른쪽 자식이 모두있는 노드가 지워질때.

	iterator erase(const iterator& _EraseIter)
	{
		if (_EraseIter == end())
		{
			MsgBoxAssert("앤드를 삭제하려고 했습니다.");
		}

		MapNode* CurNode = _EraseIter.Node;
		MapNode* ParentNode = CurNode->Parent;
		MapNode* RightChild = CurNode->RightChild;
		MapNode* LeftChild = CurNode->LeftChild;

		MapNode* ChangeNode = nullptr;
		MapNode* NextNode = CurNode->NextNode();

		if (true == CurNode->IsLeaf())  // 1번의 경우 완료. (왼쪽오른쪽 둘다 null인지판별)
		{
			CurNode->Release(); // 지워질 노드의 부모에게 자신을 끊어줌.
			delete CurNode;     //  현재지울노드를 지운다.
			CurNode = nullptr;  // null로 변경
			return NextNode;    // 현재 지우기로 한 노드의 next를 반환.
		}
		// 2번의 경우에서 왼쪽에만 자식이 있을경우.
		else if (nullptr == RightChild)  // 오른쪽이 null이면 왼쪽에는 자식이있다.
		{
			CurNode->Release();     // 부모가 자식을 끊은거고 자식은 부모를 기억하는중.
			CurNode->Parent->LeftChild = LeftChild; //지워질 노드가 기억하는 부모의 왼쪽자식에 지워질 나의 왼쪽 자식을 전해준다.
			CurNode->LeftChild->Parent = ParentNode; // 지워질 노드의 왼쪽 자식노드의 부모가 현재 지워질 나인걸 나의 부모로 해준다.
			delete CurNode;
			CurNode = nullptr;
			return NextNode;
		}
		// 2번의 경우에서 오른쪽에만 자식이 있을경우.
		else if (nullptr == LeftChild) // 왼쪽이 null이면 오른쪽에는 자식이있다.
		{
			// 자신을 지우고 자신의 nextnode가 자신의 자리를 대체시켜야함

			// 1. 지워질 자신의 부모에게 자신을 잊어달라고한다.
			CurNode->Release();     // 부모가 자식을 끊은거고 자식은 부모를 기억하는중.
			// 2. 나의 next노드를 찾는다.
			MapNode* CurNextNode = CurNode->NextNode();
			// 3. 나의 next 노드의 부모에게 나의next노드를 잊어달라고한다.
			CurNextNode->Release();
			// 4. 나의 next 노드의 부모에게 나의 next노드의 자식을 알려준다.
			// 4-1 next노드의 자식은 무조건 오른쪽 자식만 있다.
			CurNextNode->Parent = CurNextNode->RightChild;
			// 8. 나의 next의 노드의 자식의 부모를 나의 next노드의 부모로 알려준다
			CurNextNode->RightChild->Parent = CurNextNode->Parent;
			// 5. 나의 next 노드에게 나의 부모를 알려준다.
			CurNextNode->Parent = ParentNode;
			// 6. 나의 부모에게 나의 next노드를 자식으로 알려준다.
			CurNode->Parent->RightChild = CurNextNode;
			// 7. 나의 next 노드에게 나의 자식을 알려준다.
			CurNextNode->RightChild = RightChild;
			// 9. 나의 자식노드에 next노드를 부모로 알려준다.
			CurNode->RightChild->Parent = CurNextNode;

			delete CurNode;
			CurNode = nullptr;
			return NextNode;
		}

	}

	// ????
	iterator rbegin()
	{
		if (nullptr == Root)
		{
			return end();
		}

		return iterator(Root->MaxNode());
	}
	// ???
	iterator rend()
	{
		if (nullptr == Root)
		{
			return nullptr;
		}

		return Root;
	}


	// 안들어가면 false리턴
	bool insert(const GameEnginePair& _Pair)
	{
		if (nullptr == Root)
		{
			Root = new MapNode();
			Root->Pair = _Pair;
			return true;
		}

		MapNode* NewNode = new MapNode();
		NewNode->Pair = _Pair;

		if (false == Root->insert(NewNode))
		{
			delete NewNode;
			NewNode = nullptr;
		}

		return true;
	}

	MapNode* Root = nullptr;
};

