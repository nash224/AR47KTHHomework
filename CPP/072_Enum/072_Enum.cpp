// 072_Enum.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 컴파일되면 int로 변형
// 자동으로 index가 붙음
//enum GameJobType
//{
//    FIghter,
//    Mage,
//    Archer,
//    Paladin
//};

// 암시적 형변환이 다 막힘.
// 클래스 이넘은 int가 될 수 없음
enum class GameJobType
{
    FIghter = 5, // 5
    Mage,        // 6
    Archer,      // 7
    Paladin      // 8
};

// 0 전사
// 1 마법사
// 2 궁수
// 3 성기사

class FightUnit
{
    GameJobType JobType;

public:

    void SetJobType(GameJobType _Type)
    {
        JobType = _Type;
    }
};

int main()
{
    FightUnit NewUnit;

    // 직업을 할당한다
    NewUnit.SetJobType(GameJobType::Archer);

    // 형변환해서 변수를 받아 볼 수 있다.
    int Value = (int)GameJobType::Archer;
}