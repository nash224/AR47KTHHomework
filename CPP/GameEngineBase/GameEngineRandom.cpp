#include "GameEngineRandom.h"
#include <iostream>

GameEngineRandom GameEngineRandom::MainRandom;

// �����Ҷ� ���� Seed�� time()�� �־���
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

// 2���ڸ� �޾� 
int GameEngineRandom::RandomInt(const int _Min, const int _Max)
{
	return (rand() % (_Max + 1 - _Min)) + _Min;
}

GameEngineRandom::~GameEngineRandom() 
{
}