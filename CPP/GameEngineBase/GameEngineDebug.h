#pragma once


#include <Windows.h>
#include <assert.h>

class GameEngineDebug
{
public:
	// constructor desstructor
	GameEngineDebug();
	~GameEngineDebug();

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;

	static void LeckCheck();

protected:

private:

};


// define���� �����ϴ� ����
// => �Լ��� ���ڸ� �޾� ���� �����ڵ带 ���� ������, define�� �׳� �ڵ带 ���� �ٿ��ֱ��Ѵ�.
// �׷� define�̵� �Լ��� ���� �ʳ� => �Լ��� �����Ϸ��� �˻��ϱ� ������ ���ο��� ����ǰ�,
// define�� ���� �׳� �����̱� ������ �ܺο��� �����ش�.
// �׷� define�� ��𿡼� ����ϴ°� => ������ ���� �ߴ����� �� �ʿ䰡 �ִ� �ڵ��̰ų� �����ڵ尡 �ִ� ���� 
// define�� �����ϸ� �ܺη� �����ֱ� ������ ���ο��� Ȯ���� �� �ִ� �Լ��ʹ޸� ����װ� ������ �� �ִ�.
#define MessageBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK);	assert(false);