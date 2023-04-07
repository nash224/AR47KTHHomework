#pragma once

#include <iostream>

class Player
{
public:
	// constructor desstructor
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;


	void Damage(int _value);

protected:

private:

};