

#include <iostream>
\

class Player
{
    //  클래스 문법에서 속성과 행동을 외부로 공개할지를 결정할 수 있다.
    //  이것을 접근제한 지정자라고 한다.


    //                 내부코드     자식코드     외부
public:                // 공개        공개      공개
    int Att = 10;
    int Def = 2;
protected:             // 공개        공개      비공개
    int Hp = 100;
private:               // 공개        비공개    비공개
    int Speed = 3;
};

class Monster
{
    //private: // 디폴트 접근제한 지정자는 private이다.
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int Speed = 3;
};

int main()
{
    Monster Newmonster;

    //Newmonster.

    Player NewPlayer = Player();
    NewPlayer.Att;
}