#pragma once

// Ό³Έν :
class Sword_Knight
{
public:
	// constrcuter destructer
	Sword_Knight();
	~Sword_Knight();

	// delete Function
	Sword_Knight(const Sword_Knight& _Other) = delete;
	Sword_Knight(Sword_Knight&& _Other) noexcept = delete;
	Sword_Knight& operator=(const Sword_Knight& _Other) = delete;
	Sword_Knight& operator=(Sword_Knight&& _Other) noexcept = delete;

protected:

private:

};

