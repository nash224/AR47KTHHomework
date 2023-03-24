#include <iostream>


class TestOperator
{
public:
	int Value;

public:
	// 맴버 이니셜라이저.
	TestOperator(int _Value)
		: Value(_Value)
	{

	}
	int operator[](size_t _Value)
	{
		return Value;
	}


	bool operator==(int _Value)
	{
		return true;
	}

	bool operator!=(int _Value)
	{
		return false;
	}


	// 클래스가 연산자를 사용할수 있게 만들어주는 것.

	//	산술 연산자

	TestOperator& operator+(int _Value)
	{
		return *this + _Value;
	}

	int operator-(int _Value)
	{
		return Value - _Value;
	}


	int operator*(int _Value)
	{
		return Value * _Value;
	}


	double operator/(int _Value)
	{
		return Value / _Value;
	}

	int operator%(int _Value)
	{
		return Value % _Value;
	}

	bool operator>(int _Value)
	{
		if (Value > _Value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator&&(int _Value)
	{
		if (Value && _Value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator||(int _Value)
	{
		if (Value || _Value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//	복합 대입 연산자
	int operator+=(int _Value)
	{
		return Value += _Value;
	}

	int operator-=(int _Value)
	{
		return Value -= _Value;
	}

	int operator*=(int _Value)
	{
		return Value *= _Value;
	}

	double operator/=(int _Value)
	{
		return Value /= _Value;
	}

	int operator<<(int _Value)
	{
		for (int i = 0; _Value > i; i++)
		{
			Value *= 2;
		}
		return Value;
	}

	int operator>>(int _Value)
	{
		for (int i = 0; _Value > i; i++)
		{
			Value /= 2;
		}
		return Value;
	}


	//	증감 연산자

	TestOperator& operator++()
	{
		//return ++ this->Value;
		++Value;
		return *this;
	}

	int operator--()
	{
		return -- this->Value;
	}

	int operator++(int)
	{
		int temp = Value;
		Value++;

		return temp;
	}

	//	후위 연산자는 인자만 넣고 값을 넣지 않아도 동작한다.

	int operator--(int)
	{
		int temp = Value;
		Value--;

		return temp;
	}

	//	비트 연산자

	int operator|(int _Value)
	{
		return Value | _Value;
	}

	int operator&(int _Value)
	{
		return Value & _Value;
	}

	int operator^(int _Value)
	{
		return Value ^ _Value;
	}

	//int operator++(int _Value)
	//{
	//	int temp = _Value;
	//	++_Value;
	//	return temp;
	//}

	//	참조연산자

	TestOperator* operator&()
	{
		return this;
	}

};


int main()
{
	int value = 0;

	TestOperator Test = 30;

	// 연산자 겹지정 함수라고 부릅니다.
	value = Test + 10;


	//value = Test.operator+(10);

	if (Test == 30)
	{
		value = Test - 10;
	}

	if (value <= 40)
	{
		value = Test % 8;
	}

	int Sizeofvalue = sizeof(value);

	value = Test * 2;

	value = Test / 2;
	value = Test >> 2;


	value = Test--;

	int count = 0;

	Test = 0;
	++Test = 10;
	Test + 1 = 20;


	for (int i = 0;
		Test > i;
		Test--)
	{
		count++;
		printf_s("%d번째 Test: %d \n", count, Test.Value);
	}

	Test = 10;

	int a = 0;



}
