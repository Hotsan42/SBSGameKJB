//����-Day2

/*
1.BMI ���� ���α׷� �����
��¿���
Ű(m)�� �Է�
������(kg)�� �Է����ּ���
BMI ���� : 24.5
��ü���Դϴ�. (0 ~ 18.5 ��ü��, ~ 23 ����ü��, ~ 25 ��ü��, ~ 30 ��, ~ ���Ѵ� ����)
*/

#include <iostream>

using namespace std;

void main()
{
	
	float height=170;
	float weight=65;
	float BMI = 42;

	printf("Ű�� ��cm���� ���ڸ� �Է����ּ��� : ");
	scanf_s("%f", &height);
	printf("�����԰� ��kg���� ���ڸ� �Է����ּ��� : ");
	scanf_s("%f", &weight);
	BMI = weight / ((height / 100) * (height / 100));
	if (BMI > 0 && BMI <= 18.5)
	{
		printf("��ü���Դϴ�.");
	}
	else if (BMI > 18.5 && BMI <= 23)
	{
		printf("����ü���Դϴ�.");
	}
	else if (BMI > 23 && BMI <= 25)
	{
		printf("��ü���Դϴ�.");
	}
	else if (BMI > 25 && BMI <= 30)
	{
		printf("���Դϴ�.");
	}
	else if(BMI > 30 && BMI <=40)
	{
		printf("�����Դϴ�.");
	}
	else if(BMI >= 40)
	{
		printf("����� �ƴմϴ�.");
	}
}
