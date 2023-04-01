#include "ShootingGame.h"


Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ArrMonsterCount];

void ShootingGame::Loading()
{
	// �Ѿ��� ������ ������ ���弼��.

	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({ 3 + i, 1 });
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

		for (size_t MonsterIndex = 0; MonsterIndex < ArrMonsterCount; MonsterIndex++)
		{
			ArrMonster[MonsterIndex].Render();
		}

		Bullet* BulletArr = Bullet::GetArrBullet();

		// ��� �Ѿ�
		for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
		{
			Bullet& CurBullet = BulletArr[BulletIndex];

			// ��� ����
			for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
			{
				// Monster ������ Ÿ���� CurMonster ������ ArrMonster�� ���� ��ü�� �����ض�
				Monster& CurMonster = ArrMonster[MonsterIndex];

				// �̰ɷ� �Ѿ˰� ������ ��ġ�� ��ġ�� �����ض�
				if (CurMonster.GetPos() == CurBullet.GetPos())
				{
					ArrMonster[MonsterIndex].Death();
					BulletArr[BulletIndex].Off();
				}

			}

		}

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
	ShootingGame::Loading();
	ShootingGame::GameUpdate();
}