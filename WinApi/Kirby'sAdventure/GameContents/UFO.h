#pragma once

// Ό³Έν :
class UFO
{
public:
	// constrcuter destructer
	UFO();
	~UFO();

	// delete Function
	UFO(const UFO& _Other) = delete;
	UFO(UFO&& _Other) noexcept = delete;
	UFO& operator=(const UFO& _Other) = delete;
	UFO& operator=(UFO&& _Other) noexcept = delete;

protected:

private:

};

