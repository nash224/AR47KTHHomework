#include "Player.h"

Player::Player()
{

}

void Player::Damage(int _value)
{
	this->Hp -= _value;
}

void Player::Heal(int _value)
{
	this->Hp += _value;
}