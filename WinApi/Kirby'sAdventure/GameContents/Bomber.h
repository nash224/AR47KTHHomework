#pragma once

// Ό³Έν :
class Bomber
{
public:
	// constrcuter destructer
	Bomber();
	~Bomber();

	// delete Function
	Bomber(const Bomber& _Other) = delete;
	Bomber(Bomber&& _Other) noexcept = delete;
	Bomber& operator=(const Bomber& _Other) = delete;
	Bomber& operator=(Bomber&& _Other) noexcept = delete;

protected:

private:

};

