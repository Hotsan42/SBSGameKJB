#include "pch.h"

//��������:
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
	// 1. ������Ŭ������ ���
	MyRegisterClass(hInstance);

	// 2. �����츦 ����
	if (false == InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// 3. ������ �޼��� ����
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
			printf("1�� Ű�� ������. \n");
			break;
		case '2':
		case VK_NUMPAD2:
			printf("2�� Ű�� ������. \n");
			break;
		default:
			break;
		}
		break;
	case WM_PAINT:
	{
		//ȭ���� �׸��� �̺�Ʈ
		//�������� �� ȣ�� �ѹ� �ǰ�, InvalidateRect��� �Լ��� ȣ�� ���� �� �ѹ� ����ǰ�
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// hdc�� ��� ������?
		//wstring str = L"�ȳ�";
		//wchar * ���·� ������ֱ� ���ؼ���
		// str.c_str()
		//::TextOut(hdc, 100, 100, str.c_str(), str.length());

		//for (int i = 0; i < 9; i++)
		//{
		//	wchar_t str[100];
		//	wsprintf(str, L"�ȳ��ϼ��� %d", i);
		//	::TextOut(hdc, 100, 100 + 50 * i, str, lstrlenW(str));

		//	//������ ��� �ǽ�
		//	//1��		2��		3��
		//	//4��		5��		6��
		//	//7��		8��		9��
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