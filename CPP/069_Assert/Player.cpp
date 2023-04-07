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
		// 함수는 새로운걸 만들지만, define은 그냥 복붙
		MessageBoxAssert("데미지가 0입니다.");
	}
	
}