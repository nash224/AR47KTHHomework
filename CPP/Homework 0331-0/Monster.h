#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();

	int Dir = 1;

	void Update();


private:

};

