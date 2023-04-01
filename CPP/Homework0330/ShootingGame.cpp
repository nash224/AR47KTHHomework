#include "ShootingGame.h"


Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ArrMonsterCount];

void ShootingGame::Loading()
{
	// 총알이 여러발 나가게 만드세요.

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



		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		Bullet::AllRender();

		for (size_t MonsterIndex = 0; MonsterIndex < ArrMonsterCount; MonsterIndex++)
		{
			ArrMonster[MonsterIndex].Render();
		}

		Bullet* BulletArr = Bullet::GetArrBullet();

		// 모든 총알
		for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
		{
			Bullet& CurBullet = BulletArr[BulletIndex];

			// 모든 몬스터
			for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
			{
				// Monster 포인터 타입의 CurMonster 변수는 ArrMonster의 현재 객체에 대입해라
				Monster& CurMonster = ArrMonster[MonsterIndex];

				// 이걸로 총알과 몬스터의 위치가 겹치면 실행해라
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