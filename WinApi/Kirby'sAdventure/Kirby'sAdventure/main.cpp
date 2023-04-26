#include <GameEnginePlatform/GameEngineWindow.h>

void TestStart(HINSTANCE _Hinst)
{
    GameEngineWindow::MainWindow.Open("Kirby's Adventure", _Hinst);
}

void TestEnd()
{

}

void TestUpdate()
{

}


// WIndows Api를 사용하여 창 인터페이스를 구현하는 코드에서는 링커 하위 시스템을 창으로 지정해야 한다.

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    GameEngineWindow::MessageLoop(hInstance, TestStart, TestUpdate, TestEnd);

    // 윈도우 창은 하나


    return 0;
}