// 056_HeaderAndCpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "Player.h"
#include "Player.h"
#include "Player.h"
#include "Player.h"
#include "Player.h"

//  #pragma once
//  한 cpp 파일내의 헤더 중복을 제거한다.



int main()
{
    // 컴파일러는 Cpp파일을 전부 검사를 한 후, 
    // 하나의 프로젝트에 내가 친 모든 코드를 하나의 파일로 모으게 된다.
    Player NewPlayer = Player();

    NewPlayer.Damage(20);

    // 나는 했는데? 오류가 난다.
    // 후드려 까일수가 있다.

    // 내가 사용하지 않는 선언문은 컴파일러가 자동으로 삭제할 수 있다.
    // 만약 이를 초기화하지 않고, 쓰게 된다면 에러가 난다.
    // 클래스에서만 국한되지 않고 일반적인 변수도 적용되는 것은 똑같다.
}