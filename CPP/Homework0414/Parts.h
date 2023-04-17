#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <vector>


// ���� :
class Parts : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	Parts* GetNext() const
	{
		return Next;
	}

	Parts* GetPrev() const
	{
		return Prev;
	}

	int2 GetBeforePos() const
	{
		return BeforePos;
	}

	// ������ũ�� �Ӹ��� ������ ���� ���� �˷���
	static size_t GetPartsCount()
	{
		return PartsCount;
	}

	// ArrData�� ����� ���� ������ũ ������ ���� ���ظ�ŭ NonUnitNumberArray ������ Ȯ����
	static void SetUnitNumberArray(int _value)
	{
		NonUnitNumberArray.reserve(_value - PartsCount);
	}

	// NonUnitNumberArray�� ��ĭ�� ���� �������
	static void UnitNumberPushback(int _value)
	{
		NonUnitNumberArray.push_back(_value);
	}

	// ClearUnitNumberArray�� �ʱ�ȭ
	static void ClearUnitNumberArray()
	{
		NonUnitNumberArray.resize(0);
	}

	// ArrData�� ��ǥ���� NonUnitNumberArray�� �־���
	static void PutNonUnitNumber();
	// NonUnitNumberArray�� ����� ���� �����ؼ� ��ǥ���� ��ȯ
	static int2 RandomUnitPos();


protected:
	void Update() override;

	void LinktoNext(Parts* _OtherPtr);
	void LinktoPrev(Parts* _OtherPtr);

	void SetBeforePos(int2 _BeforePos)
	{
		BeforePos = _BeforePos;
	}


private:
	Parts* Next = nullptr;
	Parts* Prev = nullptr;


	int2 BeforePos = { 0 , 0 };

	static size_t PartsCount;
	static std::vector<int> NonUnitNumberArray;
};