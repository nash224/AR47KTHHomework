#include "Player.h"
#include "BaseHeader.h"


Player::Player()
{
}

Player::~Player()
{
}

void Player::Damage(int _value)
{
	if (0 == _value)
	{
		// �Լ��� ���ο�� ��������, define�� �׳� ����
		MessageBoxAssert("�������� 0�Դϴ�.");
	}
	
}