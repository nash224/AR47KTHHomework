#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>


class ConsoleGameScreen;
// 부모 ConsoleGameObject에 대한 멤버들을 상속받겠다.
class Player : public ConsoleGameObject 
{
public:
	static bool IsGameUpdate;
	
	Player();
	void Update() override;

protected:

private:
};

