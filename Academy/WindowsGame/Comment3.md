# Window API 1일차
---
## 1. 구구단 찍기

### 구구단 찍을 때 필요한 기능
 1. 글자 출력하는 방법
 ```cpp
 // TextOut 
 TextOut(HDC hdc, int x, int y, LPCWSTR lpString, int c)

 //hdc - Device Context (화면 구조체)
 // x, y - 어떤 위치에 
 //lpString - 어떤 글자에
 // c - 문자열 길이

 //콘솔에서 printf랑 같은 기능
 // 나중에 쓸 예정
 // 보톤 개발할 때 옆에 콘솔 창 띄워두고 합니다.
 //printf는 콘솔창에 써지고
 //TextOut은 화면에 그려짐

 //LPCWSTR - WCHAR* 형태
 //WCHAR - wchar_t
 ```

 ### WCHAR, CHAR 차이
 ```
 //wchar_t - 은 무엇일까
 //char, wchar

 char - 1byte
 wchar - 2byte

 한글은 2byte고
 영문은 1byte 입니다.

 1byte는 크기가 256 
 그러다보니 전세계 문자를 다 표현 x

 1byte는 UTF-8(ASCII)이라고 하는 문자열 포맷을 사용
 UTF - 국제적으로 ?bit를사용할 때 65는 0 32는 a 이렇게 표현하자. 문자열 규격

 2byte를 적었는데 
 어떤 컴퓨터에서는 aa라고 인식하고 어떤 컴퓨터에서는 이상한 문자로 인식

 이거를 하나로 통일

 보통 해외국가까지 퍼블리싱을 생각하면
 UTF-16으로 작업하게 됩니다.

 UTF-8 - char
 UTF-16 - wchar
 ```

## 2. 사각형 그리기
### 사각형 그릴 때 필요한 기능
1. 사각형을 그리는 방법

```cpp
//사각형 그리기
Rectangle(hdc, left, top, right, bottom);
//원 그리기
Ellipse(hdc, left, top, right, bottom);

left - 좌측 x좌표
top - 상단 y좌표
right - 우측 x 좌표
bottom  하단 y 좌표

//windows api 좌표계는 좌측 상단이 0,0 입니다.

// 사각형을 그리거나 타원을 그릴 때 
// x, y, width, height 이게 좀 더 좋을것 같은데
// 저희만의 함수로 만들어줄 예정

//Windows API 의 함수를 사용하기 편하게 

//국제 시간 KST 9시인데 UTC는 0시니까


```

### namespace
```
namespace는 이름공간

using namespace std;
//std를 생략하고 함수를 작성하겠다.
//std :: cout ==> cout

```

### 숙제
```
1번 ~ 9번키를 누르면
각각 
1단 나오게
2단 나오게
등등으로 바꾸고

0번 키를 누르면 1단 ~ 9단 까지 다 나오도록

```