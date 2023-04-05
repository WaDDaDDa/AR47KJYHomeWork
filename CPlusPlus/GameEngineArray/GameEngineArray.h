#pragma once

//typedef int DataType;  // template�� class�� ����鼭 ����.

// ���� :
template <typename DataType>
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(size_t _Value)    // ������
		: ArrPtr(new DataType[_Value])  // heap������ _Value��ŭ�� �迭�� ����� ArrPtr�� �޴´�.
		, ArrCount(_Value)              // _Value ��ŭ�� ArrCount�� �޴´�.
	{
		// ArrPtr = new int[100];  // �ش� ������ ���� �ʱ�ȭ ���ٴ� �̴ϼȶ���� ���Ѱ� ��õ.
	}

	~GameEngineArray() // �Ҹ��� -> �������Ű� ���۵ȴ�.
	{
		if (nullptr != ArrPtr) //���� ����
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other) // =�� ��� �����
	{
		DataType* Ptr = new DataType[_Other.ArrCount];

		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			Ptr[i] = _Other.ArrPtr[i];                  // �׾ȿ� ���� �迭 ���� �ִ´�.
		}
		ArrPtr = Ptr;
		ArrCount = _Other.ArrCount;              // ArrCount�� _Value�� �ִ´�.
		return *this;
	}

	inline size_t Count() const
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
	{
		DataType& Result = ArrPtr[_Index];
		return Result;
	}

	// 20�� ����.
	// ���� ������ �Ẹ�ø� �����̴ϴ�.
	// ������ �Ҵ�� �迭�� �˰� �ִ°��� 
	// ���Ҹ� ����� �ȵȴ�.
	// ������ �ִ� ������ ������ �迭�� �����Ѵ��� �����ؾ� �Ѵ�.
	
	/*  ���� ReSize �Լ�.  �����̰� �����͸� ���� ����� ���ο� �迭�� ����� �Լ��� �Ǿ��ִ�.
	void ReSize(int _Value)
	{

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = new DataType[_Value];
		ArrCount = _Value;
	}*/

	// ������ ��������ִ°���
	// ���θ���Ϳ� �־��ְ�
	// �������� ������ �Ѵ�.
	// ���ο�� ���� ������ְ�.
	// �� ��������ſ� ���������͸� �־��ְ�
	// �����Ŵ� ����.

	inline void ReSize(int _Value)
	{
		// ������ ArrPtr�� heap�� ����.
		DataType* Ptr = new DataType[_Value];  // ���ο� �������� ����� Ptr�� �޴´�.
		if (nullptr == Ptr) // Ptr�� nullüũ.
		{
			return;
		}

		for (size_t i = 0; i < _Value; i++)
		{
			Ptr[i] = ArrPtr[i];                  // �׾ȿ� ���� �迭 ���� �ִ´�.
		}

		if (nullptr != ArrPtr) // ���� �迭 ���� ����
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = Ptr;               // null�� ����Ű�� �ִ� ArrPtr�� Ptr�� ����Ű���� �Ѵ�.
		// ���� Ptr���� ����� Heap������ ������ �ʴ� ����.
		// ArrPtr�� Ptr�� ���������� ����Ű�� �ִµ� Ptr�� ����Ű�� �ִ� ������ �����
		// ArrPtr�� ����Ű�� ������ �������°�.
		// Ptr�� �� �Լ����� ����� �����̹Ƿ� �Լ��� ������ ������ �������.
		ArrCount = _Value;              // ArrCount�� _Value�� �ִ´�..
	}


protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

