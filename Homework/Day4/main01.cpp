// �ζǹ�ȣ ������
//	��Ʈ : �ζ� �� lotto[45] �迭�� ����
//			�̰Ÿ� ������ �Ŀ�, 7���� �̱�

#include <iostream>

using namespace std;

void main()
{
	int arr[45] = {};

	for (int i = 0; i < 45; i++)
	{
		arr[i] = i+1;
	}


	// ����׿�
	//  for (int i = 0; i < 45; i++)
	//  {
	//		printf("arr[%d] = %d\n", i, arr[i]);
	//  }


	//arr�� ��� ���� ����
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		//�ε����� �ΰ� ��� swap
		int index1 = rand() % 45;
		int index2 = rand() % 45;

		//swap
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	//���
	printf("�ζ� ��ȣ�� ");
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("�Դϴ�.");
}