#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();
	void Forward();

	static int GetAllDirection()
	{
		return EntireDirection;
	}

	void Reverse(int _Reverse)
	{
		EntireDirection = -_Reverse;
	}

private:
	int Dir = 1;
	static int EntireDirection;

};

