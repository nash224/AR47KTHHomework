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

	// 스네이크의 머리와 몸통을 합한 수를 알려줌
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

	// ArrData의 요소의 수에 스네이크 단위의 수를 빼준만큼 NonUnitNumberArray 공간을 확보함
	inline static void SetUnitNumberArray(const int _value)
	{
		NonUnitNumberArray.reserve(_value - PartsCount);
	}

	// NonUnitNumberArray에 빈칸의 수를 집어넣음
	inline static void UnitNumberPushback(const int _value)
	{
		NonUnitNumberArray.push_back(_value);
	}

	// ClearUnitNumberArray을 초기화
	inline static void ClearUnitNumberArray()
	{
		NonUnitNumberArray.resize(0);
	}

	void SetArrData();

	// ArrData의 좌표값을 NonUnitNumberArray에 넣어줌
	static void PutNonUnitNumber();
	// NonUnitNumberArray의 요소의 수를 리롤해서 좌표값을 반환
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