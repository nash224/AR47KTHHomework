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

	inline void SetPos(const int2& _Pos) override
	{
		BeforePos = this->GetPos();
		ConsoleGameObject::SetPos(_Pos);
	}

	inline int2 GetBeforePos() const
	{
		return BeforePos;
	}

	inline Parts* GetPrev() const
	{
		return Prev;
	}

	inline Parts* GetNext() const
	{
		return Next;
	}

	// ������ũ�� �Ӹ��� ������ ���� ���� �˷���
	inline static size_t GetPartsCount()
	{
		return PartsCount;
	}
	inline bool GetisFollow() const
	{
		return isFollow;
	}

	inline void SetisFollow(bool _boolean)
	{
		isFollow = _boolean;
	}

	// ArrData�� ����� ���� ������ũ ������ ���� ���ظ�ŭ NonUnitNumberArray ������ Ȯ����
	inline static void SetUnitNumberArray(const int _value)
	{
		NonUnitNumberArray.reserve(_value - PartsCount);
	}

	// NonUnitNumberArray�� ��ĭ�� ���� �������
	inline static void UnitNumberPushback(const int _value)
	{
		NonUnitNumberArray.push_back(_value);
	}

	// ClearUnitNumberArray�� �ʱ�ȭ
	inline static void ClearUnitNumberArray()
	{
		NonUnitNumberArray.resize(0);
	}

	void SetArrData();

	// ArrData�� ��ǥ���� NonUnitNumberArray�� �־���
	static void PutNonUnitNumber();
	// NonUnitNumberArray�� ����� ���� �����ؼ� ��ǥ���� ��ȯ
	static int2 RandomUnitPos();


protected:
	void Update() override;

	void LinktoNext(Parts* _OtherPtr);
	void LinktoPrev(Parts* _OtherPtr);
	int2 Dir = int2::Up;

private:
	Parts* Prev = nullptr;
	Parts* Next = nullptr;

	bool isFollow = false;

	int2 BeforePos = { 0 , 0 };

	static int PartsCount;
	static std::vector<int> NonUnitNumberArray;
};