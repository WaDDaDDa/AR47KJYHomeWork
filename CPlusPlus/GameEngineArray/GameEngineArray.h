#pragma once

typedef int DataType;  // int를 DataType로 칭하겠다.

// 설명 :
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
			Ptr[i] = _Other.ArrPtr[i];                  // 그안에 기존 배열 값을 넣는다.
		}

		// 삼항연산자. 
		//ArrCount >= _Value ? true기존보다 같거나 작다 : false기존보다 크다;
		ArrPtr = Ptr;
		ArrCount = _Other.ArrCount;              // ArrCount에 _Value를 넣는다.

		//ArrCount = _Other.ArrCount; // _Other.ArrCount의 값을 ArrCount에 대입.
		//ArrPtr = _Other.ArrPtr;     // _Other.ArrPtr을 ArrPtr에 대입.

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

	// 20줄 안팍.
	// 삼항 연산자 써보시면 좋을겁니다.
	// 기존의 할당된 배열을 알고 있는것은 
	// 섣불리 지우면 안된다.
	// 기존의 있던 값에서 현재의 배열이 복사한다음 삭제해야 한다.
	
	/*  기존 ReSize 함수.  지금이건 데이터를 전부 지우고 새로운 배열을 만드는 함수가 되어있다.
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

	// 기존에 만들어져있는것을
	// 새로만든것에 넣어주고
	// 기존것을 지워야 한다.
	// 새로운걸 먼저 만들어주고.
	// 그 만들어진거에 기존데이터를 넣어주고
	// 기존거는 삭제.

	void ReSize(int _Value)
	{
		// 기존의 ArrPtr이 heap에 존재.
		DataType* Ptr = new DataType[_Value];  // 새로운걸 만든다. Ptr또한 heap에 존재하지만
		// 함수가 끝나면서 소멸될것.
		if (nullptr == Ptr) // Ptr의 null체크.
		{
			return;
		}

		for (size_t i = 0; i < _Value; i++)
		{
			Ptr[i] = ArrPtr[i];                  // 그안에 기존 배열 값을 넣는다.
		}

		if (nullptr != ArrPtr) // 기존 배열 안전 제거
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = Ptr;               // null을 가리키고 있던 ArrPtr을 Ptr을 가르키도록 한다.
		// Ptr에서 선언된 Heap영역을 지우지 않는 이유.
		// ArrPtr과 Ptr이 같은구역을 가르키고 있는데 Ptr이 가르키고 있는 영역을 지우면
		// ArrPtr이 가르키는 영역이 지워지는것.
		// Ptr은 이 함수내에 선언된 변수이므로 함수가 끝나면 변수는 사라진다.
		ArrCount = _Value;              // ArrCount에 _Value를 넣는다..
	}


protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

