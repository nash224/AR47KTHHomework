#pragma once

// Ό³Έν :
class Parasol
{
public:
	// constrcuter destructer
	Parasol();
	~Parasol();

	// delete Function
	Parasol(const Parasol& _Other) = delete;
	Parasol(Parasol&& _Other) noexcept = delete;
	Parasol& operator=(const Parasol& _Other) = delete;
	Parasol& operator=(Parasol&& _Other) noexcept = delete;

protected:

private:

};

