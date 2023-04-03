#include "ShootingGame.h"

#include <iostream>

// ���� ����� ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

// ��ü ����
Player ShootingGame::NewPlayer;
// �迭 ��ü ����
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// ������ �����ϱ� ���� �غ��Ѵ�.
	// �Ѿ��� ������ ������ ���弼��.

	// �����ϸ� ������ ��� �Ѿ��� �߻���� �ʾ������̹Ƿ� �� ����.
	Bullet::AllOff();

	// �÷��̾ �Ѿ��� ���� ����̴�.
	// �÷��̾ �Ѿ��� ��� �ִ�.
	// �÷��̾ �Ѿ��� �����͸� �˰� �Ѵ�.
	// �÷��̾� �Ѿ� �迭�� ������ �˰��Ѵ�
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// �÷��̾ ȭ���� �߾ӿ� ��ġ��Ų��.
	// ��ǥ ������ ������ ��´�. <= �̱��� ������ ����� ��ũ�� ��ü�� ��ǥ ������ ��ũ�� ���� �޴´�
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	// NewPlayer ��ü�� ScreenSize���� ��ƴ�� ���ڷ� �ְڴ�.
	// NewPlayer�� ��ġ�� �ʱ�ȭ�Ѵ�.
	NewPlayer.SetPos(ScreenSize.Half());

	// ������ ����ŭ �ݺ��� �Ѵ�.
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		// ���͵��� ��ġ�� �ʱ�ȭ�Ѵ�.
		ArrMonster[i].SetPos({i + 3, 1});
	}

}

void ShootingGame::Collision()
{
	// �Ѿ˵��� ������ �����´�.
	Bullet* BulletArr = Bullet::GetArrBullet();

	// ��� �Ѿ��� ����ŭ �ݺ��Ѵ�.
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		// �Ѿ˺��� ������ CurBullet�� �����Ѵ�.
		Bullet& CurBullet = BulletArr[BulletIndex];

		// �Ѿ��� ��Ȱ��ȭ�Ǹ� ���� ��ü�� �˻��Ѵ�.
		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		// �Ѿ��� Ȱ��ȭ �Ȱ͸� ���Ϳ� �浹 �˻縦�Ѵ�.
		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			// ���͵��� ������ CurMonster�� �����Ѵ�.
			Monster& CurMonster = ArrMonster[MonsterIndex];

			// ���� ���Ͱ� ��Ȱ��ȭ �Ǹ� ���� ���͸� �˻��Ѵ�.
			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			// ���� �˻����� ���Ϳ� �Ѿ��� ��ġ�� �����ϸ�
			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				// �Ѿ˰� ���͸� ��������.
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}

void ShootingGame::MonsterEndCheck()
{
	// 1. �����̰� �Ѵ�.
	// �������� �����̰� �غ���.
	// �������� �����̰� �غ���.

	// 2. ���� ��� ������ �� 1���� ��Ҵ��� Ȯ���Ѵ�.
	//    2-1. ���� ����üũ�Ѵ�.
	//    2-2. ������ ���� ������ üũ�Ѵ�.
	//if (���Ͱ� ���� ���� ��Ҵ�)
	//{
	//	int a = 0;
	//}
	// üũ�� ������� ����´�.
	bool Check = false;
	// ������ ������ ����ŭ �ݺ��� �Ѵ�.
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{
		// �� ������ �̷��� ��ǥ�� �ҷ��� ��´�
		int2 NextPos = ArrMonster[i].GetNextPos();

		// �� ���� ���� ȭ������� ������
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{// Check�� �������� �ٲ۴�.
			Check = true;
			// �ݺ����� �����Ѵ�.
			break;
		}
	}

	// ������ �ʾҴٸ�
	if (false == Check)
	{ // ��ȯ�Ѵ�.
		return;
	}


	// ���� �� ���� ���ʹ�
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{
		// ������ ���������� ���Ⱚ�� �ٲ��
		ArrMonster[i].Down();
	}



	// 3. ������ �ٲ۴�.

	// 4. ������ ����.
}

// ������ �̷��� �����ڴ�.
void ShootingGame::GameUpdate() 
{
	// ������ ���������� �������� ������.
	while (true)
	{
		// �ܼ�â�� �Է��� ���� �ʱ�ȭ�Ѵ�.
		system("cls");

		// ���ν�ũ���� ��ü�� ������ ��ǥ���� ��ũ���� �ʱ�ȭ�Ѵ�.
		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// ĳ���� ��ġ�� ���ڸ� �ϳ� ����.
		NewPlayer.Render();
		// �����ϴ� �Ѿ˸� ������ �ϰڴ�.
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{ // ���� ����ŭ �������ϰڴ�.
			ArrMonster[i].Render();
		}

		// ���� ��ü�� �浹�� �����Ѵ�.
		MonsterEndCheck();
		// �Ѿ˰� ������ �浹 �˻縦 �Ѵ�.
		Collision();

		// ��ü���� ��ǥ��� ����Ѵ�.
		ConsoleGameScreen::GetMainScreen().ScreenPrint();


		NewPlayer.Input();
		Bullet::AllUpdate();

		// ������ ����ŭ �˻��Ѵ�.
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

	}
}

void ShootingGame::GameProgress()
{
	// �ʱ�ȭ�� ���� ������ �����Ѵ�.
	Loading();
	// ������ �������Ѵ�.
	GameUpdate();
}