// GameEngineVector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
// stl자료구조 입니다.
#include <vector>
#include <GameEngineBase/GameEngineDebug.h>

// vector는 배열(GameEngineArray)을 대체합니다. 
// 조금 특징이 다릅니다.

// vector는 시퀸스 배열형 자료구조이다.

// 스퀸스는 자료를 넣는순서대로 자료가 할당되는것이다.
// 연관은 순서나 구조가 바뀌면 연관.
// 어댑터는.

// 일반적인 배열 바로 접근이 가능하다.
// [][][][][][][][][][접근]

// 벡터 10개를 만들고도
// [][][][][][][][][][]

// vector에는 우리가 만들었던 GameEngineArray에는 없는 Capacity라는 값이 존재한다.
// CapaCity는 만들고자하는 배열의 전체크기를 말하는 것이고
// vector에서 size는 실제 값이 들어있는 크기를 말하게된다 (= 원소의 크기 라고한다)
// 예를 들어 Capacity가 10으로 지정해서 배열을 만들게 되면
// 초기에는 데이터가 아무것도 없을수도있지만 배열크기는 10인것이다.
// 그래서 push_back을 이용해서 배열크기에 원소를 채워넣게 되는데 배열크기를 넘지않는다면
// 할당 재할당 같은 과정을 거치지않고 값을 채워넣을수있게 되는것이다./




// typedef int DataType;

template<typename DataType>
class MyVector
{

public:
    MyVector()
    {

    }

    void push_back(const DataType& _Value)
    {
        //  0           0
        // 배열크기가 감당할수 있나?
        if (Size + 1 > Capacity)
        {
            // 더 크게 할당하자.
            reserve((Capacity + 1) * 1.5);
            // 확장해야 합니다.
        }

        ArrData[Size] = _Value;
        ++Size;
    }

    void reserve(size_t _Value)
    {
        DataType* NewPtr = new DataType[_Value];
        size_t CopySize = _Value < Capacity ? _Value : Capacity;

        for (size_t i = 0; i < CopySize; i++)
        {
            NewPtr[i] = ArrData[i];
        }

        if (nullptr != ArrData)
        {
            delete[] ArrData;
            ArrData = nullptr;
        }

        ArrData = NewPtr;
        Capacity = _Value;
    }

    size_t size()
    {
        return Size;
    }

    size_t capacity()
    {
        return Capacity;
    }

    DataType& operator[](size_t _Index) const
    {
        if (Size <= _Index)
        {
            MsgBoxAssert("인덱스를 오버하여 벡터를 사용하려고 했습니다.");
        }

        return ArrData[_Index];
    }

private:
    // 배열의 크기
    size_t Capacity = 0;
    // 넣어준 원소의 크기
    size_t Size = 0;

    DataType* ArrData = nullptr;
};

//class PArray 
//{
//    std::vector<>
//};

int main()
{

    {
        MyVector<int> Test;

        Test.reserve(10);    // capacity 에 10을 지정하는 사용법.
        // 이렇게 vector는 사용할때 reserve를 통해 배열의 크기를 지정해서 사용하게 된다.



        for (size_t i = 0; i < 10; i++)
        {
            Test.push_back(i);
            printf("Capacity %d\n", Test.capacity());
            printf("Size %d\n", Test.size());
        }

        for (size_t i = 0; i < Test.size(); i++)
        {
            printf("Value %d\n", Test[i]);
        }

        printf_s("size : %d", (int)Test.size());
    }

    return 1;

    {
        std::vector<int> Test;

        Test.reserve(10);
        Test.push_front;
        // 배열의 가장처음에 push_front를 하려면.
        // 배열의크기가 1 더큰 배열을 새로 만들고.
        // 그안에 push프론트의 값을 먼저넣고
        // 그이후에 원래있던 배열의 값들을 넣고.
        // 원래의 배열은 삭제한다음에
        // 원래 배열이 가리키던 포인터를 새로만든 배열을 가리키도록 한다.

        // randomacces 했던 값들이 전부 바뀌게 되는 대참사가 발생하기도 함.
        // 하지만 못할 이유는 없지 않은가?


        for (size_t i = 0; i < 10; i++)
        {
            Test.push_back(i);
            printf("Capacity %d\n", Test.capacity());
            printf("Size %d\n", Test.size());
        }

        //for (size_t i = 0; i < Test.size(); i++)
        //{
        //    printf("%d\n", Test[i]);
        //}

        // printf_s("size : %d", (int)Test.size());

        return 1;
        // push_back 10번을 한것과 똑같은 크기로 만들어준다.
        // 벡터에서는 이미 10개의 int를 공간을 확장하면서
        // 원소 자체도 넣어주는걸 resize라고 합니다.
        Test.resize(10);

        // 벡터는 넣는다는 개념이고. 
        // 최초 아무것도 없다.
        // Test
        // 내부에서 벌어지고 있으니까.
        // 이런 사용법은 vector를 사용하는 최악의 사용법으로 불린다.
        Test.push_back(0);
        // [0]
        Test.push_back(0);
        // [0][0]
        Test.push_back(0);
        // [0][0][0]
        Test.push_back(0);
        // [0][0][0][0]

        printf_s("size : %d", (int)Test.size());
    }

    // Test.reserve(10);

    // Test.resize(10);
}
