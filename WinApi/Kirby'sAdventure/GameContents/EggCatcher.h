#pragma once

// Ό³Έν :
class EggCatcher
{
public:
	// constrcuter destructer
	EggCatcher();
	~EggCatcher();

	// delete Function
	EggCatcher(const EggCatcher& _Other) = delete;
	EggCatcher(EggCatcher&& _Other) noexcept = delete;
	EggCatcher& operator=(const EggCatcher& _Other) = delete;
	EggCatcher& operator=(EggCatcher&& _Other) noexcept = delete;

protected:

private:

};

