#pragma once
#include "ConsoleGameObject.h"
#include "ConsoleGameMath.h"
#include "GameEngineArray.h"
#include <vector>

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{
public:
	// 전역변수 불러오는 함수
	// 왜 레퍼런스지? : 리턴값이 참조형이면 변수를 복사하지 않음
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	//static int2 GetMainScreenSize()
	//{
	//	return MainScreen.GetScreenSize();
	//}

	int2 GetScreenSize();

	void SetScreenSize(int2 _Size);
	void SetArrDataSize();

	void ScreenClear();
	void ArrDataClear();

	// 나의 사이즈 크기
	void ScreenPrint() const;

	// 누구(상속받은 자식)의 _Pos값을 받아 0과 나의 Size에 $ 나가면 true를 반환하고 $ 아니면 false를 반환함
	bool IsScreenOver(const int2& _Pos) const;

	// 누구(상속받은 자식)의 _Pos와 _Ch를 받아 나의 ArrScreen의 요소에 _Ch를 저장함
	void SetScreenCharacter(const int2& _Pos, char _Ch);
	
	// ArrData에 Parts위치 좌표 찍기
	void PutArrDataPartsPos(ConsoleGameObject* _PartsPos);

	void SetArrData();

	GameEngineArray<GameEngineArray<int>> GetArrData() const
	{
		return ArrData;
	}


protected:

private:
	// char Arr[ScreenYSize][ScreenXSize] = { 0, };

	// char** ArrScreen = nullptr;

	// GameEngineArray<char> ArrPtr 여러개 
	// char를 여러개 가질수 있는 녀석
	GameEngineArray<GameEngineArray<char>> ArrScreen;

	int2 Size;

	GameEngineArray<GameEngineArray<int>> ArrData;

	// 캐릭터의 배열을 가진 또다른 배열이라고 할수 있어요.


	ConsoleGameScreen();
	~ConsoleGameScreen();

	// 싱글톤 패턴이라고 합니다.
	// 패턴이란 => 클래스를 짤때 이러이러한 구조가 정말 많이 사용된다.
	// 갱스오브포라고 불리는 프로그래머 동호회가 있었다.
	// 클래스간의 관계나 구조를 짜는 방식이 비슷한 녀석들을 모아서 이름을 붙였는데.
	// 그걸 디자인 패턴이라고 하고.
	// 아무도 안써요.

	// 전역변수
	static ConsoleGameScreen MainScreen;
};