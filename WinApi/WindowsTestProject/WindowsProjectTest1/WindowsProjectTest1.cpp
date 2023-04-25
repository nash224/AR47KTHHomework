// WindowsProjectTest1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProjectTest1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:

// 전방선언
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


// 윈도우의 핸들 방식에 대해서 이해해야 합니다.
// 윈도우는 진입점을 지들이 바꿔놨다.

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

    // 윈도우가 응용프로그래머에게 주는 우리 프로그램의 등록번호
    // ex) 너는 301211번이야 앞으로 나한테 뭔가를 부탁할때 301211내놔.
    // HINSTANCE hInstance

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECTTEST1, szWindowClass, MAX_LOADSTRING);

    // 윈도우 클래스의 인스턴스를 받아 커널에 등록한다.
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECTTEST1));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
        // GetMessage()함수가 메세지 큐에서 메세지를 꺼내 msg 인스턴스에 저장한다(없을때까지 반복)
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            // 두개의 메세지를 하나로 병합
            TranslateMessage(&msg);

            //메세지를 처리하는 함수에 메세지 전달
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    // 구조체 크기
    wcex.cbSize = sizeof(WNDCLASSEX);

    // 윈도우 크기를 변경하면 다시 그린다.
    wcex.style          = CS_HREDRAW | CS_VREDRAW;

    // 메세지 처리에 사용될 함수의 이름을 기재
    // 함수 포인터형식으로 메세지에서 처리될 행동이 생길시, 윈도우 클래스가 대신 처리한다.
    wcex.lpfnWndProc    = WndProc;

    // 클래스와 윈도우를 위한 여분의 메모리크기
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;

    // 락 : 여러 스레드를 실행하는 환경에서 자료에 대한 접근을 강제하기 위한 동기화 메커니즘
    // 이른바 뮤택스라고도 함
    // WinMain() 함수에서 첫번째 매개변수로 넘어온 응용프로그램의 인스턴스 값을 넘겨줌
    wcex.hInstance      = hInstance;

    // 기본아이콘 설정  = nullptr
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECTTEST1));

    // 기본커서 설정 
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);

    // 윈도우 색을 결정
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+3);

    // 메뉴이름 작성    = 요즘에는 안씀
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECTTEST1);

    // 윈도우 클래스의 이름을 문자열로 작성, 이 형식의 이름은 "(사용자지정)"
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));


    // "AAAAA" 윈도우 형식은 메뉴를 사용하지 않아.
    // 윈도우 형식을 등록하는 함수
    // 윈도우 인스턴스의 주소를 매개변수로 넘기면 커널에 등록된다.
    // 커널에 등록한 윈도우 인스턴스는 윈도우 생성시 사용한다.
    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   // 윈도우 클래스를 이용하여 윈도우를 생성하는 함수
   // HandleWindow의 인스턴스 hWnd를 생성 => "AAAAA"형식 윈도우를 만들어 줘
   HWND hWnd = CreateWindowW(
       szWindowClass, // 윈도우 클래스 이름 "AAAAA"
       /*szTitle*/  L"Kirby's Adventure", // 타이틀
       WS_OVERLAPPEDWINDOW, // 윈도우 스타일을 선택
       CW_USEDEFAULT, // 모니터에 생성된 윈도우의 시작위치 X값 => 시작점 위치 X
       0, // 시작점 위치 Y
       /*CW_USEDEFAULT*/900, // 생성되는 윈도우의 폭 값 => 끝점 X
       700, // 끝점 Y
       nullptr, 
       nullptr, 
       hInstance, 
       nullptr);

   if (!hWnd) 
   {
      return FALSE;
   }

   // 창을 보여주는 함수(나타낼 윈도우의 값, 화면에 출력하는 방법)
   ShowWindow(hWnd, nCmdShow);
   // WM_PRINT 메세지를 보내서 출력하도록 함
   UpdateWindow(hWnd);

   return TRUE;
}

// 윈도우 메세지 처리과정
// 이벤트 발생 -> 이벤트 감지 -> 정수 타입인 메시지를 보내는 방법을 선택
// -> 큐에 정수값 메세지가 쌓임 -> WinMain() 함수는 메세지 큐에서 메세지를 꺼냄
// -> 꺼낸 메세지를 해석 메세지 처리 함수에 전달 -> TranslateMessage()함수로 변형
// -> DisPatchMessage()함수로 메세지를 처리하는 함수에 메세지 전달
// -> 메세지 처리함수가 WndProc()라면 WndProc()함수는 메세지를 받아서 반응
// -> 출력



int Value = 0;


//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

// 메세지 처리 함수(생성된 윈도우의 주소 값(어떤 메세지가 왔는지 알려줌), 양의 정수 타입인 메세지 번호
//                  , Word Parameter의 약자로 데이터를 넘겨 받을때 handle 값 및 정수 인자
//                  , Long Parameter의 약자로 32비트 값의 메세지 종류를 해석함)
// 위의 각 인자타입은 메세지의 종류에 따라 다르게 처리해야 함으로 switch문이 필요하다.

// 메세지 처리부분
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    // DefWindowProc()함수가 처리되지 않은 기본 메세지를 처리해주기 때문에
    // 원하는 메세지만 case문을 만들어서 사용하면 된다.
    switch (message)
    {
    case WM_CREATE:
    {
        int a = 0;
        break;
    }
    case WM_SETFOCUS:
    {
        int a = 0;
        break;
    }
    case WM_KILLFOCUS:
    {
        int a = 0;
        break;
    }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    // 모든 메세지 중에 우선순위가 높은 확률로 가장 낮다.
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...


            Rectangle(hdc, 100 + Value, 100, 200 + Value, 200);

            ++Value;


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
