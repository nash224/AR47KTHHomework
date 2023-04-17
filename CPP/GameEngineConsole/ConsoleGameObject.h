#pragma once
#include "ConsoleGameMath.h"

// Screen���� �����̴� ������Ʈ���� �⺻����� �����Ѵ�.
class ConsoleGameObject
{
public:
	// �Ű������� ������ ����ġ�� ������
	inline void SetPos(const int2& _Value)
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

	bool GetisFollow() const
	{
		return isFollow;
	}

	void SetisFollow(bool _boolean)
	{
		isFollow = _boolean;
	}

	ConsoleGameObject* GetNext() const
	{
		return Next;
	}

	ConsoleGameObject* GetPrev() const
	{
		return Prev;
	}

	// ������ Ư���� ����
	virtual void Update();
	virtual void Render();

	int2 GetBeforePos() const
	{
		return BeforePos;
	}


protected:
	int2 Pos;
	char RenderChar = ' ';

	void LinktoNext(ConsoleGameObject* _OtherPtr);
	void LinktoPrev(ConsoleGameObject* _OtherPtr);
	void SetBeforePos(int2 _BeforePos)
	{
		BeforePos = _BeforePos;
	}

private:
	bool UpdateValue = true;
	bool DeathValue = false;

	int2 BeforePos = { 0 , 0 };

	bool isFollow = false;

	ConsoleGameObject* Next = nullptr;
	ConsoleGameObject* Prev = nullptr;

};

