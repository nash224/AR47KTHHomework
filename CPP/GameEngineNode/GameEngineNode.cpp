// GameEngineNode.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameEngineConsole/GameEngineArray.h>
#include <conio.h>

// 배열형
//      노드형
//   노드형에서 2가지가 있는데.
// 선형 트리형

// 노드 형태라고 부르는 굉장히 많이 
// 사용되는 방식이 존재하는데

// 어떤 클래스가 자신내부에 자기자신의 
// 참조형(보통은 포인터)을 n개 들고 있으면
// 그걸 노드형식이라고 합니다.


// 맵의 한 지역
// 하이데의 패허에서는 
// 청의성당
// 하이데의 큰 불탑   
// 매듀라

class MapZone
{
public:
    MapZone* SelectNext()
    {
        system("cls");
        printf_s("현재 이곳은 %s 입니다.\n", GetName());
        printf_s("어디로 가시겠습니까?\n");

        for (int i = 0; i < LinkZone.Count(); i++)
        {
            printf("%d. %s\n", i + 1, LinkZone[i]->GetName());
        }

        int Select = _getch();
        int SelectIndex = Select - '1';

        if (SelectIndex >= LinkZone.Count())
        {
            return this;
        }

        return LinkZone[SelectIndex];

    }

    const char* GetName()
    {
        return Name;
    }

    void SetName(const char* _Name)
    {
        Name = _Name;
    }

    void Link(MapZone* _OtherZone)
    {
        if (nullptr == _OtherZone)
        {
            return;
        }

        LinkZone.ReSize(LinkZone.Count() + 1);
        LinkZone[LinkZone.Count() - 1] = _OtherZone;

        _OtherZone->LinkZone.ReSize(_OtherZone->LinkZone.Count() + 1);
        _OtherZone->LinkZone[_OtherZone->LinkZone.Count() - 1] = this;

    }

private:
    const char* Name = nullptr;
    GameEngineArray<MapZone*> LinkZone;
};

typedef int DataType;

class Node
{
public:
    Node(const DataType& _Value)
        : Value(_Value)
    {
    }

    int GetValue()
    {
        return Value;
    }

    Node* GetNext()
    {
        return Next;
    }

    Node* GetPrev()
    {
        return Prev;
    }


    void NextLinkPointer(Node* _Next)
    {
        Next = _Next;
        _Next->Prev = this;
    }

    void NextLinkRef(Node& _Next)
    {
        Next = &_Next;
        _Next.Prev = this;
    }

private:
    // 단방향 노드
    Node* Next = nullptr;
    // 양방향
    Node* Prev = nullptr;

    DataType Value;
};

int main()
{
    {
        Node Node1 = 0;
        Node Node2 = 1;
        Node Node3 = 2;
        Node Node4 = 3;
        Node Node5 = 4;

        Node1.NextLinkRef(Node2);
        Node2.NextLinkRef(Node3);
        Node3.NextLinkRef(Node4);
        Node4.NextLinkRef(Node5);

        Node* CurNode = &Node5;
        while (nullptr != CurNode)
        {
            printf_s("%d\n", CurNode->GetValue());
            CurNode = CurNode->GetPrev();


            //const char* Name = CurMap->GetName();
            //printf_s("%s\n", CurMap->GetName());
            //CurMap = CurMap->GetLink();
        }

        return 1;

    }

    {
        // 100
        MapZone Map1;
        // 200
        MapZone Map2;
        // 300
        MapZone Map3;
        // 400
        MapZone Map4;

        MapZone Map5;


        Map1.SetName("하이데의 폐허");
        Map2.SetName("청의성당");
        Map3.SetName("매듀라");
        Map4.SetName("하이데의 큰 불탑");
        Map5.SetName("숨겨진 항구");

        Map1.Link(&Map2);
        Map1.Link(&Map4);
        Map1.Link(&Map3);

        Map2.Link(&Map5);

        // 100번지
        MapZone* CurMap = &Map1;
        while (nullptr != CurMap)
        {
            CurMap = CurMap->SelectNext();

            //const char* Name = CurMap->GetName();
            //printf_s("%s\n", CurMap->GetName());
            //CurMap = CurMap->GetLink();
        }
    }

}
