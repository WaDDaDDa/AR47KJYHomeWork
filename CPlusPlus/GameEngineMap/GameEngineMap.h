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

// ���� :
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

		// �������� ������ �ؾ�����
		void Release()
		{
			if (nullptr == Parent) // �θ� null�ΰ�� �״�� ����. (��Ʈ����ϰ�쿡 �ش���). 
			{
				return;   // �״�� ���ϵ�. (������ ��尡 ��Ʈ ����¶�.)
			}

			if (this == Parent->LeftChild)   // ������ ���� �� �θ��� ������ ��. (���� ���������� Ȯ���ϱ�����)
			{
				Parent->LeftChild = nullptr;  // ���� �����ڽ��̶�� �θ��� LeftChild������ null �β��������.
				return;
			}

			if (this == Parent->RightChild)   // ������ ���� ������ �ڽ��̸�
			{
				Parent->RightChild = nullptr;  // �θ��� RightChild ������ null�� ���������.
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


	// ��尡 �������� ����� ���� �����غ���.
	// 1. �ڽ��� �ϳ������� ��尡 ��������.
	// 2. �ڽ��� �����̵� �������̵� �Ѱ� �ִ� ��尡 ��������.
	// 3. �ڽ��� ���ʰ� ������ �Ѵ� �ִ� ��尡 ��������.

	// 1. �ǰ��   �ڽ��� �ϳ��� ���°�. �ڽ��� �����϶��̴�. �׳� �������� ����� ����.
	// �ڽ��� �ؽ�Ʈ�� �����ϰ� �ڽ��� �������� �ؽ�Ʈ�� ��ȯ.

	// 2 ���� ���ʿ��� �ڽ��� �ִ� ���.
	// �����ڽ��� �ڽ��� ��ġ�� ��ü�Ǿ� ����ǰ� ������ְ� �ڽ��� ��������. �׸��� �����ڽ��� ��ȯ.
	// �����ڽ��̴��� ������ �ڽ��� �θ�� ����ǰ� ��������.
	// ���������� �θ��� �������ڽ����� �����ڽ������� �Ǻ��ϰ� �����ڽ��̸� �����ڽĿ� ����ǰ�
	// �������̸� ������ �ڽĿ� ����ǰ�.

	// �ڽ��� ����� �ڽ��� nextnode�� �ڽ��� �ڸ��� ��ü���Ѿ���
	// 1. ������ �ڽ��� �θ𿡰� �ڽ��� �ؾ�޶���Ѵ�.
	// 2. ���� next��带 ã�´�.
	// 3. ���� next ����� �θ𿡰� ����next��带 �ؾ�޶���Ѵ�.
	// 4. ���� next ����� �θ𿡰� ���� next����� �ڽ��� �˷��ش�.
	// 8. ���� next�� ����� �ڽ��� �θ� ���� next����� �θ�� �˷��ش�
	// 5. ���� next ��忡�� ���� �θ� �˷��ش�.
	// 6. ���� �θ𿡰� ���� next��带 �ڽ����� �˷��ش�.
	// 7. ���� next ��忡�� ���� �ڽ��� �˷��ش�.
	// 9. ���� �ڽĳ�忡 next��带 �θ�� �˷��ش�.

	// 2���� �����ʿ��� �ڽ��� �ִ� ���.
	//


	// 3. ���� ������ �ڽ��� ����ִ� ��尡 ��������.

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
		MapNode* NextNode = CurNode->NextNode();

		if (true == CurNode->IsLeaf())  // 1���� ��� �Ϸ�. (���ʿ����� �Ѵ� null�����Ǻ�)
		{
			CurNode->Release(); // ������ ����� �θ𿡰� �ڽ��� ������.
			delete CurNode;     //  ���������带 �����.
			CurNode = nullptr;  // null�� ����
			return NextNode;    // ���� ������ �� ����� next�� ��ȯ.
		}
		// 2���� ��쿡�� ���ʿ��� �ڽ��� �������.
		else if (nullptr == RightChild)  // �������� null�̸� ���ʿ��� �ڽ����ִ�.
		{
			CurNode->Release();     // �θ� �ڽ��� �����Ű� �ڽ��� �θ� ����ϴ���.
			CurNode->Parent->LeftChild = LeftChild; //������ ��尡 ����ϴ� �θ��� �����ڽĿ� ������ ���� ���� �ڽ��� �����ش�.
			CurNode->LeftChild->Parent = ParentNode; // ������ ����� ���� �ڽĳ���� �θ� ���� ������ ���ΰ� ���� �θ�� ���ش�.
			delete CurNode;
			CurNode = nullptr;
			return NextNode;
		}
		// 2���� ��쿡�� �����ʿ��� �ڽ��� �������.
		else if (nullptr == LeftChild) // ������ null�̸� �����ʿ��� �ڽ����ִ�.
		{
			// �ڽ��� ����� �ڽ��� nextnode�� �ڽ��� �ڸ��� ��ü���Ѿ���

			// 1. ������ �ڽ��� �θ𿡰� �ڽ��� �ؾ�޶���Ѵ�.
			CurNode->Release();     // �θ� �ڽ��� �����Ű� �ڽ��� �θ� ����ϴ���.
			// 2. ���� next��带 ã�´�.
			MapNode* CurNextNode = CurNode->NextNode();
			// 3. ���� next ����� �θ𿡰� ����next��带 �ؾ�޶���Ѵ�.
			CurNextNode->Release();
			// 4. ���� next ����� �θ𿡰� ���� next����� �ڽ��� �˷��ش�.
			// 4-1 next����� �ڽ��� ������ ������ �ڽĸ� �ִ�.
			CurNextNode->Parent = CurNextNode->RightChild;
			// 8. ���� next�� ����� �ڽ��� �θ� ���� next����� �θ�� �˷��ش�
			CurNextNode->RightChild->Parent = CurNextNode->Parent;
			// 5. ���� next ��忡�� ���� �θ� �˷��ش�.
			CurNextNode->Parent = ParentNode;
			// 6. ���� �θ𿡰� ���� next��带 �ڽ����� �˷��ش�.
			CurNode->Parent->RightChild = CurNextNode;
			// 7. ���� next ��忡�� ���� �ڽ��� �˷��ش�.
			CurNextNode->RightChild = RightChild;
			// 9. ���� �ڽĳ�忡 next��带 �θ�� �˷��ش�.
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

	MapNode* Root = nullptr;
};

