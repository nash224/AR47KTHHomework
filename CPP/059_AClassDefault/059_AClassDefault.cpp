// 059_AClassDefault.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ADefalultClass.h"

class C
{

};

int main()
{
	{
		C COBOL = C();
		C Cpp = C(COBOL);
		Cpp = COBOL;
		COBOL.~C();
	}
}