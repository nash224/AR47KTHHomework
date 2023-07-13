
#include <iostream>
#include <windows.h>
#include "Level.h"
#include "Object.h"


int main()
{
    LARGE_INTEGER Count;
    LARGE_INTEGER Start;
    LARGE_INTEGER End;

    QueryPerformanceFrequency(&Count);
    QueryPerformanceCounter(&Start);

    Object* _Ptr = new Level();

    for (int i = 0; i < 200; i++)
    {
        static_cast<Level*>(_Ptr);
        std::cout << sizeof(_Ptr) << std::endl;
        system("cls");
    }

    QueryPerformanceCounter(&End);

    double Tick = static_cast<double>(End.QuadPart - Start.QuadPart) / static_cast<double>(Count.QuadPart);

    float floatTick = static_cast<float>(Tick);
    printf("%.4f초 걸렸습니다.", floatTick);

}