
#include <iostream>

int StringCount(const char* _String)
{

    int count = 0;

    while (int value = _String[count] != 0)
    {
        count++;
    }

    return count;
}




int StringToInt(const char* _String)
{
    int num = StringCount(_String);
    
    int Value = 0;
    int count = 0;
    while (num - count != 0)
    {
        char ASC = _String[count];
        int a = ASC - '0';
        int loop = num - count;

        while (--loop)
        {
            a = a * 10;
        }
        Value = Value + a;
        count++;

    }

    return Value;
}

int main()
{
    
    int value = StringToInt("6236222");

    char Str = '7';
    int Value = Str;

    int a = 0;
}