#pragma once

// 설명 : 모든 기본적인 행동을 제안하는 클래스
class GameEngineObject
{
public:
	// constrcuter destructer
	GameEngineObject();
	~GameEngineObject();

	// delete Function
	GameEngineObject(const GameEngineObject& _Other) = delete;
	GameEngineObject(GameEngineObject&& _Other) noexcept = delete;
	GameEngineObject& operator=(const GameEngineObject& _Other) = delete;
	GameEngineObject& operator=(GameEngineObject&& _Other) noexcept = delete;


	virtual void Start() {};

	virtual void Update() {};

	virtual void Render() {};

	virtual void Release() {};

	void On()
	{
		IsUpdateValue = true;
	}

	void Off()
	{
		IsUpdateValue = false;
	}
	
	void Death()
	{
		IsDeathValue = true;
	}

	bool IsUpdate() const
	{
		return true == IsUpdateValue && false == IsDeathValue;
	}

	bool IsDeath() const
	{
		return IsDeathValue;
	}

protected:

private:
	bool IsUpdateValue = true;
	bool IsDeathValue = false;

};

