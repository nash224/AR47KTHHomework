
#include <iostream>
//  클래스는 선언부터 시작합니다.

//  c++에서 클래스는 모든 것을 만들수있다.

class Player
{
	//	클래스는 속성과 행동을 가지고 있다.
	//	속성은 객체와 연관되어 있고, 행동은 함수와 연관되어있다.

	const char* const Name = "David";

	int Att;
	int Hp;
	int Speed;

	void Run() {

	}

	void Sandevistan() {

	}

};

int main()
{
	Player NewPlayer01 = Player();
	Player NewPlayer02 = Player();
	Player NewPlayer03 = Player();

	Player ArrPlayer[3];

}