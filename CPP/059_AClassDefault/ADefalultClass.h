#pragma once
class My059AClassDefault
{// 클래스에서 기본적으로 존재하는 함수
public:
	// constructor desstructor
	My059AClassDefault(); // 디폴트 생성자
	~My059AClassDefault(); // 디폴트 소멸자 

	// delete Function
	My059AClassDefault(const My059AClassDefault& _Other) = delete; // 디폴트 복사 생성자
	My059AClassDefault(My059AClassDefault&& _Other) noexcept = delete; // Rvalue 복사 생성자
	My059AClassDefault& operator=(const My059AClassDefault& _Other) = delete; // 디폴트 대입 연산자
	My059AClassDefault& operator=(My059AClassDefault&& _Other) noexcept = delete; // Rvalue 대입 연산자

protected:

private:

	//

};