#pragma once

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

		MapNode* NextNode()
		{
			return nullptr;
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

