#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include "Parts.h"
#include <vector>

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

protected:

private:
	bool isFirst = true;

	static int BodyCount;

	Parts* GetLastFollowBody();
	// ���� ��ü ����
	void NewBodyCreateLocation();
	// ���� ��ü�� ���� ��ü�� �����Ŵ
	void LinktoPrevBody();
	// ��������� �˷���
	void SetDirection();
	// ������ ��ȣ�� ��
	wchar_t GetSign(const int2 _Dir);


};

