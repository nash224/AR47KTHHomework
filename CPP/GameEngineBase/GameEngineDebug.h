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


// define으로 정의하는 이유
// => 함수는 인자를 받아 실행 내부코드를 복사 하지만, define은 그냥 코드를 복사 붙여넣기한다.
// 그럼 define이든 함수든 같지 않냐 => 함수는 컴파일러가 검사하기 때문에 내부에서 실행되고,
// define의 경우는 그냥 복붙이기 때문에 외부에서 보여준다.
// 그럼 define은 어디에서 사용하는가 => 에러로 인한 중단점을 걸 필요가 있는 코드이거나 에러코드가 있는 곳에 
// define을 정의하면 외부로 보여주기 때문에 내부에서 확인할 수 있는 함수와달리 디버그가 편리해질 수 있다.
#define MessageBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK);	assert(false);