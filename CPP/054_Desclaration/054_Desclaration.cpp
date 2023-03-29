// 054_Desclaration.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//  구현이라는 문법은
//  선언과 함술체를 같이 놓은 문법을 구현된 함수라고 부름

//  함수선언
//  이러한 함수가 있을 거야
//  구현은 나중에 있을 것
//  왜? => 코드가 복잡해지면 외우기 힘듬

//	전역함수의 경우 선언을 몇개를 해도 상관없다.
//	Function0()있다고 선언함
void Function0();
void Function1();
void Function1();
void Function1();
void Function1();
void Function2();

void test2();


//  외부 기호 Error => 실체가 없다. 구현을 해주지 않았다.


void test1()
{
	test2();	//	test1()은 자신 코드의 위의 함수를 참조하게 되는데 test2()가 없다.
				//	C3861 ; test2 식별자를 찾을 수 없습니다.
				//	해결법 : test2 함수를 위에 선언만 해주고 구현은 밑에서 한다.
}

void test2()
{

}

void Function()
//  함수체
{

}

//	클래스 자체는 2개를 선언할 수 없다.

class Player
{
public:
	//	멤버변수는 따로 실체를 둘 필요가없다.

	//	클래스 내부에서 구현을 하면 이미 구현이 끝난 것으로 간주한다.
	//	즉, 2번 구현할 수 없다. 이는 static함수도 똑같다.
	//void StatusRender()
	//{

	//}

	void Function0()
	{

	}


	void StatusRender();

private:
	//	static 변수에 const가 붙으면 코드 영역에 존재함으로 여러번 초기화 할 수 없다.
	//	리터널 초기화가 가능하다.
	//	앞으로 Player::Value는 5로 바꾼다.
	//	컴파일러의 입장으로 봤을때 전부 5로 만들어버린다.
	static const int Value = 5;

	void Damage();

	static void GlobalFunction()
	{

	}

	//	const가 아닌 static은 데이터 영역에 위치하게 되고 리터널 초기화가 불가능하다.
	//	Player에 속한 static 전역변수인 Value2가 있을꺼야
	static int Value2;



	int Arr[Value][Value];

	
};



class Monster
{
public:
	void Damage()
	{

	}
	
};



void Player::StatusRender()
{

}


int Player::Value2 = 10;

//	멤버함수의 풀네임은 
//	클래스명:: 함수이름으로 인식해야한다.
void Player::Damage()
{

}

int main()
{
	Function0();
	Function1();
	Function2();

	Player NewPlayer0 = Player();
	NewPlayer0.Function0();

	NewPlayer0.StatusRender();
}




void Function0()
{

}
void Function1()
{

}
void Function2()
{

}
