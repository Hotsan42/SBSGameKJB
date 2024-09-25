## 숙제풀이

```
1번 ~ 9번키를 누르면
각각 
1단 나오게
2단 나오게
등등으로 바꾸고

0번 키를 누르면 1단 ~ 9단 까지 다 나오도록
```


### 수도코드
#### 키인풋
 1. 1~9까지 입력하는것을 currentInput 으로 저장
#### Render
```
	if (1 <= currentInput and currentInput <= 9)
	{
		화면 중앙 currentInput Render
	}
	else
		1단 ~ 9단 출력
```


## 마우스 이동감지 (위치감지)
```
WM_MOUSEMOVE 를 통해 마우스 이동감지를 합니다.
```

## 타이머
```
타이머란
 - 타이머 호출 주기가 되면 WM_TIMER를 호출할수있게하는 기능

사용방법
 - SetTimer(_hWnd, 타이머ID, 타이머 호출주기(ms), NULL);
 - KillTimer(_hWnd, 타이머ID)
 - WM_TIMER / wParam이 타이머ID로 오게됨

게임이 주로 60프레임
```


### 프레임이란?
```
FPS - Frame Per Seconds
1초에 화면이 몇번 전환되느냐
[현재 우리입장] 1초에 InvalidateRect를 몇번 호출하느냐

60fps -> 1초에 60번 화면이 전환된다.
타이머에서 InvalidateRect를 호출시켜줄건데
1000 / 60 ms 를 호출주기로 가지면
60fps를 유지 가능
```

## 충돌체크 **(게임에서 가장 많이 쓰이는 기술)**

게임의 많은 로직이 충돌체크에서 시작

오늘 배울 충돌체크는 점과 사각형 충돌 (아이템클릭, 버튼클릭, 마우스클릭하는 대부분읙 것들)
```
수학적인 내용
if( rc.left <= mousePos.x and mousePos.x <= rc.right ) then
	if ( rc.top <= mousePos.y and mousePos.y <= rc.bottom) then
		충돌
```

실습
네모 9개를 그리고
네모 클릭시 그 네모를 지워주게끔


---
### 숙제 - 두더지잡기
```
두더지 9마리가 1초에 랜덤으로 하나씩 땅속에서 나왔다가
5초후에 다시 들어감
그리고 튀어나와있을때 두더지를 클릭하거나 A키를 누르면(택일)
점수가 1점 오름

게임은 끝나지 않음
```