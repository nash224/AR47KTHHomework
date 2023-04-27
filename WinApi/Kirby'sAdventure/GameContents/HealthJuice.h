#pragma once

// Ό³Έν :
class HealthJuice
{
public:
	// constrcuter destructer
	HealthJuice();
	~HealthJuice();

	// delete Function
	HealthJuice(const HealthJuice& _Other) = delete;
	HealthJuice(HealthJuice&& _Other) noexcept = delete;
	HealthJuice& operator=(const HealthJuice& _Other) = delete;
	HealthJuice& operator=(HealthJuice&& _Other) noexcept = delete;

protected:

private:

};

