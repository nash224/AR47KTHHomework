
#include <iostream>
#include <conio.h>
//  C를 기반으로한 객체지향을 추가한 언어가 c++이다.

inline void Heal(const char* const _RecipientName,
    const char*const _HealerName,
    const int& _Int,
    int& _Hp)
{
    printf_s("%s가 %s에게 %d 힐을 해주었습니다.\n", _RecipientName, _HealerName, _Int);
    printf_s("------------------------------------\n");
    _Hp += _Int;

}

inline void StatusRender(
    const char* const _Name,
    int& _Hp,
    const int& _Int
)
{
    printf_s("%s 의 스테이터스 ------------------------------\n", _Name);
    printf_s("체력 : %d\n", _Hp);
    printf_s("지능 : %d\n", _Int);
    printf_s("------------------------------------------\n");
}


int main()
{
    //  c에서는 행동을 정의하기 시작한다.

    int PlayerHp = 100;
    int PlayerInt = 8;

    int HealerHp = 60;
    int HealerInt = 5;
    

    while (true)
    {
        system("cls");
        StatusRender("Player", PlayerHp, PlayerInt);
        StatusRender("Healer", HealerHp, HealerInt);

        Heal("Player", "Healer", HealerInt, PlayerHp);

        if (PlayerHp >= 200)
        {
            printf_s("플레이어의 체력이 다 찼습니다.\n");
            printf_s("회복이 취소되었습니다.\n");

            break;
        }
        else if (HealerHp >= 200)
        {
            printf_s("힐러의 체력이 다 찼습니다.\n");
            printf_s("회복이 취소되었습니다.\n");

            break;
        }

        int a = 0;

    }



}