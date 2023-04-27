#pragma once

// Ό³Έν :
class Kabu
{
public:
	// constrcuter destructer
	Kabu();
	~Kabu();

	// delete Function
	Kabu(const Kabu& _Other) = delete;
	Kabu(Kabu&& _Other) noexcept = delete;
	Kabu& operator=(const Kabu& _Other) = delete;
	Kabu& operator=(Kabu&& _Other) noexcept = delete;

protected:

private:

};

