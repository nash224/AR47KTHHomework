#pragma once

// Ό³Έν :
class HpLadyBug
{
public:
	// constrcuter destructer
	HpLadyBug();
	~HpLadyBug();

	// delete Function
	HpLadyBug(const HpLadyBug& _Other) = delete;
	HpLadyBug(HpLadyBug&& _Other) noexcept = delete;
	HpLadyBug& operator=(const HpLadyBug& _Other) = delete;
	HpLadyBug& operator=(HpLadyBug&& _Other) noexcept = delete;

protected:

private:

};

