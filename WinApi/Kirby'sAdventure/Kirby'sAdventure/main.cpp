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


// WIndows Api�� ����Ͽ� â �������̽��� �����ϴ� �ڵ忡���� ��Ŀ ���� �ý����� â���� �����ؾ� �Ѵ�.

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    GameEngineWindow::MessageLoop(hInstance, TestStart, TestUpdate, TestEnd);

    // ������ â�� �ϳ�


    return 0;
}