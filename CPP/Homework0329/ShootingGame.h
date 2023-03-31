#pragma once
class ShootingGame
{
public:

	// 전역 함수를 써서 객체들의 단 하나의 함수를 만듬
	static void GameProcess();



private:
	// 생성자를 private 접근지정자에 뒀음 외부참조 x 내부에서만 생성
	ShootingGame()
	{

	}

};

