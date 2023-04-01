#pragma once
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include "Bullet.h"
#include "ConsoleGameScreen.h"


class ShootingGame
{
public:
	
	static void Loading();
	static void GameUpdate();

	static void GameProgress();

private:
	static const int ArrMonsterCount = 14;
	static Player NewPlayer;
	static Monster ArrMonster[ArrMonsterCount];

	ShootingGame() {
	}
};