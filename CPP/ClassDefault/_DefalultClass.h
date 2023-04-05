#pragma once
class ClassDefault
{
public:
	// constructor desstructor
	ClassDefault();
	~ClassDefault();

	// delete Function
	ClassDefault(const ClassDefault& _Other) = delete;
	ClassDefault(ClassDefault&& _Other) noexcept = delete;
	ClassDefault& operator=(const ClassDefault& _Other) = delete;
	ClassDefault& operator=(ClassDefault&& _Other) noexcept = delete;

protected:

private:

};