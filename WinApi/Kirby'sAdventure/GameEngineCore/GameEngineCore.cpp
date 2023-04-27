#include "GameEngineCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

std::string GameEngineCore::Title = "";
std::map<std::string, class GameEngineLevel*> GameEngineCore::AllLevel;

GameEngineCore::GameEngineCore()
{
}

GameEngineCore::~GameEngineCore()
{
}


void GameEngineCore::CoreStart(HINSTANCE _Inst)
{
    GameEngineWindow::MainWindow.Open(Title, _Inst);
}

void GameEngineCore::CoreUpdate()
{

}

void GameEngineCore::CoreEnd()
{

}




void GameEngineCore::EngineStart(const std::string& _Title, HINSTANCE _Inst)
{
    GameEngineDebug::LeckCheck();

    Title = _Title;
    GameEngineWindow::MessageLoop(_Inst, CoreStart, CoreUpdate, CoreEnd);
}