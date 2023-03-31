#pragma once
//#include "Player.h"
//#include "Monster.h"

class Player;
class Monster;
class ShootingGame
{
public:
	static void Loading();
	static void GameUpdate();
	static void MonsterEndCheck();
	static void Collision();

	static void GameProgress();


private:
	static const int ArrMonsterCount = 14;
	static Player NewPlayer;
	static Monster ArrMonster[ArrMonsterCount];

	ShootingGame() {
	}
};