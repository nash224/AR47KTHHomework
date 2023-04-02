#include "ShootingGame.h"

#include <iostream>

// ���� ����� ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// ������ �����ϱ� ���� �غ��Ѵ�.
	// �Ѿ��� ������ ������ ���弼��.

	// �����ϸ� ������ ��� �Ѿ��� �߻���� �ʾ������̹Ƿ� �� ����.
	Bullet::AllOff();

	// �÷��̾ �Ѿ��� �����͸� �˰� �Ѵ�.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// �÷��̾ ȭ���� �߾ӿ� ��ġ��Ų��.
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

	// ��� �Ѿ˰�
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
	for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
	{
		// ���� ������ ��ü�� ���� ������ �޾ƿ´�.
		Monster& CurMonster = ArrMonster[MonsterIndex];
		if (false == CurMonster.IsUpdate())
		{
			continue;
		}

		if (0 == CurMonster.GetPos().X)
		{
			for (size_t MonsterIndex_i = 0; MonsterIndex_i < ShootingGame::ArrMonsterCount; MonsterIndex_i++)
			{
				if (false == ArrMonster[MonsterIndex_i].IsUpdate())
				{
					continue;
				}

				
				if (-1 == ArrMonster[MonsterIndex_i].Dir)
				{
					if (false == ArrMonster[MonsterIndex_i].IsUpdate())
					{
						continue;
					}

					ArrMonster[MonsterIndex_i].Dir *= -1;
				}
			}

			for (size_t MonsterIndex_i = 0; MonsterIndex_i < ShootingGame::ArrMonsterCount; MonsterIndex_i++)
			{
				if (false == ArrMonster[MonsterIndex_i].IsUpdate())
				{
					continue;
				}
				ArrMonster[MonsterIndex_i].GetPos().Y += 1;
			}
		}

		// ���� �۵�
		if (ConsoleGameScreen::ScreenXSize - 1 == ArrMonster[MonsterIndex].GetPos().X)
		{
			int value0 = ArrMonster[0].GetPos().X;
			int value1 = ArrMonster[1].GetPos().X;
			int value13 = ArrMonster[13].GetPos().X;

			// ����ִ� ��ü�� ������ȯ
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

					ArrMonster[MonsterIndex_i].Dir *= -1;
				}
			}

			// ����ִ� ��ü�� ������ y ��ǥ�� 1 ����
			for (size_t MonsterIndex_i = 0; MonsterIndex_i < ShootingGame::ArrMonsterCount; MonsterIndex_i++)
			{
				if (false == ArrMonster[MonsterIndex_i].IsUpdate())
				{
					continue;
				}
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

		// ���Ⱚ�� ���� ��ĭ�� �̵�


		ArrMonster[MonsterIndex].GetPos().X += ArrMonster[MonsterIndex].Dir;

	}
}

void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// ĳ���� ��ġ�� ���ڸ� �ϳ� ����.
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