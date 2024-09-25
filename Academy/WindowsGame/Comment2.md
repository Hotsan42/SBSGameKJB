# Window API

## Windows API��?

```
#include<Windows.h>
�� �ִ� �Լ��� ����ϴ°� Windows API

API��� ��Ī�� ����
Application Programming Interface
���α׷����� �� ���̴� �Լ� ������

Android API
- �ȵ���̵� ���� �� ����ϴ� �Լ� ������

```

## �׷� ���� Ŀ��ŧ���� ���� ���� Windows API�� ���� ����
```

```

## Windows API �ʱ�ȭ

### 1. Main��
```cpp
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevINstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)

```

	- instance - ����ǰ� �ִ� ���α׷�
	���� �տ� H�� ������ Handle �̶�� ���� (�ٷ��) <- �̰͸� ���

	- prevInstance
	������ ����Ǿ��� ���� ������ �Ѱ��־�� But ���⼭�� ������� ����

	- lpCmdLine
	� ��ɾ ���ؼ� �����ϴ� Game������ ��� x
	- nCmdShow
	Game������ ��� x
### Main�� ���� //�ܿ�� ����
```cpp
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

```
	������ ���ø����̼��� �����Ű�� ���ؼ��� �� 3������ �� �ؾ���
	1. ������ Ŭ���� ���
	2. ������ ����
	3. ������ �޽��� ���� (�߿�)
	- ���콺�� �����̰ų�, Ŭ���� �ϰų�
	- Ÿ�̸Ӹ� �����ߴµ� Ÿ�̸� �ð��� �ưų�,
	- �̺�Ʈ���� ��� �۵��ұ ���� �ؼ�

	-DispatchMessage�� ���� ��Ű�ԵǸ�
	�����ϴ� �Լ��� ���� ���� 
	(������ ���ν���)

### ������Ŭ���� ���
```cpp

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
```
1. ������ Ŭ������ ���
- MS���� ������ �Լ��̱� ������ MS ������ ������
//RegisterClassExW
-wcex.lpfnWndProc = WndProc; <- -DispatchMessage�� ���� ��Ű�ԵǸ� �����ϴ� �Լ�(������ ���ν���)

### ������ ����
```cpp
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
```
// MS ���̵� �������� CreateWindow �Ŀ� 
//ShowWindw, UpdateWindow �϶�� ���

//_hWnd :����ǰ� �ִ� ���α׷� �� ��ü:
instance - ���α׷����� ����
window - ����Ǵ� ���α׷� ���� ����

### ������ ���ν���
```cpp
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam)
{
	return DefWindowProc(hWnd, message, wParam, lparam);
}
```
// ������ ���ν��� - ���� �޼����� ��� ó�������� ���� �Լ�
// HWND hWnd - ���� ����Ǵ� ���α׷� (��� �޼����� �°���)
// UINT message - � ������ �޼����� �Դ��� (���콺�� ����������, ���콺�� Ŭ���ߴ���, Ű���带 ��������)
// WPARAM wParam - �޽�������1
// LPARAM lParam - �޼�������2

���콺�� �������ٴ� �޼����� �Դµ�
���콺�� ���� ���������� �� ����� ������
wParam - X ��ǥ
lParam - Y ��ǥ

Ű���带 ������.
wParam - � Ű�� ��������
lParam - ������

�α� ���� �� ���� ��
����ڰ� �̱⸦ �ߴ�. (�޼��� ��ȣ 25)
- � �̱⸦ �߳�?
- �� ���� ����?
- ������� ������ �����̳�


