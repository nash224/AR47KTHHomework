#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// 게임이 시작하기 전에 준비한다.
	// 총알이 여러발 나가게 만드세요.

	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알의 포인터를 알게 한다.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({i + 3, 1});
	}

}

void ShootingGame::Collision()
{

	Bullet* BulletArr = Bullet::GetArrBullet();

	// 모든 총알과
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = ArrMonster[MonsterIndex];

			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}


// 2, 7, 11, 22
void ShootingGame::MonsterEndCheck()
{
	// 객체 전체를 선택하여
	for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
	{
		// 현재 몬스터의 객체에 대한 정보를 받아온다.
		Monster& CurMonster = ArrMonster[MonsterIndex];
		if (false == CurMonster.IsUpdate())
		{
			continue;
		}

		// 왼쪽벽 충돌검사
		if (0 == CurMonster.GetPos().X)
		{
			for (size_t MonsterIndex_i = 0; MonsterIndex_i < ShootingGame::ArrMonsterCount; MonsterIndex_i++)
			{
				if (false == ArrMonster[MonsterIndex_i].IsUpdate())
				{
					continue;
				}

				// 방향전환
				if (-1 == ArrMonster[MonsterIndex_i].Dir)
				{
					if (false == ArrMonster[MonsterIndex_i].IsUpdate())
					{
						continue;
					}
					// 값 변경
					ArrMonster[MonsterIndex_i].Dir *= -1;
				}
			}

			// 몬스터를 y축으로 한칸이동
			for (size_t MonsterIndex_i = 0; MonsterIndex_i < ShootingGame::ArrMonsterCount; MonsterIndex_i++)
			{
				if (false == ArrMonster[MonsterIndex_i].IsUpdate())
				{
					continue;
				}
				// 값 변경
				ArrMonster[MonsterIndex_i].GetPos().Y += 1;
			}
		}

		// 정상 작동
		// 오른쪽 벽에 대한 충돌 검사
		if (ConsoleGameScreen::ScreenXSize - 1 == ArrMonster[MonsterIndex].GetPos().X)
		{
			int value0 = ArrMonster[0].GetPos().X;
			int value1 = ArrMonster[1].GetPos().X;
			int value13 = ArrMonster[13].GetPos().X;

			// 살아있는 객체만 방향전환
			for (size_t MonsterIndex_i = 0; MonsterIndex_i < ShootingGame::ArrMonsterCount; MonsterIndex_i++)
			{
				if (false == ArrMonster[MonsterIndex_i].IsUpdate())
				{
					continue;
				}

				if (1 == ArrMonster[MonsterIndex_i].Dir)
				{

					if (false == ArrMonster[MonsterIndex_i].IsUpdate())
					{
						continue;
					}

					// 값 변경
					ArrMonster[MonsterIndex_i].Dir *= -1;
				}
			}

			// 살아있는 객체만 지정된 y 좌표에 1 더함
			for (size_t MonsterIndex_i = 0; MonsterIndex_i < ShootingGame::ArrMonsterCount; MonsterIndex_i++)
			{
				if (false == ArrMonster[MonsterIndex_i].IsUpdate())
				{
					continue;
				}
				// 값 변경
				ArrMonster[MonsterIndex_i].GetPos().Y += 1;
			}
		}
		//if (0 == ArrMonster[MonsterIndex].GetPos().X || 
		//	ShootingGame::ArrMonsterCount -1 == ArrMonster[MonsterIndex].GetPos().X)
		//{
		//	continue;
		//}
		//else
		//{
		//	ArrMonster[MonsterIndex].GetPos().X += ArrMonster[MonsterIndex].Dir;
		//}

		// 방향값에 따라 한칸씩 이동

		// 충돌검사가 끝난 객체 좌표 이동
		ArrMonster[MonsterIndex].GetPos().X += ArrMonster[MonsterIndex].Dir;

		// 버그 : 몬스터가 오른쪽 벽을 한칸 뚫고 들어감 
		//        -> 오른쪽 벽 충돌 조건문은 정상
		
	}
}

void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Render();
		}

		MonsterEndCheck();
		Collision();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}