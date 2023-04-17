#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <vector>


// 설명 :
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

	// 스네이크의 머리와 몸통을 합한 수를 알려줌
	inline static size_t GetPartsCount()
	{
		return PartsCount;
	}

	// ArrData의 요소의 수에 스네이크 단위의 수를 빼준만큼 NonUnitNumberArray 공간을 확보함
	inline static void SetUnitNumberArray(int _value)
	{
		NonUnitNumberArray.reserve(_value - PartsCount);
	}

	// NonUnitNumberArray에 빈칸의 수를 집어넣음
	inline static void UnitNumberPushback(int _value)
	{
		NonUnitNumberArray.push_back(_value);
	}

	// ClearUnitNumberArray을 초기화
	inline static void ClearUnitNumberArray()
	{
		NonUnitNumberArray.resize(0);
	}

	// ArrData의 좌표값을 NonUnitNumberArray에 넣어줌
	static void PutNonUnitNumber();
	// NonUnitNumberArray의 요소의 수를 리롤해서 좌표값을 반환
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