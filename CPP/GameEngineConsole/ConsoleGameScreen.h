#pragma once
#include "ConsoleGameObject.h"
#include "ConsoleGameMath.h"
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
	void SetScreenCharacter(const int2& _Pos, wchar_t _Ch);
	
	// ArrData�� Parts��ġ ��ǥ ���
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

	// ��������
	static ConsoleGameScreen MainScreen;
};