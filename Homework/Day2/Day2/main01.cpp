//숙제-Day2

/*
1.BMI 측정 프로그램 만들기
출력에서
키(m)을 입력
몸무게(kg)을 입력해주세요
BMI 지수 : 24.5
과체중입니다. (0 ~ 18.5 저체중, ~ 23 정상체중, ~ 25 과체중, ~ 30 비만, ~ 무한대 고도비만)
*/

#include <iostream>

using namespace std;

void main()
{
	
	float height=170;
	float weight=65;
	float BMI = 42;

	printf("키가 몇cm인지 숫자만 입력해주세요 : ");
	scanf_s("%f", &height);
	printf("몸무게가 몇kg인지 숫자만 입력해주세요 : ");
	scanf_s("%f", &weight);
	BMI = weight / ((height / 100) * (height / 100));
	if (BMI > 0 && BMI <= 18.5)
	{
		printf("저체중입니다.");
	}
	else if (BMI > 18.5 && BMI <= 23)
	{
		printf("정상체중입니다.");
	}
	else if (BMI > 23 && BMI <= 25)
	{
		printf("과체중입니다.");
	}
	else if (BMI > 25 && BMI <= 30)
	{
		printf("비만입니다.");
	}
	else if(BMI > 30 && BMI <=40)
	{
		printf("고도비만입니다.");
	}
	else if(BMI >= 40)
	{
		printf("사람이 아닙니다.");
	}
}
