#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

// 객체 생성
Player ShootingGame::NewPlayer;
// 배열 객체 생성
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// 게임이 시작하기 전에 준비한다.
	// 총알이 여러발 나가게 만드세요.

	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알을 쓰는 대상이다.
	// 플레이어가 총알을 들고 있다.
	// 플레이어가 총알의 포인터를 알게 한다.
	// 플레이얼가 총알 배열의 정보를 알게한다
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	// 좌표 형식의 변수에 담는다. <= 싱글톤 패턴을 사용한 스크린 객체에 좌표 형식의 스크린 값을 받는다
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	// NewPlayer 객체에 ScreenSize값의 반틈을 인자로 주겠다.
	// NewPlayer의 위치를 초기화한다.
	NewPlayer.SetPos(ScreenSize.Half());

	// 몬스터의 수만큼 반복을 한다.
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		// 몬스터들의 위치를 초기화한다.
		ArrMonster[i].SetPos({i + 3, 1});
	}

}

void ShootingGame::Collision()
{
	// 총알들의 정보를 가져온다.
	Bullet* BulletArr = Bullet::GetArrBullet();

	// 모든 총알의 수만큼 반복한다.
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		// 총알별로 정보를 CurBullet에 기입한다.
		Bullet& CurBullet = BulletArr[BulletIndex];

		// 총알이 비활성화되면 다음 객체를 검사한다.
		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		// 총알이 활성화 된것만 몬스터와 충돌 검사를한다.
		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			// 몬스터들의 정보를 CurMonster에 기입한다.
			Monster& CurMonster = ArrMonster[MonsterIndex];

			// 현재 몬스터가 비활성화 되면 다음 몬스터를 검사한다.
			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			// 현재 검사중인 몬스터와 총알의 위치가 동일하면
			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				// 총알과 몬스터를 꺼버린다.
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}

void ShootingGame::MonsterEndCheck()
{
	// 1. 움직이게 한다.
	// 왼쪽으로 움직이게 해본다.
	// 오른으로 움직이게 해본다.

	// 2. 끝에 어떠한 몬스터중 단 1개라도 닿았는지 확인한다.
	//    2-1. 왼쪽 끝을체크한다.
	//    2-2. 오른쪽 끝에 닿은걸 체크한다.
	//if (몬스터가 왼쪽 끝에 닿았다)
	//{
	//	int a = 0;
	//}
	// 체크한 결과만을 내뱉는다.
	bool Check = false;
	// 생성된 몬스터의 수만큼 반복을 한다.
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{
		// 각 몬스터의 미래의 좌표를 불러와 담는다
		int2 NextPos = ArrMonster[i].GetNextPos();

		// 각 몬스터 별로 화면밖으로 나가면
		if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{// Check를 참값으로 바꾼다.
			Check = true;
			// 반복문을 종료한다.
			break;
		}
	}

	// 나가지 않았다면
	if (false == Check)
	{ // 반환한다.
		return;
	}


	// 나갈 것 같은 몬스터는
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{
		// 밑으로 내려보내고 방향값을 바꿔라
		ArrMonster[i].Down();
	}



	// 3. 방향을 바꾼다.

	// 4. 내려도 본다.
}

// 게임을 이렇게 돌리겠다.
void ShootingGame::GameUpdate() 
{
	// 게임이 끝날때까지 무한으로 돌린다.
	while (true)
	{
		// 콘솔창의 입력을 전부 초기화한다.
		system("cls");

		// 메인스크린의 객체가 지정된 좌표값의 스크린을 초기화한다.
		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		// 존재하는 총알만 랜더링 하겠다.
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{ // 몬스터 수만큼 랜더링하겠다.
			ArrMonster[i].Render();
		}

		// 몬스터 객체의 충돌을 관리한다.
		MonsterEndCheck();
		// 총알과 몬스터의 충돌 검사를 한다.
		Collision();

		// 객체들을 좌표대로 출력한다.
		ConsoleGameScreen::GetMainScreen().ScreenPrint();


		NewPlayer.Input();
		Bullet::AllUpdate();

		// 몬스터의 수만큼 검사한다.
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

	}
}

void ShootingGame::GameProgress()
{
	// 초기화에 관한 내용을 수행한다.
	Loading();
	// 게임을 랜더링한다.
	GameUpdate();
}