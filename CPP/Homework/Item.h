#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

// 첫번째 숙제입니다.
// 먹으면 플레이어의 폭탄의 위력이 증가하게 하세요.

class ConsoleGameScreen;
class Item : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Item();
	~Item();

	// delete Function
	Item(const Item& _Other) = delete;
	Item(Item&& _Other) noexcept = delete;
	Item& operator=(const Item& _Other) = delete;
	Item& operator=(Item&& _Other) noexcept = delete; 

protected:
	void Update() override;

private:

};

