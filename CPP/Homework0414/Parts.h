#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <vector>


// Ό³Έν :
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


	Parts* GetNext()
	{
		return Next;
	}

	Parts* GetPrev()
	{
		return Prev;
	}

	static size_t GetPartsCount()
	{
		return PartsCount;
	}

	static void SetUnitNumberArray(size_t _value)
	{
		NonUnitNumberArray.reserve(_value - PartsCount);
	}

	static void UnitNumberPushback(size_t _value)
	{
		NonUnitNumberArray.push_back(_value);
	}

	static void ClearUnitNumberArray()
	{
		NonUnitNumberArray.resize(0);
	}

	static void PutNonUnitNumber();


protected:
	void Link(Parts* _Other, Parts* _Other2);
	void Update() override;

private:
	Parts* Next;
	Parts* Prev;
	static size_t PartsCount;

	static std::vector<int> NonUnitNumberArray;
};

