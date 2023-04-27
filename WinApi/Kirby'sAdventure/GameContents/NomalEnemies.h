#pragma once

// Ό³Έν :
class NomalEnemies
{
public:
	// constrcuter destructer
	NomalEnemies();
	~NomalEnemies();

	// delete Function
	NomalEnemies(const NomalEnemies& _Other) = delete;
	NomalEnemies(NomalEnemies&& _Other) noexcept = delete;
	NomalEnemies& operator=(const NomalEnemies& _Other) = delete;
	NomalEnemies& operator=(NomalEnemies&& _Other) noexcept = delete;

protected:

private:

};

