#include <iostream>

using namespace std;

void main()
{
	
	
	//for�� + �迭

	int arr[10] = {};
	
	

	//�迭�� �ʱ�ȭ
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	
	
	//���
	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	

	//arr�� ��� ���� ����
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		//�ε����� �ΰ� ��� swap
		int index1 = rand() % 10;
		int index2 = rand() % 10;

		//arr[index1] �� arr[index2]�� ������ swap
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}



//���� 2��
//1�� ���� : �ζǹ�ȣ ������
//	��Ʈ : �ζ� �� lotto[45] �迭�� ����
//			�̰Ÿ� ������ �Ŀ�, 7���� �̱�
// 
//2�� ���� : ���������� �ϳ�����

//�ϸ�������-���α׷��� ��ƴٰ� ��������
//���������� Ǯ�� Ÿ�Ӿ��� �������� �ڵ�ܿ��-���� �ѹ���ġ�� �������, 10�г��δ�ĥ���ְ�