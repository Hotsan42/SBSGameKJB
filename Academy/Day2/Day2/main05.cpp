#include <iostream>
using namespace std;

void main()
{
	float num1;
	float num2;
	int choice;

	float result;

	printf("����1�� �Է����ּ��� : \n");
	scanf_s("%f", &num1);
	printf("����2�� �Է����ּ��� : \n");
	scanf_s("%f", &num2);
	printf("� ������ �����ұ��? : ( 1 : +, 2 : -, 3 : *, 4 : / ) \n");
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
	printf("��� : %.3f\n", result);
}


//����
// �����ڵ� ���� ��Ʈ ��� �ٴϱ�!

 
/*
1.BMI ���� ���α׷� �����
��¿��� 
Ű(m)�� �Է�
������(kg)�� �Է����ּ��� 
BMI ���� : 24.5
��ü���Դϴ�. (0 ~ 18.5 ��ü��, ~ 23 ����ü��, ~ 25 ��ü��, ~ 30 ��, ~ ���Ѵ� ����)
*/

/*
���� ����
��¿���
�߰��� ���� �Է�
�⸻ ���� �Է�
�⼮���� �Է�
�������� �Է�
F�Դϴ�. (0~60 F, ~70 D, ~80 C, ~90 D, ~ 100 A)
*/

/*
Ȧ��¦�� ����
���ڸ� �Է����ּ���.  (14)
14�� ¦���Դϴ�.
*/