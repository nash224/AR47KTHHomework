#pragma once
#include "ConsoleGameMath.h"

// 이게 1단계
// 근본오브 근본 수학 물리 

class Player;
class ConsoleGameScreen
{
public:
	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	// 스크린 크기
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	int BullPosX;
	int BullPosY;

	// ConsoleGameScreen클래스에 속하는 GetMainScreen이 호출되면 싱글톤패턴 객체를 반환한다
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	static int2 GetScreenSize();

	// 스크린을 싹 지운다.
	void ScreenClear();

	// 스크린을 출력한다. 값을 바꿀 필요가 없음으로 const를 선언한다
	void ScreenPrint() const;

	// 플레이어가 맵 밖으로 나갔는지 판별을 위해 만든 함수, 함수에서 플레이어의 위치를 필요로 해서 매개변수는 위치값을 받음
	bool IsScreenOver(const int2& _Pos) const;

	/*bool ConsoleGameScreen::IsBulletScreenOver(const )*/

	// 화면에 플레이어의 위치를 찍어준다. 이것도 플레이어의 위치가 필요해서 위치값을 받아오고 플레이어의 모양을 가져온다
	void SetScreenCharacter(const int2& _Pos, char _Ch);

	void SetScreenBullet(const int2& _Pos, char _Bull);

protected:

private:
	// 스크린에 
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	ConsoleGameScreen();

	// 싱글톤 패턴이라고 합니다.
	// 패턴이란 => 클래스를 짤때 이러이러한 구조가 정말 많이 사용된다.
	// 갱스오브포라고 불리는 프로그래머 동호회가 있었다.
	// 클래스간의 관계나 구조를 짜는 방식이 비슷한 녀석들을 모아서 이름을 붙였는데.
	// 그걸 디자인 패턴이라고 하고.
	// 아무도 안써요.
	static ConsoleGameScreen MainScreen;
};