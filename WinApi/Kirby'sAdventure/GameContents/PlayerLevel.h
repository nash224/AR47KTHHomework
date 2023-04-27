#pragma once

// Ό³Έν :
class PlayerLevel
{
public:
	// constrcuter destructer
	PlayerLevel();
	~PlayerLevel();

	// delete Function
	PlayerLevel(const PlayerLevel& _Other) = delete;
	PlayerLevel(PlayerLevel&& _Other) noexcept = delete;
	PlayerLevel& operator=(const PlayerLevel& _Other) = delete;
	PlayerLevel& operator=(PlayerLevel&& _Other) noexcept = delete;

protected:

private:

};

