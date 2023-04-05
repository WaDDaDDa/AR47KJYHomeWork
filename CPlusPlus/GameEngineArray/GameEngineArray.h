#pragma once

typedef int DataType;  // int�� DataType�� Ī�ϰڴ�.

// ���� :
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
		// ArrPtr = new int[100];
	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		DataType* Ptr = new DataType[_Other.ArrCount];

		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			Ptr[i] = _Other.ArrPtr[i];                  // �׾ȿ� ���� �迭 ���� �ִ´�.
		}

		// ���׿�����. 
		//ArrCount >= _Value ? true�������� ���ų� �۴� : false�������� ũ��;
		ArrPtr = Ptr;
		ArrCount = _Other.ArrCount;              // ArrCount�� _Value�� �ִ´�.

		//ArrCount = _Other.ArrCount; // _Other.ArrCount�� ���� ArrCount�� ����.
		//ArrPtr = _Other.ArrPtr;     // _Other.ArrPtr�� ArrPtr�� ����.

		return *this;
	}

	size_t Count()
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

	void ReSize(int _Value)
	{
		// ������ ArrPtr�� heap�� ����.
		DataType* Ptr = new DataType[_Value];  // ���ο�� �����. Ptr���� heap�� ����������
		// �Լ��� �����鼭 �Ҹ�ɰ�.
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
		// Ptr���� ����� Heap������ ������ �ʴ� ����.
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

