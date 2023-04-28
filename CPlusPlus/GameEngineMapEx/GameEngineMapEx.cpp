
#include <iostream>
#include <map>
#include <list>
//
//template<typename KEY, typename Data>
//class Pair 
//{
//
//};
//
//template<typename KEY, typename Data>
//class MyMap 
//{
//    class Node 
//    {
//        Pair<KEY, Data> ValuePair;
//    };
//    
//    Node Root;
//};

class GameEngineActor
{

};

class Pair
{
public:
    int first;
    std::list<GameEngineActor*> second;
};

class MyMap
{
    class Node
    {
    public:
        Pair ValuePair;
        // Pair<int, std::list<GameEngineActor*>> ValuePair;
    };

public:
    Node Root;
};

int main()
{
    //MyMap NewMap;

    //int& Key = NewMap.Root.ValuePair.first;
    //std::list<GameEngineActor*>& Value = NewMap.Root.ValuePair.second;

    // MyMap<int, std::list<GameEngineActor*>> NewMap;


    //std::map<int, 자료형>

    std::map<int, std::list<int>> AllActors;

     std::map<int, std::list<int>>::iterator FindIter = AllActors.find(0);

     // map의 데이터가 한개도 없다면 찾을수 없기때문에
     // 만든다음에 다시 Find하여 찾아내야하는데
     // 이런기능이 map안에 있다.
    if (AllActors.end() == AllActors.find(0))
    {
        AllActors.insert(std::make_pair(0, std::list<int>()));
        FindIter = AllActors.find(0);
    }

    // 배열처럼 쓰게되는데 []연산이 오퍼레이터 정의로 내려져있다.
    // 의미는 []해당하는 map이 없다면 생성하고 리턴하고. 있다면 그대로 리턴한다.
    // 어느경우에도 리턴할수있게 하는것.  위와같은 if문을 사용하지 않아도 된다.
    // 이용할수있는것은 이용하자.
    std::list<int>& NewList = AllActors[0];

    std::cout << "Hello World!\n";
}
