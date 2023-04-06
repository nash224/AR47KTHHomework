#pragma once
#include <iostream>

typedef int DataType;

class GameEngineArray
{
public:
	// constructor���� �迭�� ũ�⸦ �ޱ� ���� size_t�� �����
	GameEngineArray(size_t _value)
		// �����ڿ��� ArrPtr�� �ʱ�ȭ���� 
		: ArrPtr(new DataType[_value]) // new int[_value]
		// �ݺ����� ���� ArrCount������ �ʱ�ȭ
		, ArrCount(_value)
	{
		
	}

	// destructor���� �����ڿ��� ��ü�� �����Ǹ鼭 ���ͳ� �̴ϼȶ����� �ʱ�ȭ�� �������� �޸𸮸� �Ҵ��� ���� 
	// ��ü���� ����� ���� �޸𸮸� �ٽ� �����ϴ� ���Ǹ� �Ѵ�.
	~GameEngineArray()
	{
		// ArrPtr�� ���� �����Ǿ����� üũ
		if (nullptr != ArrPtr)
		{
			// ������ ������ �迭 �޸𸮸� ����
			delete[] ArrPtr;
			// ArrPtr�� �ּҸ� nullptr�� �ʱ�ȭ => �ּҰ��� 0���� ��
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



	// ��ȯ���� ���� �迭�� ũ�⸦ �����ϱ����� ���� �Լ�
	void ReSize(size_t _value) // 5
	{
		// Ȯ��
		if (nullptr == ArrPtr)
		{
			return;
		}

		_value < ArrCount ? ArrCount = _value : ArrCount;

		// ���� �ӽ� �迭 ���� => �Լ������� ���� ����
		TemporaryArrPtr = new DataType[ArrCount];

	

		// �Ű�������ŭ ����
		for (size_t i = 0; i < ArrCount; i++)
		{
			TemporaryArrPtr[i] = ArrPtr[i];
			printf_s("TemporaryArrPtr : %d\n", TemporaryArrPtr[i]);
		}

		////TemporaryArrPtr = ArrPtr;
		//DataType TempArrayvalue0 = TemporaryArrPtr[0];
		//DataType TempArrayvalue3 = TemporaryArrPtr[3];

		// ���� �迭 ����
		CheckNullptr(ArrPtr);

		
		// ����
		if (nullptr == ArrPtr)
		{
			ArrPtr = new DataType[ArrCount];
		}

		// ����
		ArrPtr = TemporaryArrPtr;

		// ��Ȯ��
		//DataType ArrPtr2 = ArrPtr[2];
		// ���̰� Ȯ��
		//DataType ArrPtr6 = ArrPtr[6];

		// �ӽ� �迭 ���� => �Լ������� ���� ���� => �迭����
		CheckNullptr(TemporaryArrPtr);


			//ArrPtr = TemporaryArrPtr;

			//// _value�� 5�� ��
			//DataType ArrPtr3 = ArrPtr[3];
			//DataType ArrPtr6 = ArrPtr[6];

	}
	

	// ArrCount�� ȣ���ϱ� ���� ����Լ�
	size_t GetCount()
	{
		return ArrCount;
	}






protected:

private:
	// ArrPtr�� ���� �޸𸮷� ���� ����
	// �켱 ������ ���� nullptr�� �ʱ�ȭ
	DataType* ArrPtr = nullptr;
	DataType* TemporaryArrPtr = nullptr;
	size_t ArrCount;


};