#pragma once

// Ό³Έν :
class AbillityEffect
{
public:
	// constrcuter destructer
	AbillityEffect();
	~AbillityEffect();

	// delete Function
	AbillityEffect(const AbillityEffect& _Other) = delete;
	AbillityEffect(AbillityEffect&& _Other) noexcept = delete;
	AbillityEffect& operator=(const AbillityEffect& _Other) = delete;
	AbillityEffect& operator=(AbillityEffect&& _Other) noexcept = delete;

protected:

private:

};

