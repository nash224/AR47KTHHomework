
#include <iostream>

void Myprintf(const char* const _Ptr)
{
	int count = 0;
	char Ch = 0;
	while (Ch = _Ptr[count], 0 != _Ptr[count])
	{
		putchar(Ch);
		count++;
	}
}


int main()
{
	const char ArrTest[2] = { 'a', 'b' };

	const char ArrPrint[10] = "I AM PRO";

	const char* Ptr = "test Print";
	//	포인터 배열

	char ArrCh[2] = {};


	__int64 Address = 0;

	Address = (__int64)Ptr;

	int a = 0;


	char Ch0 = Ptr[0];
	char Ch1 = Ptr[1];
	char Ch2 = Ptr[2];
	char Ch3 = Ptr[3];
	char Ch4 = Ptr[4];
	char Ch5 = Ptr[5];
	char Ch6 = Ptr[6];
	char Ch7 = Ptr[7];
	char Ch8 = Ptr[8];
	char Ch9 = Ptr[9];
	char Ch10 = Ptr[10];

	Myprintf(ArrPrint);
}