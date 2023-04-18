#pragma once
#include "ConsoleGameMath.h"

// Screen에서 움직이는 오브젝트들의 기본기능을 제공한다.
class ConsoleGameObject
{
public:
	// 매개변수의 값으로 내위치를 설정함
	virtual inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	// 내 위치를 반환함
	inline int2 GetPos() const
	{
		return Pos;
	}


	// 내가 죽었는지 알려줌
	bool IsDeath()
	{
		return DeathValue;
	}

	// 내가 죽었나?
	void Death()
	{
		DeathValue = true;
	}

	// 내가 실행하는지 알려줌
	bool IsUpdate()
	{
		return UpdateValue;
	}

	// 실행하고 있음
	void On()
	{
		UpdateValue = true;
	}

	// 꺼져있음
	void Off()
	{
		UpdateValue = false;
	}

	// 나만의 특성을 가짐
	virtual void Update();
	virtual void Render();

protected:
	int2 Pos;
	wchar_t RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;
};

