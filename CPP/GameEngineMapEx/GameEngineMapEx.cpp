// GameEngineMapEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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

    // std::map<int, std::list<int>>::iterator FindIter = AllActors.find(0);

    //if (AllActors.end() == AllActors.find(0))
    //{
    //    AllActors.insert(std::make_pair(0, std::list<int>()));
    //    FindIter = AllActors.find(0);
    //}

    std::list<int>& NewList = AllActors[0];

    std::cout << "Hello World!\n";
}