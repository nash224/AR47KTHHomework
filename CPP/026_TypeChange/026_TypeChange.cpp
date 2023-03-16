
#include <iostream>

int main()
{

	//	형변환은 데이터 손실, 비트 패턴의 잘못된 해석 또는 메모리의 손상이
	//	발생하지 않는 선에서 사용되어질 수 있다.
	//	선택한 변환이 승격인 경우는 허용 하지만, 축소인 경우는 데이터 손실이 이뤄지므로 
	//	컴파일러에서 에러에 대한 경고가 발생한다.

	{
		bool Bvalue0 = true;
		int Ivalue0 = 7;
		Ivalue0 = Bvalue0;
		//	자료형태가 다르지만 대입이 가능하다.
		//	자료형태를 바꿔주는것을 암시적 변환이라고 한다.

		printf_s("aaaaa");
		//	(const char[6])"aaaaa"

		//	const char* const <= const char[6]
		//	

	}

	{
		//	형변환이 허용되지 않는 자료형도 존재한다

		int Arr[10];

		//int value = Arr;
		//	변수에 배열 자체를 받을수는 없다.

		int value = 0;
		int* Ptr = nullptr;
		//Ptr = value;	
		//	기본적으로 주소값에 상수를 넣어줄 수 없다.
	}


	{
		int Arr[10] = {};
		int* Ptr = Arr;
		//	배열의 주소를 대입받을 수 있다.

		int a = 0;
	}
}