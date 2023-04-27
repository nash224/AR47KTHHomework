#pragma once

// Ό³Έν :
class CraneFever
{
public:
	// constrcuter destructer
	CraneFever();
	~CraneFever();

	// delete Function
	CraneFever(const CraneFever& _Other) = delete;
	CraneFever(CraneFever&& _Other) noexcept = delete;
	CraneFever& operator=(const CraneFever& _Other) = delete;
	CraneFever& operator=(CraneFever&& _Other) noexcept = delete;

protected:

private:

};

