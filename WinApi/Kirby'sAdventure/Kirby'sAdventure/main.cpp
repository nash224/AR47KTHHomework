#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineBase/GameEngineString.h>


// WIndows Api를 사용하여 창 인터페이스를 구현하는 코드에서는 링커 하위 시스템을 창으로 지정해야 한다.

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    std::string TemporaryName = GameEngineString::ToUpperReturn("isChangeToLargeWord");
    GameEngineCore::EngineStart("Kirby's Adventure", hInstance);


    return 0;
}