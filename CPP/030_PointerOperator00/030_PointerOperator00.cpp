
#include <iostream>

int main()
{
    int value = 0;
    __int64 Address = 0;

    int* Ptr = &value;
    Address = (__int64)Ptr;
    Ptr += 1;
    Address = (__int64)Ptr;
    Ptr += 1;
    Address = (__int64)Ptr;
    Ptr += 1;
    Address = (__int64)Ptr;
    Ptr += 1;

    char string = '4';

    char* SPtr = &string;
    Address = (__int64)SPtr;
    SPtr += 1;
    Address = (__int64)SPtr;
    SPtr += 1;
    Address = (__int64)SPtr;
    SPtr += 1;
    Address = (__int64)SPtr;
    SPtr += 1;


}
