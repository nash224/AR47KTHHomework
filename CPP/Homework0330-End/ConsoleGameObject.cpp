#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

// 캐릭터를 랜더링 하겠다.
void ConsoleGameObject::Render() 
{
	if (false == IsUpdate())
	{
		return;
	}
	// 반환 타입이 메인 스크린 객체이고, 좌표에 대한 위치와 상징 아이콘을 매개변수로 받아 
	// 게임 좌표애 RenderChar를 대입한다.
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, RenderChar);

}