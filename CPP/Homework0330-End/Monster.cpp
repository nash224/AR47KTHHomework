#include "Monster.h"
#include "ConsoleGameScreen.h"

Monster::Monster() 
{
	RenderChar = 'M';
}

// �����ϴ� ���͸� �ǽð����� ����ڴ�.
void Monster::Update() 
{
	// ���Ͱ� �������� ������ ��ȯ
	if (false == IsUpdate())
	{
		return;
	}
	// ������ ����������
	if (true == DownCheck)
	{
		// ������ false�� �ʱ�ȭ�ϰ�
		DownCheck = false;
		// ��ȯ�Ѵ�.
		return;
	}

	// ���Ͱ� �����ϰų�, ������ �������� ������, ���Ⱚ�� ���� ��ǥ�� ����ְڴ�.
	Pos.X += Dir;
}