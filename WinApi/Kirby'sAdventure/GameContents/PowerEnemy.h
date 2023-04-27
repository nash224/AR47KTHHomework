#pragma once

// Ό³Έν :
class PowerEnemy
{
public:
	// constrcuter destructer
	PowerEnemy();
	~PowerEnemy();

	// delete Function
	PowerEnemy(const PowerEnemy& _Other) = delete;
	PowerEnemy(PowerEnemy&& _Other) noexcept = delete;
	PowerEnemy& operator=(const PowerEnemy& _Other) = delete;
	PowerEnemy& operator=(PowerEnemy&& _Other) noexcept = delete;

protected:

private:

};

