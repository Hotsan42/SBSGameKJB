#include <iostream>

using namespace std;

void main()
{
	int year = 0;
	printf("�¾ �⵵�� �Է����ּ��� : ");
	scanf_s("%d", &year);


	//���ڿ� �Է��� ���� Ư����!
	//scanf_s("%s", ������, (int)sizeof(������));
	char name[100] = "";
	printf("�̸��� �Է����ּ��� : ");
	scanf_s("%s", name, (int)sizeof(name));

	printf("�� �̸��� %s�̰�, ���� %d��� �Դϴ�.", name, year);
}