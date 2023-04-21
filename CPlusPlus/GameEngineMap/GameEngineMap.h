#pragma once
#include <GameEngineBase/GameEngineDebug.h>

class iterator;

typedef int KeyType;
typedef int ValueType;

// template <typename KeyType, typename ValueType>
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

// ���� :
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
		GameEnginePair Pair;

		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}

		void ChangeChild(MapNode* _OldChild, MapNode* _NewChild)
		{
			if (_OldChild == LeftChild)
			{
				LeftChild = _NewChild;
				if (nullptr != _NewChild)
				{
					_NewChild->Parent = this;
				}
				return;
			}

			if (_OldChild == RightChild)
			{
				RightChild = _NewChild;
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
		// ��Ʈ���� ���� ���� �ڽĵ��� ���ʴ�� ���� ��ȸ�ϰ� ������ �ټ�ȸ������
		//  �ٽ� �ϳ����ö���鼭 �����ʵ� �Ȱ��� üũ.
		void FirstOrder() 
		{
			std::cout << Pair.first << std::endl;
			if (nullptr != LeftChild)  // left�� ������ �����
			{
				LeftChild->FirstOrder();
			}
			if (nullptr != RightChild) // right�� ������ �����.
			{
				RightChild->FirstOrder();
			}
		}
		// Min��带 ���� ����Ѵ����� �� ���� min��带 ã�� ����ϴ� ����
		// std::map�� ����� �̰�.
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
		// min��带 ������� ����ϰ� �� �θ��� �������� �γ�带 ã�� ����ϰ� ��ĭ�� �ö���鼭 ��ȸ
		// ������ ���� �������� ��ȸ�ϰ� �����ʵ� �����ϰ� ��ȸ�ϸ� ��ĭ���ö���� ����.

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

		void LastOrderdelete() // ���������� ����Ʈ �ϰڴ�.
		{
			MapNode* CurNode = this;
			
			if (nullptr == CurNode) // ��尡 �Ѱ��� ������ rootnode�� null�϶�.
			{
				return;
			}

			if (nullptr != LeftChild) 
			{
				LeftChild->LastOrderdelete(); //���� �ڽ��� ������ �ݺ�.
			}

			if (nullptr != RightChild)
			{
				RightChild->LastOrderdelete(); // ������ �ڽ��� ������ �ݺ�.
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
		// ���漱��
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
			MsgBoxAssert("�ص带 �����Ϸ��� �߽��ϴ�.");
		}

		MapNode* CurNode = _EraseIter.Node;
		MapNode* ParentNode = CurNode->Parent;
		MapNode* RightChild = CurNode->RightChild;
		MapNode* LeftChild = CurNode->LeftChild;

		MapNode* ChangeNode = nullptr;
		MapNode* ChangeNodeParent = nullptr;
		MapNode* NextNode = CurNode->NextNode();

		if (true == CurNode->IsLeaf())
		{
			ParentNode->ChangeChild(CurNode, nullptr);
			if (nullptr != CurNode)
			{
				delete CurNode;
				CurNode = nullptr;
			}
			return NextNode;
		}


		// ��ü�� ���� ����� ������ ��� ���� ����ϼ� ����.
		MapNode* ChangeChild = nullptr;
		MapNode* ChangeParent = nullptr;

		if (nullptr != LeftChild)
		{
			ChangeNode = LeftChild->MaxNode();
			ChangeChild = ChangeNode->LeftChild;
			ChangeParent = ChangeNode->Parent;
		}
		else if (nullptr != RightChild)
		{
			ChangeNode = RightChild->MinNode();
			ChangeChild = ChangeNode->RightChild;
			ChangeParent = ChangeNode->Parent;
		}

		if (nullptr == ChangeNode)
		{
			MsgBoxAssert("�����ȵ�");
			return nullptr;
		}

		// ��Ʈ����� ��츦 ����ؼ�
		// ü���� ����� �������� �ϴ� �Ⱓ
		if (nullptr != ChangeParent)
		{
			ChangeParent->ChangeChild(ChangeNode, ChangeChild);
		}


		// ��ü�� ���� ������ ����� ���� ��ü�� �Ѵ�.

		if (nullptr != ParentNode)
		{
			ParentNode->ChangeChild(CurNode, ChangeNode);
		}
		else
		{
			ChangeNode->Parent = nullptr;
			Root = ChangeNode;
			// RootNode 
		}


		ChangeNode->LeftChild = LeftChild;
		if (nullptr != LeftChild)
		{
			LeftChild->Parent = ChangeNode;
		}
		ChangeNode->RightChild = RightChild;
		if (nullptr != RightChild)
		{
			RightChild->Parent = ChangeNode;
		}

		if (nullptr != CurNode)
		{
			delete CurNode;
			CurNode = nullptr;
		}

		return NextNode;
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


	// �ȵ��� false����
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

