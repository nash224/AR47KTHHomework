#pragma once
#include "ConsoleGameObject.h"
#include "ConsoleGameMath.h"
#include "GameEngineArray.h"
#include <vector>

// �̰� 1�ܰ�
// �ٺ����� �ٺ� ���� ���� 
class ConsoleGameScreen
{
public:
	// �������� �ҷ����� �Լ�
	// �� ���۷�����? : ���ϰ��� �������̸� ������ �������� ����
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

	// ���� ������ ũ��
	void ScreenPrint() const;

	// ����(��ӹ��� �ڽ�)�� _Pos���� �޾� 0�� ���� Size�� $ ������ true�� ��ȯ�ϰ� $ �ƴϸ� false�� ��ȯ��
	bool IsScreenOver(const int2& _Pos) const;

	// ����(��ӹ��� �ڽ�)�� _Pos�� _Ch�� �޾� ���� ArrScreen�� ��ҿ� _Ch�� ������
	void SetScreenCharacter(const int2& _Pos, char _Ch);
	
	// ArrData�� Parts��ġ ��ǥ ���
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

	// GameEngineArray<char> ArrPtr ������ 
	// char�� ������ ������ �ִ� �༮
	GameEngineArray<GameEngineArray<char>> ArrScreen;

	int2 Size;

	GameEngineArray<GameEngineArray<int>> ArrData;

	// ĳ������ �迭�� ���� �Ǵٸ� �迭�̶�� �Ҽ� �־��.


	ConsoleGameScreen();
	~ConsoleGameScreen();

	// �̱��� �����̶�� �մϴ�.
	// �����̶� => Ŭ������ ©�� �̷��̷��� ������ ���� ���� ���ȴ�.
	// ������������� �Ҹ��� ���α׷��� ��ȣȸ�� �־���.
	// Ŭ�������� ���質 ������ ¥�� ����� ����� �༮���� ��Ƽ� �̸��� �ٿ��µ�.
	// �װ� ������ �����̶�� �ϰ�.
	// �ƹ��� �Ƚ��.

	// ��������
	static ConsoleGameScreen MainScreen;
};