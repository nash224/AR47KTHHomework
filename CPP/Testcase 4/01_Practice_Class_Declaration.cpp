#include <iostream>


class timer
{
private:
	int hour;
	int Minute;
	int second;

public:
	timer(int _h, int _m, int _s)
		: hour(_h)
		, Minute(_m)
		, second(_s)
	{

	}

	void Set_time(int _h, int _m, int _s);
	
	void Out_time();

};

//	시간 설정
void timer::Set_time(int _h, int _m, int _s)
{
	hour = _h;
	Minute = _m;
	second = _s;
}

//	시간 출력
void timer::Out_time()
{
	std::cout << "현재 시각은 " << hour << "시 " << Minute << "분 " << second << "초 입니다." << std::endl;
}


int main()
{
	timer Newtime = timer(5, 10, 22);
	Newtime.Out_time();

	Newtime.Set_time(6, 20, 36);
	Newtime.Out_time();

}