#include <iostream>
using namespace std;

void main()
{
	//[IF ��]
	//���� �߿��ϰ�, ���� ���� ���

	//if (boolean)
	//{
	//	boolean�� true�� ������ ����
	//}

	bool check = false;

	int year = 2024;
	if (check) 
	{
		printf("���ش� 2024�⵵ �Դϴ�.\n");
	}

	// == ���� != �ٸ�
	int hp = 10;
	if (0 < hp) 
	{
		printf("���� ������\n");
	}
	else
	{
		printf("���� ���!\n");
	}

	float result1 = 3 + 5;
	float result2 = 3 * 5;
	float result3 = 3 - 5;
	float result4 = 3 / 5;
	printf("result1 : %f\n", result1);
	printf("result2 : %f\n", result2);
	printf("result3 : %f\n", result3);
	printf("result4 : %f\n", result4);
}