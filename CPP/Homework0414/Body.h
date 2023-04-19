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
	// 몸통 객체 생성
	void NewBodyCreateLocation();
	// 현재 객체와 이전 객체를 연결시킴
	void LinktoPrevBody();
	// 진행방향을 알려줌
	void SetDirection();
	// 정해진 기호를 줌
	wchar_t GetSign(const int2 _Dir);


};

