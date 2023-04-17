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

	inline Parts* GetNext() const
	{
		return Next;
	}

	inline Parts* GetPrev() const
	{
		return Prev;
	}

	inline int2 GetBeforePos() const
	{
		return BeforePos;
	}

	// ������ũ�� �Ӹ��� ������ ���� ���� �˷���
	inline static size_t GetPartsCount()
	{
		return PartsCount;
	}

	// ArrData�� ����� ���� ������ũ ������ ���� ���ظ�ŭ NonUnitNumberArray ������ Ȯ����
	inline static void SetUnitNumberArray(int _value)
	{
		NonUnitNumberArray.reserve(_value - PartsCount);
	}

	// NonUnitNumberArray�� ��ĭ�� ���� �������
	inline static void UnitNumberPushback(int _value)
	{
		NonUnitNumberArray.push_back(_value);
	}

	// ClearUnitNumberArray�� �ʱ�ȭ
	inline static void ClearUnitNumberArray()
	{
		NonUnitNumberArray.resize(0);
	}

	// ArrData�� ��ǥ���� NonUnitNumberArray�� �־���
	static void PutNonUnitNumber();
	// NonUnitNumberArray�� ����� ���� �����ؼ� ��ǥ���� ��ȯ
	static int2 RandomUnitPos();

	inline void SetPos(const int2& _Pos) override
	{
		BeforePos = this->GetPos();
		ConsoleGameObject::SetPos(_Pos);
	}

protected:
	void Update() override;

	void LinktoNext(Parts* _OtherPtr);
	void LinktoPrev(Parts* _OtherPtr);

private:
	Parts* Next = nullptr;
	Parts* Prev = nullptr;


	int2 BeforePos = { 0 , 0 };

	static size_t PartsCount;
	static std::vector<int> NonUnitNumberArray;
};