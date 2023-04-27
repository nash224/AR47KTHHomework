#pragma once

// Ό³Έν :
class WaddleDoo
{
public:
	// constrcuter destructer
	WaddleDoo();
	~WaddleDoo();

	// delete Function
	WaddleDoo(const WaddleDoo& _Other) = delete;
	WaddleDoo(WaddleDoo&& _Other) noexcept = delete;
	WaddleDoo& operator=(const WaddleDoo& _Other) = delete;
	WaddleDoo& operator=(WaddleDoo&& _Other) noexcept = delete;

protected:

private:

};

