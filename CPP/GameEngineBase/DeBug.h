#pragma once
class GameEngineBase
{
public:
	// constructor desstructor
	GameEngineBase();
	~GameEngineBase();

	// delete Function
	GameEngineBase(const GameEngineBase& _Other) = delete;
	GameEngineBase(GameEngineBase&& _Other) noexcept = delete;
	GameEngineBase& operator=(const GameEngineBase& _Other) = delete;
	GameEngineBase& operator=(GameEngineBase&& _Other) noexcept = delete;

protected:

private:

};