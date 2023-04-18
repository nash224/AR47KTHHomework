#pragma once
#include "ConsoleGameMath.h"

// Screen���� �����̴� ������Ʈ���� �⺻����� �����Ѵ�.
class ConsoleGameObject
{
public:
	// �Ű������� ������ ����ġ�� ������
	virtual inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	// �� ��ġ�� ��ȯ��
	inline int2 GetPos() const
	{
		return Pos;
	}


	// ���� �׾����� �˷���
	bool IsDeath()
	{
		return DeathValue;
	}

	// ���� �׾���?
	void Death()
	{
		DeathValue = true;
	}

	// ���� �����ϴ��� �˷���
	bool IsUpdate()
	{
		return UpdateValue;
	}

	// �����ϰ� ����
	void On()
	{
		UpdateValue = true;
	}

	// ��������
	void Off()
	{
		UpdateValue = false;
	}

	// ������ Ư���� ����
	virtual void Update();
	virtual void Render();

protected:
	int2 Pos;
	wchar_t RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeathValue = false;
};

