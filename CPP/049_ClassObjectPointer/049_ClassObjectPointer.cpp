
#include <iostream>

class Player
{
private:
    int Hp;
    int Att;


public:
    void Damage(/*Player const this*/)
    {
        this->Hp = 20;
    }
};

int main()
{
    int value = int();
    int* valuePtr = &value;

    Player NewPlayer = Player();
    Player* NewPlayerPtr = &NewPlayer;

    valuePtr = nullptr;
    NewPlayerPtr = nullptr; 
    NewPlayerPtr->Damage(); //  NewPlayerPtr의 주소값을 nullptr로 초기화하게 되면 
    //  Damage 함수의 인자가 *const로 선언되어 있기 때문에 exception 에러가 뜬다.

    int a = 0;
}
