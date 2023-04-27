#pragma once

// Ό³Έν :
class GameOverLevel
{
public:
	// constrcuter destructer
	GameOverLevel();
	~GameOverLevel();

	// delete Function
	GameOverLevel(const GameOverLevel& _Other) = delete;
	GameOverLevel(GameOverLevel&& _Other) noexcept = delete;
	GameOverLevel& operator=(const GameOverLevel& _Other) = delete;
	GameOverLevel& operator=(GameOverLevel&& _Other) noexcept = delete;

protected:

private:

};

