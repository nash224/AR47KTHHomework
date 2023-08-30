#pragma once
#include "GameEngineObject.h"

// ���� : ȭ�� �Ǵ� ���� ������
//        ex) Ÿ��Ʋ ���, �÷��� ���, ���� �忬
class GameEngineLevel : public GameEngineObject
{
public:
	// constrcuter destructer
	GameEngineLevel();
	~GameEngineLevel();

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:

private:

};
