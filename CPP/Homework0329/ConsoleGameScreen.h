#pragma once
#include "ConsoleGameMath.h"

// �̰� 1�ܰ�
// �ٺ����� �ٺ� ���� ���� 

class Player;
class ConsoleGameScreen
{
public:
	// Ŭ���� ���ο� ���������� �����Ҽ��� �ֽ��ϴ�.
	// ��ũ�� ũ��
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	int BullPosX;
	int BullPosY;

	// ConsoleGameScreenŬ������ ���ϴ� GetMainScreen�� ȣ��Ǹ� �̱������� ��ü�� ��ȯ�Ѵ�
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	static int2 GetScreenSize();

	// ��ũ���� �� �����.
	void ScreenClear();

	// ��ũ���� ����Ѵ�. ���� �ٲ� �ʿ䰡 �������� const�� �����Ѵ�
	void ScreenPrint() const;

	// �÷��̾ �� ������ �������� �Ǻ��� ���� ���� �Լ�, �Լ����� �÷��̾��� ��ġ�� �ʿ�� �ؼ� �Ű������� ��ġ���� ����
	bool IsScreenOver(const int2& _Pos) const;

	/*bool ConsoleGameScreen::IsBulletScreenOver(const )*/

	// ȭ�鿡 �÷��̾��� ��ġ�� ����ش�. �̰͵� �÷��̾��� ��ġ�� �ʿ��ؼ� ��ġ���� �޾ƿ��� �÷��̾��� ����� �����´�
	void SetScreenCharacter(const int2& _Pos, char _Ch);

	void SetScreenBullet(const int2& _Pos, char _Bull);

protected:

private:
	// ��ũ���� 
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	ConsoleGameScreen();

	// �̱��� �����̶�� �մϴ�.
	// �����̶� => Ŭ������ ©�� �̷��̷��� ������ ���� ���� ���ȴ�.
	// ������������� �Ҹ��� ���α׷��� ��ȣȸ�� �־���.
	// Ŭ�������� ���質 ������ ¥�� ����� ����� �༮���� ��Ƽ� �̸��� �ٿ��µ�.
	// �װ� ������ �����̶�� �ϰ�.
	// �ƹ��� �Ƚ��.
	static ConsoleGameScreen MainScreen;
};