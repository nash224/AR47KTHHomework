// 055_ClassDeclaration.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//  클래스 전방선언 => 클래스의 경우는 이렇게 선언한다.
class Monster;

//  순환참조
//  선언과 구현의 분리
//  클래스 전방선언
//  우선 믿고 써 
class Player
{
public:
    int Hp = 100;
    int Att = 10;

public:
    //  몬스터를 알아야해
    void Attack(Monster* _Monster);/*
    {
        _Monster->Hp -= Att;
    }*/

    //  내부에서 다른 클래스의 내용을 사용하게되면,
    //  전방 선언을 해도 읽혀지지 않는다.
    //  호출된 클래스의 송성이 있는지 알아야겠다 <= 컴파일러가.
    void Heal(Monster* _Monster);
    //{  
    //    //  클래스의 속성이 있는가?
    //    //  클래스의 크기는 얼마인가
    //    //  클래스는 어떤 생성자를 가졌는가
    //    _Monster->Hp += 10;
    //}

private:

};

class Player;

class Monster
{
public:
    int Hp = 100;
    int Att = 10;

public:
    void Attack(Player* _Player);
    /*{
        this->Hp -= Att;
    }*/

    //  8바이트 함수의 반환 메모리(Player의 메모리)는 8바이트 주소값을 받아서 리턴한다.
    //  해당 클래스 내부에서 멤버변수나 멤버함수를 사용하지 않았기 때문에 필요가 없다.
    Player* Test(Player* _Player)
    {
        return _Player;
    }

    //  함수의 실행메모리를 정하려면 함수의 인자의 크기를 알아야한다.
    Player Test2(Player _Player)
    {
        return _Player;
    }

private:
     
};


int main()
{
    Player NewPlayer;
    Monster NewMonster;

    NewPlayer.Attack(&NewMonster);
    NewMonster.Attack(&NewPlayer);

    NewPlayer.Heal(&NewMonster);

    NewMonster.Test(&NewPlayer);

    NewMonster.Test2(NewPlayer);

}


void Player::Attack(Monster* _Monster)
{
    _Monster->Hp -= Att;
}


void Monster::Attack(Player* _Player)
{
    _Player->Hp -= Att;
}

void Player::Heal(Monster* _Monster)
{
    _Monster->Hp += Att;
}
