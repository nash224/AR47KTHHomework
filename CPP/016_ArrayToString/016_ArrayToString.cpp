
int main()
{
    {
        //  배열은 같은 타입의 변수로 이루어진 집합체이다.며
        //  배열을 구성하는 각 값들은 배열 요소라고 하며, 배열 위치를 가르키는 숫자를 인덱스(index)라고 한다.
        
        //  변수의 초기화 또한 배열도 초기화가 되어하고 낭비되면 좋은 코드라고 볼 수 없다.
        int IntArray01[5] = {};
        //  배열의 길이는 기본적으로 0으로 시작하며 0을 포함한 정수를 가질 수 있다.
        //  이를 제로베이스라고 한다.

        //  배열을 초기화하게 되면 배열 요소는 자동으로 0으로 초기화된다.
    }

    {
        //  배열은 논리형 변수로도 선언이 가능하다.
        bool boolArray01[5] = { true, false, true, true, };
    }

    {
        char charArray01[6] = { 'a', 'b', 'c' };
        //  배열의 축약형이다.
        char charArray02[6] = "abc";

        //  모든 배열의 이름은 시작위치를 표현하게 된다.
        //  [] <= 랜덤인덱스 연산자라고 한다.

        char charArray03[6] = "52561";
        //  문자열 상수 표현식은 마지막에 컴파일러가 0을 붙인다.
    
        char ArrValue1[6] = {};
        //  배열의 주소 계산법은
        //  ArrValue1 200번지라고 하면
        ArrValue1[2];
        //  ArrValue1[정수]
        //  ArrValue1의 시작위치 + (sizeof(자료형) * 정수) 이다.
        //  ArrValue1[2]의 주소는 203번지가 된다.
        
        
    }

    {

        //  배열 요소의 수가 배열 길이를 넘어버리면
        //  char charArray03[6] = "abcdefg";    //  'charArray03': 배열 범위 오버플로입니다. 코드 C2117

        char charArray04[5] = { 'ab', 'b', 'c' };   //  char은 1바이트 변수이기 때문에 bbc라고 값이 나온다.

        int IntArray02[5] = { 'ab','b','c' };

        int b = 10;
    }

    {
        //  배열을 받아볼 수 있다.
        char ArrTest[7] = "abdefg";
        char GetValue = ArrTest[5];

    }


}