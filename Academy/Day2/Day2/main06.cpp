#include <iostream>

using namespace std;

void main()
{
	int number = 0;
	number = ((1 == 1) + 2);
	printf("%d", number);
}


//[연산자] : 사칙연산
// = 이것도 연산자 (대입연산자)
//  (왼쪽의 변수에게 오른쪽의 값을 넣어준다)

//연산자에 순서가 있어요.
//비교연산자, 대입연산자, 산술연산자 (+ - / *)

// () << 제일 우선순위가 높음
// true = 1, false = 0

// %
// 정수형끼리 나눴을때 나머짓값을 구하는 연산자 (/는 몫을 구함)