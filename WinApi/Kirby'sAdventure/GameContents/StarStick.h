#pragma once

// Ό³Έν :
class StarStick
{
public:
	// constrcuter destructer
	StarStick();
	~StarStick();

	// delete Function
	StarStick(const StarStick& _Other) = delete;
	StarStick(StarStick&& _Other) noexcept = delete;
	StarStick& operator=(const StarStick& _Other) = delete;
	StarStick& operator=(StarStick&& _Other) noexcept = delete;

protected:

private:

};

