#include "Monster.h"
#include "ConsoleGameScreen.h"

Monster::Monster() 
{
	RenderChar = 'M';
}

// 존재하는 몬스터를 실시간으로 적용겠다.
void Monster::Update() 
{
	// 몬스터가 존재하지 않으면 반환
	if (false == IsUpdate())
	{
		return;
	}
	// 밑으로 내려갔으면
	if (true == DownCheck)
	{
		// 변수를 false로 초기화하고
		DownCheck = false;
		// 반환한다.
		return;
	}

	// 몬스터가 존재하거나, 밑으로 내려가지 않으면, 방향값에 따라 좌표를 집어넣겠다.
	Pos.X += Dir;
}