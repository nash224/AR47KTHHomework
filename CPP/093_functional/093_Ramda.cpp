// 093_Ramda.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

void Function()
{

}


void testFunction(int _value)
{
	int a = 0;
}


void testRefFunction(int* _value)
{
	int a = 0;
}


int main()
{
	// 람다는 왜 쓰는가?
	// 나는 지금까지 함수를 선언부에 작성하고 구현부에서 썻었다.
	
	// 하지만 선언부에 함수를 정의하지 않아도 구현부에서 즉석 함수를 만들 수 있는게
	// 그게 람다이다
	

	// 람다의 사용법은 다음 예제와 같다

	{
		// 이것 자체로 이미 함수포인터가 된다.
		// 이름없는 함수가 된다.

		// 주소값이 같은 메모리 만이 둘이 완전히 같은 메모리를 증명하는 수단입니다.

		// 100번지에 있는 int B;

		// int* int& 를 받았다고 칠께요.
		// int B일 가능성이 있나요 없나요?



		int A = 20;
		int B = 20;

		int* PtrA = &A;
		int* PtrB = &B;

		// TestAddRess(&A);

		std::function<void()> Ptr = [= /* const int A = A*/]()
		{
			const int* PtrAInner = &A;

			int a = 0;
		};

		Ptr();
	}

	std::function<void()> Ptr;

	{
		int A = 20;
		int B = 20;

		int* PtrA = &A;
		int* PtrB = &B;

		Ptr = [& /* int& A = A*/]()
		{
			int* PtrAInner = &A;

			int a = 0;
		};
	}

	Ptr();

	{
		int A = 20;
		int B = 20;

		int* PtrA = &A;
		int* PtrB = &B;

		std::function<void()> Ptr = [A, &B]()
		{

		};

		Ptr();
	}


	{
		short B = 5;
		short C = 10;

		short* PtrB = &B;
		short* PtrC = &C;

		bool CheckBooleanTypeRamda = true;


		// 람다에서 함수명 = [=]()을 하게되면 외부의 변수를 사용할 수 있게 된다.
		std::function<void()> Ptr = [= /*const int B = B*/]()
		{
			B /*= 50*/; // 값을 변경하지 못하는걸 보니 const일 것이다.
						// => 그럼 이름은 같지만 주소는 같은가? 

			const short* PtrBInner = &B;

			// PtrBInner == 0x000000ff384ff384 {5}
			// PtrB == 0x000000ff384ff438 {5}

			// 값은 같으나 주소가 다르다

			// 따라서 람다 지역에서 변수를 const (자료형) 으로 받아 사용한다

			int a = 0;

			CheckBooleanTypeRamda;
		};

		Ptr();
	}


	// 람다의 스코프 안에서는 외부의 주소는 못쓰는가?
	// 확인을 위해 다음 예저로 넘어가겠다

	{
		int B = 5;
		int C = 10;

		int* PtrB = &B;
		int* PtrC = &C;


		// = [&]() 에 레퍼런스 기호가 들어있으면 외부에서 참조할 수 있다고 한다
		std::function<void()> Ptr = [&  /*int& B = B*/]()
		{
			int* PtrBInner = &B;


			// PtrB == 0x00000080a65ef3d4 {5}
			// PtrBInner == 0x00000080a65ef3d4 {5}

			// 람다 지역 바깥 변수와 람다 지역 안 변수의 주소가 동일하다 


			// 그럼 값은 변경가능한가?
			B = 20;

			// 컴파일이 된다 => 즉 const는 선언되어 있지 않다

			int a = 0;
		};


		Ptr();
	}


	{
		int B = 5;
		int C = 10;
		int D = 50;

		int* PtrB = &B;
		int* PtrC = &C;
		// 람다를 괄호에 아무것도 없을때는 해당 지역의 모든 인자를 불러오는 것 같다.
		// 그럼 인자를 개별로 불러올수는 없는가?

		std::function<void()> Ptr = [B, &C]()
		{
			const int* PtrBInner = &B;
			int* PtrCInner = &C;

			/*D;*/ // 인자를 불러올 수 없다.
		};

		Ptr();
	}



	// 람다는 위험성이 없는가?

	// 다음 예제로 확인해보겠다


	// 람다 함수의 선언을 구현부 지역 바깥에서 했다.
	// 문제점은 지역 안의 변수를 사용하고 지역이 끝나서 사용하면 어떻게 될까?
	// 어떻게 될지 모른다.
	// 사용이 될 수도 있고, 터질 수도 있다.

	

	std::function<void()> Ptr1;

	{
		short B = 5;
		short C = 10;

		short* PtrB = &B;
		short* PtrC = &C;

		bool CheckBooleanTypeRamda = true;


		// 람다에서 함수명 = [=]()을 하게되면 외부의 변수를 사용할 수 있게 된다.
		Ptr1 = [= /*const int B = B*/]()
		{
			B /*= 50*/; // 값을 변경하지 못하는걸 보니 const일 것이다.
			// => 그럼 이름은 같지만 주소는 같은가? 

			const short* PtrBInner = &B;

			// PtrBInner == 0x000000ff384ff384 {5}
			// PtrB == 0x000000ff384ff438 {5}

			// 값은 같으나 주소가 다르다

			// 따라서 람다 지역에서 변수를 const (자료형) 으로 받아 사용한다

			int a = 0;

			CheckBooleanTypeRamda;
		};

	}

	Ptr1();


}
