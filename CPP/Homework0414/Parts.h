#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

// Ό³Έν :
class Parts : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	void Link(Parts* _Other, Parts* _Other2);

	Parts* GetNext()
	{
		return Next;
	}

	Parts* GetPrev()
	{
		return Prev;
	}

protected:
	void Update() override;

private:
	Parts* Next;
	Parts* Prev;
};

