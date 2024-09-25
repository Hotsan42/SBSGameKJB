#include "pch.h"

//전역변수:
HINSTANCE _hInstance;
HWND	  _hWnd;

ATOM	  MyRegisterClass(HINSTANCE hInstance);
BOOL	  InitInstance(HINSTANCE instance, int nCmdShow);
LRESULT	  WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);
void SetWindowSize(int x, int y, int width, int height);

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

	SetWindowSize(0, 0, WIN_SIZE_X, WIN_SIZE_Y);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	::AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);

	::SetWindowPos(_hWnd, nullptr, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER);
}

int currentDan = 0;
int mouseX, mouseY;
POINT mousePos = {};

class Enemy
{
public:
	RECT rc;
	bool isLive;

	void Die()
	{
		isLive = false;
	}
	void Draw(HDC hdc)
	{
		::Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
	bool IsLive()
	{
		return isLive;
	}
};

vector<Enemy> enemies;

LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		//윈도우 생성시 발생이벤트
		//여기서 초기화 동작
		srand(time(NULL));

		//60프레임 -> 타이머호출주기
		SetTimer(hWnd, 1, 1000 / 60, NULL);

		//두더지 튀어나오기
		SetTimer(hWnd, 2, 1000, NULL);
		
		for (int i = 0; i < 9; i++)
		{
			Enemy newEnemy;
			newEnemy.isLive = false;
			newEnemy.rc = {
				(i % 3) * 100,
				(i / 3) * 100,
				(i % 3) * 100 + 70,
				(i / 3) * 100 + 70
			};
			enemies.push_back(newEnemy);
		}

		break;

	
	case WM_PAINT:
	{
		//화면을 그리는 이벤트
		//시작했을 때 호출 한번 되고, InvalidateRect라는 함수가 호출 됐을 때 한번 실행되고
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		for (Enemy enemy : enemies)
		{
			if (enemy.IsLive())
			{
				enemy.Draw(hdc);
			}
		}
		
		::EndPaint(hWnd, &ps);
	}
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			InvalidateRect(_hWnd, NULL, true);
			break;

		case 2:
			//두더지 튀어나오는 로직
			SetTimer(hWnd, doonum * 100, 5000, NULL);
			//100, 200, 300, 400, 500, 600, 700, 800, 900으로 만들어지겠죠
			break;

		case 100:
			//두더지 들어가는 로직
			break;
		case 200:
			//두더지 들어가는 로직
			break;
		case 300:
			//두더지 들어가는 로직
			break;
		case 400:
			//두더지 들어가는 로직
			break;
		case 500:
			//두더지 들어가는 로직
			break;
		case 600:
			//두더지 들어가는 로직
			break;
		case 700:
			//두더지 들어가는 로직
			break;
		case 800:
			//두더지 들어가는 로직
			break;
		case 900:
			//두더지 들어가는 로직
			break;

		default:
			break;
		}
		break;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case 'A':
			for (Enemy& enemy : enemies)
			{
				if (enemy.rc.left <= mousePos.x && mousePos.x <= enemy.rc.right)
				{
					if (enemy.rc.bottom <= mousePos.y && mousePos.y <= enemy.rc.bottom)
					{
						enemy.Die();
					}
				}
			}
		}
	}

	case WM_MOUSEMOVE:
	{
		//위치 어케앎?
		mousePos.x = GET_X_LPARAM(lParam);
		mousePos.y = GET_Y_LPARAM(lParam);
	}
		break;

	case WM_DESTROY:
		break;
	default:
		break;
	}


	return DefWindowProc(hWnd, message, wParam, lParam);
}
