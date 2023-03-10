// 002_include.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//  1.소스 코딩 →  hello.c
//
//  2.hello.c → preprocess(전처리)  →  hello.i
//
//  3.hello.i →  컴파일 →  hello.s
//
//  4.hello.s →  Assemble → hello.o
//
//  5.hello.o(목적파일) + library →  Link → hello.exe

//  불필요한 헤더 파일이 있을 경우 컴파일 시간이 길어진다.

#include <iostream> // iostram 헤더는 표준 라이브러리이다.

//  전처리기(Preprocessor) 지시문은 C컴파일러가 쉽게 인식할 수 있도록
//  /*  */ 와 같은 Comment는 불필요한 부분임으로 제거하고 C언어를 재정리함
// 
//  include 구문은 상수 및 매크로 정의를 포함하는 파일 ( 헤더 파일 )
// 
//  Ctrl + Shift + G = F12 를 누르면 헤더 코드로 이동
// 
//  #include를 쓰는 대신 헤더 파일의 내용을 똑같이 복사해도 
//  똑같은 결과를 출력함
// 
//  사용자가 직접 작성한 헤더를 포함시킬때는 ""를 사용함
//  이때 절대경로도 지정이 가능 
//  Ex) #include "C:\CPP\CustomHeader1"
//

int main()
{
    std::cout << "Hello World!\n";
}
