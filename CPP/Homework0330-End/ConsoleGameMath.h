#pragma once

// ������� �� �����.
class int2
{
public:
	// �ܺο� �� �� �ִ� ������ �ִ�.
	int X = 0;
	int Y = 0;

	inline int2()
	{

	}

	// �Ű������� 2���� �����ڰ� ȣ��Ǹ� ��������� �����ϰڴ�.
	inline int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}

	inline int2 Half()
	{
		return { X / 2, Y / 2 };
	}

	bool Check(const int2& _Other)
	{
		return X == _Other.X && Y == _Other.Y;
	}

	// int2��ô�ϴ� ���� ������ �ʴ� �Ű������� �޾�
	// int2�� ������ ���Ͽ� �� ���� ���� ��ȯ�ϰڴٴ� ����
	bool operator==(const int2& _Other) 
	{
		return X == _Other.X && Y == _Other.Y;
	}


};