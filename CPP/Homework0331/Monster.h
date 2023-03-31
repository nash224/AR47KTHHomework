#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();

	static int GetAllDirection()
	{
		return EntireDirection;
	}

	void Reverse(int _Reverse)
	{
		EntireDirection = -_Reverse;
	}

	void Forward();

	static bool GetCanMosnterGo()
	{
		return CanMosnterGo;
	}




private:
	int Dir = 1;
	static int EntireDirection;

	bool IsForward = false;

	static bool CanMosnterGo;
};

