#pragma once
#include "Parts.h"

// Ό³Έν :
class Head : public Parts
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	static bool IsPlay;

	inline static bool GetWintrigger()
	{
		return Wintrigger;
	}

protected:
	bool isBody(int2 _NextPos);
	void CreateBody();
	void IsBodyCheck();
	void NewBodyCreateCheck();
	void Update() override;

private:
	bool FirstEatBody = false;

	static bool Wintrigger;
};

