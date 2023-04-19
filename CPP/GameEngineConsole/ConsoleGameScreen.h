#pragma once
#include "ConsoleGameObject.h"
#include "ConsoleGameMath.h"
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
	void SetScreenCharacter(const int2& _Pos, wchar_t _Ch);
	
	// ArrData에 Parts위치 좌표 찍기
	void PutArrDataPartsPos(int2& _PartsPos);

	std::vector<int>& GetArrData(size_t _value)
	{

		return ArrData[_value];
	}


protected:

private:
	int2 Size;

	std::vector<std::vector<wchar_t>> ArrScreen;
	std::vector<std::vector<int>> ArrData;

	ConsoleGameScreen();
	~ConsoleGameScreen();

	// 전역변수
	static ConsoleGameScreen MainScreen;
};