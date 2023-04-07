#pragma once
#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>



typedef int DataType;

class GameEngineArray
{
public:
	// constructor에서 배열의 크기를 받기 위해 size_t를 사용함
	GameEngineArray(size_t _value)
		// 생성자에서 ArrPtr을 초기화해줌 
		: ArrPtr(new DataType[_value]) // new int[_value]
		// 반복문에 사용될 ArrCount변수를 초기화
		, ArrCount(_value)
	{
		if (0 <= _value)
		{
			MessageBoxAssert("0 크기의 배열은 만들 수 없습니다");
		}
	}

	// destructor에서 생성자에서 객체가 생성되면서 리터널 이니셜라이저 초기화로 동적으로 메모리를 할당한 것을 
	// 객체에서 사용한 동적 메모리를 다시 해제하는 정의를 한다.
	~GameEngineArray()
	{
		// ArrPtr이 따로 해제되었는지 체크
		if (nullptr != ArrPtr)
		{
			// 힙에서 생성된 배열 메모리를 해제
			delete[] ArrPtr;
			// ArrPtr의 주소를 nullptr로 초기화 => 주소값을 0으로 함
			ArrPtr = nullptr;
		}
	}


	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;

	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	//                         호출받은 인자값은 바뀌지 않음
	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		//ArrCount = _Other.ArrCount;
		//ArrPtr = _Other.ArrPtr;

		if (this == &_Other) // 자기 자신에 대한 대입 방지
		{
			return *this;
		}

		// 깊은복사는 나만의 메모리를 만들고 복사한다.
		ReSize(_Other.ArrCount);

		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			ArrPtr[i] = _Other[i];
		}

		return *this;
	}

	DataType& operator[](size_t _value) const
	{
		return ArrPtr[_value];
	}


	// 반환값은 없고 배열의 크기를 조정하기위해 만든 함수
	void ReSize(int _value) // 5
	{
		// 확인
		if (nullptr == ArrPtr)
		{
			return;
		}

		int NewCount = 0;
		DataType* TemporaryArrPtr = new DataType[_value];
		NewCount = _value < ArrCount ? _value : ArrCount;

		for (size_t i = 0; i < NewCount; i++)
		{
			TemporaryArrPtr[i] = ArrPtr[i];
		}

		// 기존 배열 삭제
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
		
		// 이러면 안되는 이유
		// => 얕은 복사는 주소값을 대입받음
		// 따라서 동적 할당받은 변수의 주소를 공유함
		// 즉 생성하고 다시받으면 2중으로 받게된다는 소리
		//if (nullptr == ArrPtr)
		//{
		//	ArrPtr = new DataType[NewCount];
		//}

		// 대입
		ArrPtr = TemporaryArrPtr;

		// 값확인
		//DataType ArrPtr2 = ArrPtr[2];
		// 더미값 확인
		//DataType ArrPtr6 = ArrPtr[6];

		// 임시 배열 생성 => 함수내에서 지울 예정 => 배열삭제


		ArrCount = _value;


			//ArrPtr = TemporaryArrPtr;

			//// _value가 5일 때
			//DataType ArrPtr3 = ArrPtr[3];
			//DataType ArrPtr6 = ArrPtr[6];

	}
	

	// ArrCount를 호출하기 위한 멤버함수
	size_t GetCount()
	{
		return ArrCount;
	}






protected:

private:
	// ArrPtr에 동적 메모리로 받을 예정
	// 우선 포인터 값에 nullptr로 초기화
	DataType* ArrPtr = nullptr;
	size_t ArrCount;


};