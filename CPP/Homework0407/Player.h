#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>


class ConsoleGameScreen;
// �θ� ConsoleGameObject�� ���� ������� ��ӹްڴ�.
class Player : public ConsoleGameObject 
{
public:
	static bool IsGameUpdate;
	
	Player();
	void Update() override;

protected:

private:
};

