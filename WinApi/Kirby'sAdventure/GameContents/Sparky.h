#pragma once

// Ό³Έν :
class Sparky
{
public:
	// constrcuter destructer
	Sparky();
	~Sparky();

	// delete Function
	Sparky(const Sparky& _Other) = delete;
	Sparky(Sparky&& _Other) noexcept = delete;
	Sparky& operator=(const Sparky& _Other) = delete;
	Sparky& operator=(Sparky&& _Other) noexcept = delete;

protected:

private:

};

