#pragma once

class ADefaultClassssasdss
{
public:
	// constructor desstructor
	ADefaultClassssasdss();
	~ADefaultClassssasdss();

	//delete Function
	ADefaultClassssasdss(const ADefaultClassssasdss& _Other) = delete;
	ADefaultClassssasdss(ADefaultClassssasdss&& _Other) noexcept = delete;
	ADefaultClassssasdss& operator=(const ADefaultClassssasdss& _Other) = delete;
	ADefaultClassssasdss& operator=(ADefaultClassssasdss&& _Other) noexcept = delete;

protected:

private:

};
