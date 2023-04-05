#pragma once
class My067Template
{
public:
	// constructor desstructor
	My067Template();
	~My067Template();

	// delete Function
	My067Template(const My067Template& _Other) = delete;
	My067Template(My067Template&& _Other) noexcept = delete;
	My067Template& operator=(const My067Template& _Other) = delete;
	My067Template& operator=(My067Template&& _Other) noexcept = delete;

protected:

private:

};