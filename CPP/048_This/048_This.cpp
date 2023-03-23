
#include <iostream>

class Player
{
public:
	Player()
	{
	}

	void Damage0(int _Att)
	{
		Hp -= _Att;
	}

	void Damage1(/*Player* const this ,*/int _Att)
	{
		__int64 Address = (__int64)&Hp;
		//	눈에 보이지 않지만, 멤버 변수는 첫번째 인자로
		//	자기자신의 클래스의 포인터가 들어가게 된다.
		//	* const이기 때문에 this의 주소는 바꿀 수 없다.
		//this = nullptr;

		this->Hp -= _Att;
	}

	inline int GetHp()
	{
		return Hp;
	}

	inline void SetHp(int _value)
	{
		Hp = _value;
	}

	inline int GetAtt()
	{
		return Att;
	}

	inline void SetAtt(int _value)
	{

		Att = _value;
	}


	
private:
	int Hp = 100;
	int Att = 30;
	int Def = 5;
};


class Position
{
private:
	int Asite;
	int Bsite;

public:
	Position()
		: Asite(50)
		, Bsite(30)
	{

	}
	int DistanceBetweenAtoB(/*Position* const this*/)
	{
		int value = this->Asite;
		return Asite + Bsite;
	}


};

void GlobalDamage()
{

}

void Test(int _value)
{
	_value = 36262;
}

int main()
{
	int value = 30;
	Test(value);	//	value 값은 바뀌지 않는다.

	Player NewPlayer = Player();

	NewPlayer.SetHp(200);	//	NewPlayer객체의 멤버변수 Hp에 200을 대입
	NewPlayer.SetAtt(20);

	
	Player NewPlayer0 = Player();

	Player NewPlayer1 = Player();
	//	Player클래스의 주소가 다른 객체가 2개 만들어졌다.

	NewPlayer0.Damage0(20);	// Hp = Hp - Att
	NewPlayer1.Damage1(/*&NewPlayer1,*/ 50);
	//	각 객체들이 자신의 멤버변수를 바꿨다.
	
	Position SniperDistance = Position();
	SniperDistance.DistanceBetweenAtoB(/*&SniperDistance*/);

	int a = 0;
}