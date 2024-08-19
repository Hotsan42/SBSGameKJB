#include <iostream>
using namespace std;

void main()
{
	float num1;
	float num2;
	int choice;

	float result;

	printf("숫자1을 입력해주세요 : \n");
	scanf_s("%f", &num1);
	printf("숫자2를 입력해주세요 : \n");
	scanf_s("%f", &num2);
	printf("어떤 연산을 진행할까요? : ( 1 : +, 2 : -, 3 : *, 4 : / ) \n");
	scanf_s("%d", &choice);
	if (choice == 1) 
	{
		result = num1 + num2;
	}
	else if (choice == 2)
	{
		result = num1 - num2;
	}
	else if (choice == 3)
	{
		result = num1 * num2;
	}
	else if (choice == 4)
	{
		result = num1 / num2;
	}
	printf("결과 : %.3f\n", result);
}


//숙제
// 수도코드 적을 노트 들고 다니기!

 
/*
1.BMI 측정 프로그램 만들기
출력에서 
키(m)을 입력
몸무게(kg)을 입력해주세요 
BMI 지수 : 24.5
과체중입니다. (0 ~ 18.5 저체중, ~ 23 정상체중, ~ 25 과체중, ~ 30 비만, ~ 무한대 고도비만)
*/

/*
학점 계산기
출력에서
중간평가 점수 입력
기말 점수 입력
출석점수 입력
과제점수 입력
F입니다. (0~60 F, ~70 D, ~80 C, ~90 D, ~ 100 A)
*/

/*
홀수짝수 계산기
숫자를 입력해주세요.  (14)
14는 짝수입니다.
*/