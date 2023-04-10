#pragma once
#include <GameEngineConsole/GameEngineArray.h>
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

	void SetScreenSize(int2 _Size);

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private: // Ŭ���� �ڽŸ� �ƴ� ����

	// char ArrScreen[][];
	//char** ArrScreen = nullptr;

	// GameEngineArray�� 1���� �迭�� ��Ÿ���� Ŭ�����̴�.
	// GameEngineArray<char>�� char ������ ���� ������ 1���� �迭
	// GameEngineArray<GameEngineArray<char>>�� char������ ���� ������ 1���� �迭�� 1���� �迭�̴�.
	// ��, 2�� �迭�̴�.
	// ArrScreen ������ 2���� �迭�� ��Ÿ����.
	// 
	
 	GameEngineArray<GameEngineArray<char>> ArrScreen;

	int2 Size;

	// �̱��� ���� : 2��°
	// ���� ��ũ���� �����ڸ� private�����ڿ� ����������
	// �Ϲ����� �ν��Ͻ� ������ ���� ���ϰ� ���´�. 
	ConsoleGameScreen();
	~ConsoleGameScreen();

	// �̱��� ���� : 1��°
	// �������� Ŭ���� Ÿ���� ���ӽ�ũ�� ������ �ִ�.
	static ConsoleGameScreen MainScreen;
};