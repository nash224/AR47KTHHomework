#include <iostream>

// 영어만 씁니다.

// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하세요
int StringCount(const char* _String)
{
    int count = 0;
    int Stringcount = 0;

    while (0 != _String[count])
    {
        if (int value = _String[count] != ' ')
        {
            Stringcount += 1;
        }
        count++;
    }

    return Stringcount;
}

int PtrStringCount(const char* _String)
{

    int count = 0;

    while (int value = _String[count] != 0)
    {
        count++;
    }

    return count;
}


int TrimDelete(char* _String)
{
    int count = 0;

    while (int value = _String[count] != 0)
    {
        if (_String[count] != ' ')
        {
            putchar(_String[count]);
        }
        count++;
    }
    printf_s("\n");
    
    return *_String;
}

int StringToInt(const char* _String)
{
    int num = PtrStringCount(_String);

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
    char String01[5] = "aaaa";
    char* PtrString01 = String01;

    char String02[1024] = "aas adaa gds gg ss sss";
    char* PtrString02 = String02;


    int Return0 = StringCount(PtrString01);
    int Return1 = StringCount(PtrString02);

    char Arr0[1024] = "a b c d e";
    char* PtrArr0 = Arr0;

    char Arr1[1024] = "a    b c    d    e";
    char Arr2[1024] = "ab    cde    ";

    
    TrimDelete(Arr0);
    printf_s(Arr0);
    TrimDelete(Arr1);
    printf_s(Arr1);
    TrimDelete(Arr2);
    printf_s(Arr2);

    // 영어나 다른글자가 섞여 들어가있는것을 가정하지 않는다.
    int RValue0 = StringToInt("1111");
    int RValue1 = StringToInt("432");
    int RValue2 = StringToInt("4523312");
    int RValue3 = StringToInt("432231");

    std::cout << "Hello World!\n";
}