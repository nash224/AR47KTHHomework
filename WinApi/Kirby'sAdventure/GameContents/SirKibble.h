#pragma once

// Ό³Έν :
class SirKibble
{
public:
	// constrcuter destructer
	SirKibble();
	~SirKibble();

	// delete Function
	SirKibble(const SirKibble& _Other) = delete;
	SirKibble(SirKibble&& _Other) noexcept = delete;
	SirKibble& operator=(const SirKibble& _Other) = delete;
	SirKibble& operator=(SirKibble&& _Other) noexcept = delete;

protected:

private:

};

