#pragma once
#include "GameEngineArray.h"
#include "ConsoleGameMath.h"

// �̰� 1�ܰ�
// �ٺ����� �ٺ� ���� ���� 
class ConsoleGameScreen
{
public:
	// �ܺο��� ����� �� �ִ� ��ũ�� ũ���� ���� ��� ������ �ִ�.
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	// �̱��� ���� : 3��°
	// ���� ��ũ�� ���� ��ȯ������ Ŭ���� ���� �Լ��� ����
	// ���ӽ�ũ����ô�ϴ� ���� ��ũ�� ������ ������ ��ȯ�Ѵ�.
	// ������: �ܺο��� ConsoleGameScreen::GetMainScreen()�Լ��� ����Ͽ� 
	// ��ü�� �̸��� ���� ��� ������ �����´�.
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	static int2 GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private: // Ŭ���� �ڽŸ� �ƴ� ����
	// �迭�� ScreenYSize(10), ScreenXSize(20)��ŭ ���ڰ� �ִ�.
	//char Arr[ScreenYSize][ScreenXSize] = { 0, };

 	GameEngineArray<GameEngineArray<char>> ArrScreen;


	// �̱��� ���� : 2��°
	// ���� ��ũ���� �����ڸ� private�����ڿ� ����������
	// �Ϲ����� �ν��Ͻ� ������ ���� ���ϰ� ���´�. 
	ConsoleGameScreen();

	// �̱��� ���� : 1��°
	// �������� Ŭ���� Ÿ���� ���ӽ�ũ�� ������ �ִ�.
	static ConsoleGameScreen MainScreen;
};