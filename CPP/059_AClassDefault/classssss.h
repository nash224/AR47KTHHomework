#pragma once

class classssss
{
public:
	// constructor desstructor
	classssss();
	~classssss();

	//delete Function
	classssss(const classssss& _Other) = delete;
	classssss(classssss&& _Other) noexcept = delete;
	classssss& operator=(const classssss& _Other) = delete;
	classssss& operator=(classssss&& _Other) noexcept = delete;

protected:

private:

};
