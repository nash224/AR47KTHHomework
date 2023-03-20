
//  추후 정리 예정
#include <iostream>

int Myprintf(const char* const _Value, ...)
{
    __int64 Address = (__int64)& _Value;

    int count = 0;

    while (_Value[count] != 0)
    {
        if (_Value[count] == '%')
        {
            count++;
            switch (_Value[count])
            {
            case 'd':
            {
                Address += 8;
                int* PointerValue = (int*)Address;
                int Ptrvalue = *PointerValue;
                printf_s("%d", Ptrvalue);
                break;
            }
            default:
                break;
            }
        }
        else
        {
            putchar(_Value[count]);
        }

        count++;
    }



    int a = 0;

    return 0;
}

int main()
{
    Myprintf("asdasd%das%dd", 152, 633);

    printf_s("");
}

