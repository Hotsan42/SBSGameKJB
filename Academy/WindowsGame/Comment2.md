# Window API

## Windows API란?

```
#include<Windows.h>
에 있는 함수를 사용하는게 Windows API

API라는 명칭에 대해
Application Programming Interface
프로그래밍할 때 쓰이는 함수 모음집

Android API
- 안드로이드 만들 때 사용하는 함수 모음집

```

## 그럼 굳이 커리큘럼을 따로 빼서 Windows API를 배우는 이유
```

```

## Windows API 초기화

### 1. Main문
```cpp
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevINstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)

```

	- instance - 실행되고 있는 프로그램
	보통 앞에 H가 붙으면 Handle 이라고 생각 (다루다) <- 이것만 사용

	- prevInstance
	이전에 시행되었던 무언가 있으면 넘겨주어라 But 여기서는 사용하지 않음

	- lpCmdLine
	어떤 명령어에 대해서 시행하는 Game에서는 사용 x
	- nCmdShow
	Game에서는 사용 x
### Main문 내용 //외우면 좋음
```cpp
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

```
	윈도우 어플리케이션을 실행시키기 위해서는 저 3가지를 꼭 해야함
	1. 윈도우 클래스 등록
	2. 윈도우 생성
	3. 윈도우 메시지 루프 (중요)
	- 마우스를 움직이거나, 클릭을 하거나
	- 타이머를 설정했는데 타이머 시간이 됐거나,
	- 이벤트들이 어떻게 작동할까에 대한 해석

	-DispatchMessage를 실행 시키게되면
	실행하는 함수가 따로 있음 
	(윈도우 프로시저)

### 윈도우클래스 등록
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
1. 윈도우 클래스를 등록
- MS에서 지정한 함수이기 때문에 MS 문서를 봐야함
//RegisterClassExW
-wcex.lpfnWndProc = WndProc; <- -DispatchMessage를 실행 시키게되면 실행하는 함수(윈도우 프로시저)

### 윈도우 생성
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
// MS 가이드 문서에서 CreateWindow 후에 
//ShowWindw, UpdateWindow 하라고 명시

//_hWnd :실행되고 있는 프로그램 그 자체:
instance - 프로그램별로 존재
window - 실행되는 프로그램 별로 존재

### 윈도우 프로시저
```cpp
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam)
{
	return DefWindowProc(hWnd, message, wParam, lparam);
}
```
// 윈도우 프로시저 - 현재 메세지를 어떻게 처리할지에 대한 함수
// HWND hWnd - 지금 실행되는 프로그램 (어디에 메세지가 온건지)
// UINT message - 어떤 종류의 메세지가 왔는지 (마우스가 움직였는지, 마우스를 클릭했는지, 키보드를 눌렀는지)
// WPARAM wParam - 메시지설명1
// LPARAM lParam - 메세지설명2

마우스를 움직였다는 메세지가 왔는데
마우스가 어디로 움직였는지 알 방법이 없음ㅈ
wParam - X 좌표
lParam - Y 좌표

키보드를 눌렀다.
wParam - 어떤 키를 눌렀는지
lParam - 사용안함

로그 같은 걸 찍을 때
사용자가 뽑기를 했다. (메세지 번호 25)
- 어떤 뽑기를 했냐?
- 몇 개를 깠냐?
- 사용자의 직업은 무엇이냐


