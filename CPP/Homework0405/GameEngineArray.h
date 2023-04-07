#pragma once
#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>



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
		if (0 <= _value)
		{
			MessageBoxAssert("0 ũ���� �迭�� ���� �� �����ϴ�");
		}
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
		}
	}


	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;

	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	//                         ȣ����� ���ڰ��� �ٲ��� ����
	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		//ArrCount = _Other.ArrCount;
		//ArrPtr = _Other.ArrPtr;

		if (this == &_Other) // �ڱ� �ڽſ� ���� ���� ����
		{
			return *this;
		}

		// ��������� ������ �޸𸮸� ����� �����Ѵ�.
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


	// ��ȯ���� ���� �迭�� ũ�⸦ �����ϱ����� ���� �Լ�
	void ReSize(int _value) // 5
	{
		// Ȯ��
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

		// ���� �迭 ����
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
		
		// �̷��� �ȵǴ� ����
		// => ���� ����� �ּҰ��� ���Թ���
		// ���� ���� �Ҵ���� ������ �ּҸ� ������
		// �� �����ϰ� �ٽù����� 2������ �ްԵȴٴ� �Ҹ�
		//if (nullptr == ArrPtr)
		//{
		//	ArrPtr = new DataType[NewCount];
		//}

		// ����
		ArrPtr = TemporaryArrPtr;

		// ��Ȯ��
		//DataType ArrPtr2 = ArrPtr[2];
		// ���̰� Ȯ��
		//DataType ArrPtr6 = ArrPtr[6];

		// �ӽ� �迭 ���� => �Լ������� ���� ���� => �迭����


		ArrCount = _value;


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
	size_t ArrCount;


};