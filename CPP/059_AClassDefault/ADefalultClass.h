#pragma once
class My059AClassDefault
{// Ŭ�������� �⺻������ �����ϴ� �Լ�
public:
	// constructor desstructor
	My059AClassDefault(); // ����Ʈ ������
	~My059AClassDefault(); // ����Ʈ �Ҹ��� 

	// delete Function
	My059AClassDefault(const My059AClassDefault& _Other) = delete; // ����Ʈ ���� ������
	My059AClassDefault(My059AClassDefault&& _Other) noexcept = delete; // Rvalue ���� ������
	My059AClassDefault& operator=(const My059AClassDefault& _Other) = delete; // ����Ʈ ���� ������
	My059AClassDefault& operator=(My059AClassDefault&& _Other) noexcept = delete; // Rvalue ���� ������

protected:

private:

	//

};