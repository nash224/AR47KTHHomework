#pragma once
#include <GameEngineBase/GameEngineDebug.h>
// #include <Program Files/Adobe/Adobe Creative Cloud Experience/>

// typedef int DataType;

// 템플릿은 여러 자료형에 대해 동작하도록 만들어 준다.
// <>는 타입 매개변수를 나타내는 기호이다.
// 타입 매개변수는 모든 자료형을 받아들일 수 있다.
template<typename DataType>
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;



	// constrcuter
	GameEngineArray(size_t _Value)
	{
		if (0 >= _Value)
		{
			MessageBoxAssert("0크기의 배열은 만들수 없습니다");
		}

		ReSize(_Value);
		// ArrPtr = new int[100];
	}

	GameEngineArray()
	{
	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		// 얕은 복사라고 합니다.
		//ArrCount = _Other.ArrCount;
		//ArrPtr = _Other.ArrPtr;

		// 나만의 메모리를 만들고 
		// 깊은 복사라고 합니다.
		ReSize(_Other.ArrCount);
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			 ArrPtr[i] = _Other[i];
		}

		return *this;
	}

	size_t Count() 
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index) const
	{
		return ArrPtr[_Index];
	}

	void ReSize(int _Value) 
	{
		// 20줄 안팍.
		// 삼항 연산자 써보시면 좋을겁니다.

		// 기존의 할당된 배열을 알고 있는것은 
		// 섣불리 지우면 안된다.

		// 기존의 있던 값에서 현재의 배열이 복사한다음 삭제해야 한다.

		DataType* NewPtr = new DataType[_Value];
		int CopySize = _Value < ArrCount ? _Value : ArrCount;

		for (size_t i = 0; i < CopySize; i++)
		{
			NewPtr[i] = ArrPtr[i];
		}

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = NewPtr;
		ArrCount = _Value;
	}

protected:

private:
	size_t ArrCount = 0;
	DataType* ArrPtr = nullptr;

};

