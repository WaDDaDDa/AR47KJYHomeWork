#pragma once
#include <GameEngineBase/GameEngineDebug.h>

class iterator;

// typedef int KeyType;
// typedef int ValueType;

template <typename KeyType, typename ValueType>
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
template <typename KeyType, typename ValueType>
class GameEngineMap
{
public:

	~GameEngineMap()
	{
		Root->LastOrderdelete();
	}

	class MapNode
	{
	public:
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;
		GameEnginePair<KeyType, ValueType> Pair;

		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}


		// 자식의 부모에게 교체될 Node를 알려주고 교체해달라고함.
		// 부모가 가르키는 자식을 변경하는 함수.
		// 새로운 자식도 부모를 인식시킴.
		void ChangeChild(MapNode* _PastChild, MapNode* _NewChild)
		{
			if (_PastChild == LeftChild) // 과거 자식이 부모의 왼쪽인지 오른쪽인지 판별.
			{
				LeftChild = _NewChild;  // 왼쪽자식으로 판별되면 새로운자식을 부모의 왼자식으로 편입.
				if (nullptr != _NewChild) // 새로운 자식이 nullptr이 아니라면
				{
					_NewChild->Parent = this; // 새로운자식에게 부모가 자신이라는것을 알림.
				}
				return;
			}

			if (_PastChild == RightChild) // 과거 자식이 부모의 왼쪽인지 오른쪽인지 판별.
			{
				RightChild = _NewChild;  //오른쪽자식으로 판별되면 새로운자식을 부모의 오른자식으로 편입.
				if (nullptr != _NewChild)
				{
					_NewChild->Parent = this;
				}
				return;
			}

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

		MapNode* UnderParentNode()
		{
			MapNode* ParentNode = Parent;

			while (Pair.first < ParentNode->Pair.first)
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
				return UnderParentNode();
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
		// 루트에서 부터 왼쪽 자식들을 차례대로 먼저 순회하고 왼쪽을 다순회했으면
		// 다시 하나씩올라오면서 오른쪽도 똑같이 체크.
		void FirstOrder() 
		{
			std::cout << Pair.first << std::endl;
			if (nullptr != LeftChild)  // left가 있으면 여기로
			{
				LeftChild->FirstOrder();
			}
			if (nullptr != RightChild) // right가 있으면 여기로.
			{
				RightChild->FirstOrder();
			}
		}
		// Min노드를 먼저 출력한다음에 그 다음 min노드를 찾아 출력하는 형식
		// std::map의 방식이 이것.
		void MidOrder() 
		{
			if (nullptr != LeftChild)
			{
				LeftChild->MidOrder();
			}
			std::cout << Pair.first << std::endl;
			if (nullptr != RightChild)
			{
				RightChild->MidOrder();
			}

		}
		// min노드를 가장먼저 출력하고 그 부모의 오른쪽의 민노드를 찾아 출력하고 한칸씩 올라오면서 순회
		// 왼쪽을 먼저 차근차근 순회하고 오른쪽도 동일하게 순회하면 한칸씩올라오는 구조.

		void LastOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->LastOrder();
			}
			if (nullptr != RightChild)
			{
				RightChild->LastOrder();
			}

			std::cout << Pair.first << std::endl;
		}
		// 후위순으로 딜리트 하겠다.
		// 가장 말단부터 차례대로 delete 하기에는 LastOrder가 적합하다.
		void LastOrderdelete() 
		{
			MapNode* CurNode = this;
			
			if (nullptr == CurNode) // 맵에 노드가 한개도 없을때 rootnode가 null일때.
			{
				return;
			}

			if (nullptr != LeftChild) 
			{
				LeftChild->LastOrderdelete(); //왼쪽 자식이 있으면 반복.
			}

			if (nullptr != RightChild)
			{
				RightChild->LastOrderdelete(); // 오른쪽 자식이 있으면 반복.
			}

			if (nullptr != CurNode)
			{
				delete CurNode;
				CurNode = nullptr;
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

		GameEnginePair<KeyType, ValueType>* operator->()
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

	iterator erase(const iterator& _EraseIter)
	{
		if (_EraseIter == end())
		{
			MsgBoxAssert("앤드를 삭제하려고 했습니다.");
		}

		MapNode* CurNode = _EraseIter.Node;     //삭제할 노드.					  15
		MapNode* ParentNode = CurNode->Parent;  //삭제할 노드의 부모.             10
		MapNode* RightChild = CurNode->RightChild; // 삭제할 노드의 오른쪽자식.   25
		MapNode* LeftChild = CurNode->LeftChild;   // 삭제할 노드의 왼쪽 자식.    null

		MapNode* ChangeNode = nullptr;          //삭제될노드를 대체할 nextnode.
		MapNode* ChangeNodeParent = nullptr;    //삭제될 노드를 대체할 nextnode의 부모.
		MapNode* NextNode = CurNode->NextNode();

		if (true == CurNode->IsLeaf())    //CurNode가 왼,오 자식이 없다면.
		{
			ParentNode->ChangeChild(CurNode, nullptr);
			if (nullptr != CurNode)
			{
				delete CurNode;
				CurNode = nullptr;
			}
			return NextNode;
		}


		// 교체될 노드는 절대로 양쪽을 모두 가진 노드일수 없다.
		MapNode* ChangeChild = nullptr;
		MapNode* ChangeParent = nullptr;

		// Next노드의 왼쪽 오른쪽 자식의 유무를 판단
		if (nullptr != LeftChild)   // 삭제할노드의 LeftChild가 존재한다면.
		{
			ChangeNode = LeftChild->MaxNode();
			ChangeChild = ChangeNode->LeftChild;
			ChangeParent = ChangeNode->Parent;
		}
		else if (nullptr != RightChild) // 삭제할노드의 RightChild가 존재한다면.
		{
			ChangeNode = RightChild->MinNode();    // NextNode임.
			ChangeChild = ChangeNode->RightChild;  // NextNode의 오른쪽자식.
			ChangeParent = ChangeNode->Parent;     // NextNode의 부모.
		}

		if (nullptr == ChangeNode) // NextNode가 null일경우. (루트노드만 있는경우)
		{
			MsgBoxAssert("말도안돼");
			return nullptr;
		}

		// 루트노드일 경우를 대비해서
		// 체인지 노드의 뒷정리를 하는 기간
		if (nullptr != ChangeParent)  //NextNode의 부모가 nullptr이 아니라면.
		{
			ChangeParent->ChangeChild(ChangeNode, ChangeChild);
			// 삭제할 노드를 삭제하기전에 NextNode가 먼저 NextNode와 자기 자식을 판별하여 교체를한다.
		}


		// 교체할 노드와 지워질 노드의 정보 교체를 한다.

		if (nullptr != ParentNode) // 부모가 null이아니라면. (현재 내가 루트가 아니라면)
		{
			ParentNode->ChangeChild(CurNode, ChangeNode); // 삭제할노드와 Next노드를 교체.
		}
		else
		{ // 삭제되는 노드가 루트일경우.
			ChangeNode->Parent = nullptr; // Next노드의 부모에 null을 넣고.
			Root = ChangeNode;            // 루트는 Next노드가 된다.
			// RootNode 
		}

		// 부모의 교체는 끝낫고 자식을 알려줘야한다.
		ChangeNode->LeftChild = LeftChild; // Next노드의 LeftChild에 내가가지고 있던 자식을 알려줌.
		if (nullptr != LeftChild)
		{
			LeftChild->Parent = ChangeNode;  // 그자식에게 부모가 Next노드임을 알림.
		}
		ChangeNode->RightChild = RightChild;
		if (nullptr != RightChild)
		{
			RightChild->Parent = ChangeNode;
		}

		if (nullptr != CurNode)  // 전부다 끝나고 안전삭제.
		{
			delete CurNode;
			CurNode = nullptr;
		}

		return NextNode;   // 반환 값은 Next노드.
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
		return end();
	}


	// 안들어가면 false리턴
	bool insert(const GameEnginePair<KeyType, ValueType>& _Pair)
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

	void FirstOrder()
	{
		Root->FirstOrder();
	}

	void MidOrder()
	{
		Root->MidOrder();
	}

	void LastOrder()
	{
		Root->LastOrder();
	}

private:
	MapNode* Root = nullptr;
};

