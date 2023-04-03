#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

Player::Player()
{
	RenderChar = '*';
}
// ȭ��ٱ����� �������� �ϼ���. 
void Player::Input()
{
	// ������ ��
	if (0 == _kbhit())
	{
		// 0.5�ʰ� �����.
		Sleep(InterFrame);
		// �Ϻη� ���߰� ����̴ϴ�.
		// continue; �ݺ��� ���ο����� ��밡��
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		// ���ο� ��ġ�� ���� ��ġ�� ��´�.
		NextPos = Pos;
		// ���ο� ��ġ�� �������� ���� �Ѵ�.
		NextPos.X -= 1;
		// ������ġ�� ���� �ʾҴٸ�
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{// �÷��̾��� ��ǥ�� �������� ��ĭ ������.
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
	{
		// �Ѿ˿� ���� ������  �ҷ��´�
		ShotUpdate();
		break;
	}
	default:
		break;
	}

	Sleep(InterFrame);
}

void Player::ShotUpdate()
{
	// �Ѿ˵��� ������ �޾ƿ´�.
	Bullet& NewBullet = BulletPtr[BulletCount];
	// �Ѿ� ��ü�� ��ġ�� �����´�.
	NewBullet.SetPos(Pos);
	// �Ѿ��� �����ϰ� �Ѵ�.
	NewBullet.On();

	// �߻��� �Ѿ��� ���� ����
	++BulletCount;
	// �߻��� �Ѿ��� ��ü �Ѿ˺��� ������ �߻��� �Ѿ��� 0���� �ʱ�ȭ�Ѵ�.
	if (BulletCount >= Bullet::ArrBulletCount)
	{
		BulletCount = 0;
	}
}
