
#include <iostream>
#include <map>
#include <list>
#include "GameEngineMap.h"

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
    GameEngineDebug::LeckCheck();

    {
        GameEngineMap<int,int> Test;
        Test.insert(GameEnginePair<int, int>(10, rand()));
        Test.insert(GameEnginePair<int,int>(7, rand()));
        Test.insert(GameEnginePair<int,int>(15, rand()));
        Test.insert(GameEnginePair<int,int>(25, rand()));
        Test.insert(GameEnginePair<int,int>(17, rand()));
        Test.insert(GameEnginePair<int,int>(18, rand()));
        Test.insert(GameEnginePair<int,int>(2, rand()));
        Test.insert(GameEnginePair<int,int>(6, rand()));
        Test.insert(GameEnginePair<int,int>(5, rand()));
        Test.insert(GameEnginePair<int,int>(4, rand()));
        Test.insert(GameEnginePair<int,int>(9, rand()));
        Test.insert(GameEnginePair<int,int>(8, rand()));
        Test.insert(GameEnginePair<int,int>(1, rand()));


        GameEngineMap<char, int> Test2;
        Test2.insert(GameEnginePair<char, int>('d', rand()));
        Test2.insert(GameEnginePair<char, int>('a', rand()));
        Test2.insert(GameEnginePair<char, int>('5', rand()));
        Test2.insert(GameEnginePair<char, int>('g', rand()));
        Test2.insert(GameEnginePair<char, int>('8', rand()));
        Test2.insert(GameEnginePair<char, int>('h', rand()));
        Test2.insert(GameEnginePair<char, int>('1', rand()));
        Test2.insert(GameEnginePair<char, int>('y', rand()));
        Test2.insert(GameEnginePair<char, int>('o', rand()));
        Test2.insert(GameEnginePair<char, int>('m', rand()));
        Test2.insert(GameEnginePair<char, int>('p', rand()));
        Test2.insert(GameEnginePair<char, int>('w', rand()));
        Test2.insert(GameEnginePair<char, int>('z', rand()));


        {
            GameEngineMap<int, int>::iterator FindIter = Test.find(15);
            GameEngineMap<int, int>::iterator NextIter = Test.erase(FindIter);
        }

        GameEngineMap<int, int>::iterator StartIter = Test.begin();
        GameEngineMap<int, int>::iterator EndIter = Test.end();
        GameEngineMap<char, int>::iterator StartIter2 = Test2.begin();
        GameEngineMap<char, int>::iterator EndIter2 = Test2.end();

        // <int,int>
        std::cout << "<int, int>그냥 돌리기" << std::endl;
        for (; StartIter != EndIter; ++StartIter)
        {
            std::cout << StartIter->first << std::endl;
        }

        std::cout << "<int, int>전위 순회" << std::endl;
        Test.FirstOrder();
        std::cout << "<int, int>중위 순회" << std::endl;
        Test.MidOrder();
        std::cout << "<int, int>후위 순회" << std::endl;
        Test.LastOrder();


        // <char,int>
        std::cout << "<char, int>그냥 돌리기" << std::endl;
        for (; StartIter2 != EndIter2; ++StartIter2)
        {
            std::cout << StartIter2->first << std::endl;
        }

        std::cout << "<char,int>전위 순회" << std::endl;
        Test2.FirstOrder();
        std::cout << "<char,int>중위 순회" << std::endl;
        Test2.MidOrder();
        std::cout << "<char,int>후위 순회" << std::endl;
        Test2.LastOrder();
    }

    return 1;

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

        std::map<int, int>::iterator FindIter = Test.find(1);
        std::map<int, int>::iterator NextIter = Test.erase(FindIter);

        int a = 0;

        // 탐색을 용이하게 하기 위해서 사용한다.
        // 사용성이 좋아요.

        //for (const std::pair<int, int>& Value : Test)
        //{

        //}

        // std::pair<int, int> Pair;
        // int& Value = Pair;

        std::map<int, int>::iterator StartIter = Test.begin();
        std::map<int, int>::iterator EndIter = Test.end();

        // for (; StartIter != EndIter; ++StartIter)
        // {
            // Key 
            // StartIter->first = 20;

            // std::cout << StartIter->first << std::endl;
            // Value
            //StartIter->second = 60;
        // }

        //for (const std::pair<int, int>& Value : Test)
        //{
        //    Value.first = 20;
        //}
    }

}
