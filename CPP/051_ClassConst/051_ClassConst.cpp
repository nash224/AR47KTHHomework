
#include <iostream>

class Player
{
public:
    //  함수의 접두에 const를 선언하게 되면 해당 클래스를 통한 객체의 변화는 없다.
    //  const를 붙이는걸 습관하면 나쁠건 없다.
    void Print_User_Status(/*const Player* const this*/) const
    {
        //this;
        //Att += 100;  =>   멤버변수를 고칠 수 없다.

        printf_s("=====================================\n");

        printf_s(" 유저 체  력 : %d\n", Hp);
        printf_s(" 유저 공격력 : %d\n", Att);
        printf_s(" 유저 방어력 : %d\n", Def);

        printf_s("=====================================\n");
    }

    void Set_Hp(int _Value)
    {
        Hp = _Value;
    }

    int Get_Hp() const
    {
        return Hp;
    }

private:

    int Hp = 100;
    int Att = 10;
    int Def = 5;
};

int main()
{
    Player NewPlayer = Player();

    NewPlayer.Print_User_Status();
    NewPlayer.Print_User_Status();
    NewPlayer.Print_User_Status();
    NewPlayer.Print_User_Status();

    NewPlayer.Set_Hp(1500);
    NewPlayer.Get_Hp();


    std::cout << "Hello World!\n";
}