#pragma once

// Ό³Έν :
class OneCoinUp
{
public:
	// constrcuter destructer
	OneCoinUp();
	~OneCoinUp();

	// delete Function
	OneCoinUp(const OneCoinUp& _Other) = delete;
	OneCoinUp(OneCoinUp&& _Other) noexcept = delete;
	OneCoinUp& operator=(const OneCoinUp& _Other) = delete;
	OneCoinUp& operator=(OneCoinUp&& _Other) noexcept = delete;

protected:

private:

};

