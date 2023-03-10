
//	연산자는 단항 연산자(메모리 영역이 1개), 이항 연산자(메모리 영역이 2개), 삼항 연산자(메모리 영역이 3개)가 있음
// 
//	()는 가로 연산자


int main()
{
	int MonsterHp01 = 10;
	int MonsterMp01 = 2;
	int result;

	//	산술 연산자

	result = MonsterHp01 + MonsterMp01;	
	result = MonsterHp01 - MonsterMp01;
	result = MonsterHp01 * MonsterMp01;
	result = MonsterHp01 / MonsterMp01;

	//	논리 연산자
	bool Temp1;	//	참과 거짓으로 나뉘어져 있음
	Temp1 = true;
	Temp1 = false;

	int Temp2 = true;

	result = Temp1 && Temp2;	//	&&는 and를 의미함
	result = Temp1 || Temp2;	//	||는 or을 의미함

	//	비교 연산자
	result = MonsterHp01 == MonsterMp01;
	result = MonsterHp01 != MonsterMp01;
	result = MonsterHp01 > MonsterMp01;
	result = MonsterHp01 < MonsterMp01;
	result = MonsterHp01 >= MonsterMp01;
	result = MonsterHp01 <= MonsterMp01;

}