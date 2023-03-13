
int main()
{
	// 삼항 연산자
	//	A ? B : C
	//	참 또는 거짓인 메모리 ? 참일때 메모리 : 거짓일때 메모리

	int Left = 10;
	int Right = 100;
	int result;

	result = Left != Right ? 2000 : 5000;
	result = Left == Right ? 2000 : 5000;

	//	sizeof	연산자 
	//	()안의 메모리영역의 바이트 크기를 리턴함

	result = sizeof(int);
	result = sizeof(Left);
	result = sizeof(short);
	result = sizeof(bool);
		//sizeof(void);
	//	void는 함수가 값을 반환하지 않도록 지정하는 함수 반환 형식으로 
	//	함수 사용시 메모리가 제거되는 void는 사용할 수 없다.

}