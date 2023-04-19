
#include <iostream>
#include <map>
#include <list>
#include "GameEngineMap.h"

// Map은 트리구조를 가진다.
// 노드 연관형 자료구조이다. (컨테이너)
// Leftchild와 Rightchild가 있는데 왼쪽이 작은key  오른쪽이 큰key이다.
// 그래서 이 법칙을 생각해보면.
// Map의 가장 작은 key (int로 생각해보면 0) 에 접근하려면 Leftchild에 다른 노드를 가리키지 않는곳이
// 가장작다.

template<typename DataType0, typename DataType1>
void TestValue(DataType0 _Data0, DataType1 _Data1)
{
}

class Item
{

};

class Inven
{
public:
    void AddItem(Item* Item);

    //void AddWeapon(Item* Item);
    //void AddArmor();
    //void AddPotion();
    //void AddQuestItem();
};

int main()
{
    {
        std::list<int> Value;
        Value.push_back(20);
        Value.push_back(30);

        for (int& Test : Value)
        {
            // Test = 내부의 변수;
            Test = 50;
        }

        //for (std::list<int>::iterator Iter : Value)
        //{
        //}

        int a = 0;
    }

    {
        std::pair<int, int> NewPair;
        NewPair.first;
        NewPair.second;


        std::map<int, int> Test;

        std::pair<std::map<int, int>::iterator, bool> Value0
            = Test.insert(std::pair<int, int>(5, rand()));

        // 키가 겹칠때는 무시하면서 리턴해주는게 정상적으로 들어간 노드를 리턴해준다.

        std::pair<std::map<int, int>::iterator, bool> Value7
            = Test.insert(std::pair<int, int>(5, rand()));

        if (Value7.second == false)
        {
            int a = 0;
            // 같은 키를 가진 녀석을 넣어줬다.
        }

        std::pair<std::map<int, int>::iterator, bool> Value1
            = Test.insert(std::pair<int, int>(4, rand()));
        std::pair<std::map<int, int>::iterator, bool> Value2
            = Test.insert(std::pair<int, int>(7, rand()));
        std::pair<std::map<int, int>::iterator, bool> Value3
            = Test.insert(std::pair<int, int>(1, rand()));
        std::pair<std::map<int, int>::iterator, bool> Value4
            = Test.insert(std::pair<int, int>(2, rand()));
        std::pair<std::map<int, int>::iterator, bool> Value5
            = Test.insert(std::pair<int, int>(15, rand()));

        std::map<int, int>::iterator FindIter = Test.find(15);

        // 탐색을 용이하게 하기 위해서 사용한다.
        // 사용성이 좋아요.

        //for (const std::pair<int, int>& Value : Test)
        //{

        //}

        // std::pair<int, int> Pair;
        // int& Value = Pair;

        std::map<int, int>::iterator StartIter = Test.begin();
        std::map<int, int>::iterator EndIter = Test.end();

        for (; StartIter != EndIter; ++StartIter)
        {
            // Key 
            // StartIter->first = 20;

            std::cout << StartIter->first << std::endl;
            // Value
            //StartIter->second = 60;
        }

        //for (const std::pair<int, int>& Value : Test)
        //{
        //    Value.first = 20;
        //}
    }

    {
        GameEngineMap Test;
        Test.insert(GameEnginePair(5, rand()));
        Test.insert(GameEnginePair(4, rand()));
        Test.insert(GameEnginePair(7, rand()));
        Test.insert(GameEnginePair(1, rand()));
        Test.insert(GameEnginePair(2, rand()));
        Test.insert(GameEnginePair(15, rand()));

        int a = 0;

        GameEngineMap::iterator FindIter = Test.find(15);

        FindIter->second = 20;

        GameEngineMap::iterator StartIter = Test.begin();
        GameEngineMap::iterator EndIter = Test.end();

        for (; StartIter != EndIter; ++StartIter)
        {
            std::cout << StartIter->first << std::endl;
        }
    }
}

