#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include "ConsoleGameMath.h"

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{
public:
	// 외부에서 사용할 수 있는 스크린 크기의 전역 멤버 변수가 있다.
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	// 싱글톤 패턴 : 3번째
	// 게임 스크린 참조 반환형식의 클래스 전역 함수를 선언
	// 게임스크린인척하는 메인 스크린 형식의 변수를 반환한다.
	// 선언방법: 외부에서 ConsoleGameScreen::GetMainScreen()함수를 사용하여 
	// 객체의 이름과 같은 멤버 변수를 가져온다.
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	static int2 GetScreenSize();

	void SetScreenSize(int2 _Size);

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private: // 클래스 자신만 아는 내부

	// char ArrScreen[][];
	//char** ArrScreen = nullptr;

	// GameEngineArray은 1차원 배열을 나타내는 클래스이다.
	// GameEngineArray<char>는 char 형태의 값을 가지는 1차원 배열
	// GameEngineArray<GameEngineArray<char>>는 char형태의 값을 가지는 1차원 배열의 1차원 배열이다.
	// 즉, 2원 배열이다.
	// ArrScreen 변수는 2차원 배열을 나타낸다.
	// 
	
 	GameEngineArray<GameEngineArray<char>> ArrScreen;

	int2 Size;

	// 싱글톤 패턴 : 2번째
	// 게임 스크린의 생성자를 private지정자에 선언함으로
	// 일반적인 인스턴스 생성을 하지 못하게 막는다. 
	ConsoleGameScreen();
	~ConsoleGameScreen();

	// 싱글톤 패턴 : 1번째
	// 전역으로 클래스 타입의 게임스크린 변수가 있다.
	static ConsoleGameScreen MainScreen;
};