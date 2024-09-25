#include "pch.h"

//��������:
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
		//������ ������ �߻��̺�Ʈ
		//���⼭ �ʱ�ȭ ����
		srand(time(NULL));

		//60������ -> Ÿ�̸�ȣ���ֱ�
		SetTimer(hWnd, 1, 1000 / 60, NULL);

		//�δ��� Ƣ�����
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
		//ȭ���� �׸��� �̺�Ʈ
		//�������� �� ȣ�� �ѹ� �ǰ�, InvalidateRect��� �Լ��� ȣ�� ���� �� �ѹ� ����ǰ�
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
			//�δ��� Ƣ����� ����
			SetTimer(hWnd, doonum * 100, 5000, NULL);
			//100, 200, 300, 400, 500, 600, 700, 800, 900���� �����������
			break;

		case 100:
			//�δ��� ���� ����
			break;
		case 200:
			//�δ��� ���� ����
			break;
		case 300:
			//�δ��� ���� ����
			break;
		case 400:
			//�δ��� ���� ����
			break;
		case 500:
			//�δ��� ���� ����
			break;
		case 600:
			//�δ��� ���� ����
			break;
		case 700:
			//�δ��� ���� ����
			break;
		case 800:
			//�δ��� ���� ����
			break;
		case 900:
			//�δ��� ���� ����
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
		//��ġ ���ɾ�?
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
