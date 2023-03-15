﻿
//  char 자료형은 1byte 문자형이며 8bit 정수형이다.
//  

int main()
{
    'A';
    //  A는 문자이며 표현하기위해 고유의 정수를 갖고 있다.
    //  이를 아스키 코드라고 한다.
    //  1byte는 8bit를 표현할 수 있지만, 맨 첫줄은 부호비트임으로
    //  0~127까지 총 128개의 문자를 표현할 수 있다.

    //  아스키코드 외에도 유니코드라는 전산 처리 방식이 존재한다.
    //  유니코드는 2바이트 문자형이고 2바이트를 표현하기 위해 변수값 앞에 L을 붙인다.
    //  
    wchar_t wch = L'6';
    //  다른 국가의 문자가 UTF-8를 쓰더라도 문자 인코딩이 부족할 때가 있다.
    //  이때 인코딩은 문자나 기호들을 컴퓨터가 이용할 수 있게 지정하는 것을 의미한다.
    //  그래서 가끔 '꿿끯' 처럼 문자가 깨지기도 한다. 
    // 
    //  그럴 경우 국가코드를 사용하는 UTF-8이 생겼다.
    //  이는 글자를 1 2 3 4 바이트로 표현한다.
    //  UTF-8은 14부터 표현이 가능하다.
    char ASC = u8'a';

    //  한글이나 한자같은 멀티 바이트는 한 문자당 2바이트를 사용하여 인코딩되는 경우가 있다.


}

//  === 핵심 요약 ===

//  모든 문자는 고유의 정수를 갖고 있다.
//  이를 아스키코드라고 한다.
//  아스키 코드는 128개의 문자를 표현할 수 있다.
//  아스키 코드외에도 유니코드 UTF-8, UTF-16, UTF-32가 존재한다.
//  UTF-8은 1 2 3 4 byte로 표현한다.
//  UTF-8를 쓰더라도 국가가 다르면 문자가 깨질 수 있다.