#pragma once
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <vector>
#include "Parts.h"

class ConsoleGameScreen;
class Body : public Parts
{
public:
	// constrcuter destructer
	Body();
	~Body();

	// delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	void Update() override;
	static Parts* NotFollowBody();
	static Parts* GetLastFollowBody();

protected:

private:
	bool isFirst = true;

	static int BodyCount;

	// ���� ��ü ����
	void NewBodyCreateLocation();
	// ���� ��ü�� ���� ��ü�� �����Ŵ
	void LinktoPrevBody();
	// ��������� �ٲ�
	void SetDirection();
	// ������ ��ȣ�� ��
	wchar_t GetSign(const int2 _Dir);
};

