#pragma once
#include "Object.h"

// Ό³Έν :
class Level : public Object
{
public:
	// constrcuter destructer
	Level();
	~Level();

	// delete Function
	Level(const Level& _Other) = delete;
	Level(Level&& _Other) noexcept = delete;
	Level& operator=(const Level& _Other) = delete;
	Level& operator=(Level&& _Other) noexcept = delete;

	static Level Inst;

protected:

private:
	int A;
	int B;


};