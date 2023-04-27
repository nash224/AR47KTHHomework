#pragma once

// Ό³Έν :
class PoppyBrosJr
{
public:
	// constrcuter destructer
	PoppyBrosJr();
	~PoppyBrosJr();

	// delete Function
	PoppyBrosJr(const PoppyBrosJr& _Other) = delete;
	PoppyBrosJr(PoppyBrosJr&& _Other) noexcept = delete;
	PoppyBrosJr& operator=(const PoppyBrosJr& _Other) = delete;
	PoppyBrosJr& operator=(PoppyBrosJr&& _Other) noexcept = delete;

protected:

private:

};

