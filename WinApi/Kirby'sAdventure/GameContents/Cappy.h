#pragma once

// Ό³Έν :
class Cappy
{
public:
	// constrcuter destructer
	Cappy();
	~Cappy();

	// delete Function
	Cappy(const Cappy& _Other) = delete;
	Cappy(Cappy&& _Other) noexcept = delete;
	Cappy& operator=(const Cappy& _Other) = delete;
	Cappy& operator=(Cappy&& _Other) noexcept = delete;

protected:

private:

};

