#include "GameEngineRandom.h"
#include <iostream>

GameEngineRandom GameEngineRandom::MainRandom;

// 생성할때 나의 Seed에 time()을 넣어줌
GameEngineRandom::GameEngineRandom() 
{
	this->Seed = (int)time(nullptr);
	srand(this->Seed);
}

GameEngineRandom::GameEngineRandom(const int _Seed)
{
	this->Seed = _Seed;
	srand(this->Seed);
}

// 2인자를 받아 
int GameEngineRandom::RandomInt(const int _Min, const int _Max)
{
	return (rand() % (_Max + 1 - _Min)) + _Min;
}

GameEngineRandom::~GameEngineRandom() 
{
}