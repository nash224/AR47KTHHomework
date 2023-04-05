#pragma once

class GameEngineArray1
{
public:
	// constructor desstructor
	GameEngineArray1();
	~GameEngineArray1();

	//delete Function
	GameEngineArray1(const GameEngineArray1& _Other) = delete;
	GameEngineArray1(GameEngineArray1&& _Other) noexcept = delete;
	GameEngineArray1& operator=(const GameEngineArray1& _Other) = delete;
	GameEngineArray1& operator=(GameEngineArray1&& _Other) noexcept = delete;

protected:

private:

};
