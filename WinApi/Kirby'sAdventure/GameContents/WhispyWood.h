#pragma once

// Ό³Έν :
class WhispyWood
{
public:
	// constrcuter destructer
	WhispyWood();
	~WhispyWood();

	// delete Function
	WhispyWood(const WhispyWood& _Other) = delete;
	WhispyWood(WhispyWood&& _Other) noexcept = delete;
	WhispyWood& operator=(const WhispyWood& _Other) = delete;
	WhispyWood& operator=(WhispyWood&& _Other) noexcept = delete;

protected:

private:

};

