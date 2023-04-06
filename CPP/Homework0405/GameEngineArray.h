#pragma once
#include <iostream>

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
			TemporaryArrPtr = nullptr;
		}
	}


	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;

	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		ArrPtr = _Other.ArrPtr;
		ArrCount = _Other.ArrCount;

		return *this;
	}

	DataType& operator[](const size_t _value)
	{
		return ArrPtr[_value];
	}

	void CheckNullptr(DataType* _Array)
	{
		if (nullptr != _Array)
		{
			delete[] _Array;
			_Array = nullptr;
		}
	}



	// 반환값은 없고 배열의 크기를 조정하기위해 만든 함수
	void ReSize(size_t _value) // 5
	{
		// 확인
		if (nullptr == ArrPtr)
		{
			return;
		}

		_value < ArrCount ? ArrCount = _value : ArrCount;

		// 힙에 임시 배열 생성 => 함수내에서 지울 예정
		TemporaryArrPtr = new DataType[ArrCount];

	

		// 매개변수만큼 대입
		for (size_t i = 0; i < ArrCount; i++)
		{
			TemporaryArrPtr[i] = ArrPtr[i];
			printf_s("TemporaryArrPtr : %d\n", TemporaryArrPtr[i]);
		}

		////TemporaryArrPtr = ArrPtr;
		//DataType TempArrayvalue0 = TemporaryArrPtr[0];
		//DataType TempArrayvalue3 = TemporaryArrPtr[3];

		// 기존 배열 삭제
		CheckNullptr(ArrPtr);

		
		// 생성
		if (nullptr == ArrPtr)
		{
			ArrPtr = new DataType[ArrCount];
		}

		// 대입
		ArrPtr = TemporaryArrPtr;

		// 값확인
		//DataType ArrPtr2 = ArrPtr[2];
		// 더미값 확인
		//DataType ArrPtr6 = ArrPtr[6];

		// 임시 배열 생성 => 함수내에서 지울 예정 => 배열삭제
		CheckNullptr(TemporaryArrPtr);


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
	DataType* TemporaryArrPtr = nullptr;
	size_t ArrCount;


};