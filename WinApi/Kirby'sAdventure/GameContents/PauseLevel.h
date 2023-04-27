#pragma once

// Ό³Έν :
class PauseLevel
{
public:
	// constrcuter destructer
	PauseLevel();
	~PauseLevel();

	// delete Function
	PauseLevel(const PauseLevel& _Other) = delete;
	PauseLevel(PauseLevel&& _Other) noexcept = delete;
	PauseLevel& operator=(const PauseLevel& _Other) = delete;
	PauseLevel& operator=(PauseLevel&& _Other) noexcept = delete;

protected:

private:

};

