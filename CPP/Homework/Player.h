#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleGameScreen;
class Player : public ConsoleGameObject
{
public:
	static bool IsGameUpdate;

public:
	Player();
	void Update() override;

	bool IsBomb(const int2 _NextPos);
	bool isItem(const int2 _NextPos);

protected:

private:
	int BombPower = 1;
};