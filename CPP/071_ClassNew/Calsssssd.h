#pragma once
class My071ClassNew
{
public:
	// constructor desstructor
	My071ClassNew();
	~My071ClassNew();


	My071ClassNew(const My071ClassNew& _Other) = delete;
	My071ClassNew(My071ClassNew&& _Other) noexcept = delete;
	My071ClassNew& operator=(const My071ClassNew& _Other) = delete;
	My071ClassNew& operator=(My071ClassNew&& _Other) noexcept = delete;

protected:

private:

};