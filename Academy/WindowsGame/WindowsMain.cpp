#include "pch.h"

//전역변수:
HINSTANCE _hInstance;
HWND	  _hWnd;

ATOM	  MyRegisterClass(HINSTANCE hInstance);
BOOL	  InitInstance(HINSTANCE instance, int nCmdShow);
LRESULT	  WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevINstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	// 1. 윈도우클래스를 등록
	MyRegisterClass(hInstance);

	// 2. 윈도우를 생성
	if (false == InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// 3. 윈도우 메세지 루프
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}

}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEXW);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = _T("GameClient");
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	return ::RegisterClassExW(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	_hInstance = hInstance;

	HWND hWnd = CreateWindow(_T("GameClient"), _T("GameClient"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	_hWnd = hWnd;

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam)
{
	switch (message)
	{
	case WM_CREATE:
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case '1':
		case VK_NUMPAD1:
			printf("1번 키를 눌렀따. \n");
			break;
		case '2':
		case VK_NUMPAD2:
			printf("2번 키를 눌렀따. \n");
			break;
		default:
			break;
		}
		break;
	case WM_PAINT:
	{
		//화면을 그리는 이벤트
		//시작했을 때 호출 한번 되고, InvalidateRect라는 함수가 호출 됐을 때 한번 실행되고
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// hdc는 어디서 만들지?
		//wstring str = L"안녕";
		//wchar * 형태로 만들어주기 위해서는
		// str.c_str()
		//::TextOut(hdc, 100, 100, str.c_str(), str.length());

		//for (int i = 0; i < 9; i++)
		//{
		//	wchar_t str[100];
		//	wsprintf(str, L"안녕하세요 %d", i);
		//	::TextOut(hdc, 100, 100 + 50 * i, str, lstrlenW(str));

		//	//구구단 찍기 실습
		//	//1단		2단		3단
		//	//4단		5단		6단
		//	//7단		8단		9단
		//}
		wchar_t str[100];
		int count = 1;
		int width = 100;
		int height = 100;
		int wInterval = 100;
		int hInterval = 25;

		/*for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				wsprintf(str, L"%d * %d = %d", i, j, i * j);
				
				int x = 100 + ((i - 1 % 3) * 200);
				int y = 100 + ((i - 1 / 3) * 250);
				y += j * 20;
				TextOut(hdc, x , height + hInterval * j, str, lstrlenW(str));
			}
			if (i % 3 == 0)
			{
				height += hInterval * 9;
			}
		}*/
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				wstring str = format(L"{} * {} = {}", i, j, i * j);
				int x = 100 + ((i - 1) % 3) * 200;
				int y = 100 + ((i - 1)/ 3) * 250;
				y += j * 20;
				TextOut(hdc, x, y, str.c_str(), str.length());
			}
		}
		Draw::Rectangle(hdc, 10, 10, 100, 100);
		::Ellipse(hdc, 500, 500, 600, 600);
		
		::EndPaint(hWnd, &ps);
	}
		break;
	case WM_DESTROY:
		break;
	default:
		break;
	}


	return DefWindowProc(hWnd, message, wParam, lparam);
}