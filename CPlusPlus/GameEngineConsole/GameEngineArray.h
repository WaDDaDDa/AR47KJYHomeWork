#pragma once
#include <GameEngineBase/GameEngineDebug.h>
// #include <Program Files/Adobe/Adobe Creative Cloud Experience/>

// typedef int DataType;

template<typename DataType>
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	GameEngineArray()
	{
	}


	// constrcuter destructer
	GameEngineArray(size_t _Value)
	{
		if (0 >= _Value)
		{
			MsgBoxAssert("0ũ���� �迭�� ����� �����ϴ�.");
		}

		ReSize(_Value);
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
		// ���� ������ �մϴ�.
		//ArrCount = _Other.ArrCount;
		//ArrPtr = _Other.ArrPtr;

		// ������ �޸𸮸� ����� 
		// ���� ������ �մϴ�.
		ReSize(_Other.ArrCount);
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			 ArrPtr[i] = _Other[i];
		}

		return *this;
	}

	size_t Count() 
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index) const
	{
		return ArrPtr[_Index];
	}

	void ReSize(size_t _Value) 
	{
		// 20�� ����.
		// ���� ������ �Ẹ�ø� �����̴ϴ�.

		// ������ �Ҵ�� �迭�� �˰� �ִ°��� 
		// ���Ҹ� ����� �ȵȴ�.

		// ������ �ִ� ������ ������ �迭�� �����Ѵ��� �����ؾ� �Ѵ�.

		DataType* NewPtr = new DataType[_Value];
		size_t CopySize = _Value < ArrCount ? _Value : ArrCount;

		for (size_t i = 0; i < CopySize; i++)
		{
			NewPtr[i] = ArrPtr[i];
		}

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = NewPtr;
		ArrCount = _Value;
	}

protected:

private:
	size_t ArrCount = 0;
	DataType* ArrPtr = nullptr;

};

