#pragma once
class My059AClassDefault
{
public:
	// constructor desstructor
	My059AClassDefault();
	~My059AClassDefault();

	// delete Function
	My059AClassDefault(const My059AClassDefault& _Other) = delete;
	My059AClassDefault(My059AClassDefault&& _Other) noexcept = delete;
	My059AClassDefault& operator=(const My059AClassDefault& _Other) = delete;
	My059AClassDefault& operator=(My059AClassDefault&& _Other) noexcept = delete;

protected:

private:

};