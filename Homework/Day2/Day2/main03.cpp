/*
Ȧ��¦�� ����
���ڸ� �Է����ּ���.  (14)
14�� ¦���Դϴ�.
*/

#include <iostream>

using namespace std;

void main() 
{
	int num;
	int leftnum;
	printf("���ڸ� �Է����ּ��� : ");
	cin >> num;
	leftnum = num % 2;
	if (leftnum == 0)
	{
		printf("¦���Դϴ�.");
	}
	else 
	{
		printf("Ȧ���Դϴ�.");
	}
}