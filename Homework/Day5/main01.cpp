#include <iostream>	

using namespace std;

void main()
{
	//��ǻ�Ͱ� ��ġ�� �ʴ� 3�ڸ� ���� ���ڸ� ���� (ù��° �ڸ� 1�̻�)

	//�� �ڸ��� ���� ������ ����
	int comnum1;
	int comnum2;
	int comnum3;
	//������ ���� time Ȱ��ȭ
	srand(time(NULL));

	for (comnum1=0; comnum1 == 1 || comnum1 == 0;)			//0, 1�� �ƴҶ����� �ݺ�
	{
		comnum1 = rand() % 10;	//1~9���� ����
	}
	for (comnum2=0; comnum2 == 0 || comnum2 == comnum1;)		//0�� �ƴϰ�, ù��°�ڸ��� �ٸ������� �ݺ�
	{
		comnum2 = rand() % 10;
	}
	for (comnum3=0; comnum3 == 0 || comnum3 == comnum1 || comnum3 == comnum2;) //���������� 0�ƴϰ� �Ȱ�ġ��
	{
		comnum3 = rand() % 10;
	}

	// cout << comnum1 << comnum2 << comnum3 << endl;		//������

	//�÷��̾� �Է�


	//��������
	int playernum1;
	int playernum2;
	int playernum3;

	for (int i = 0; i < 9; i++) //�� 9ȸ �ݺ�
	{
		cout << "ù��° �ڸ��� 1 �̻�, �ڸ����� ���� ��ġ�� �ʰ� �� �ڸ� ���ڸ� �Է����ּ���. ��ȸ�� �� 9���Դϴ�." << endl;
		cout << "ù��° �ڸ�(���� �ڸ�) : " << endl;
		cin >> playernum1;

		if (playernum1 < 1 || playernum1 > 9)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;		//�߸� �Է¹޾����� ���α׷� ����
			return;
		}
		cout << "�ι�° �ڸ�(���� �ڸ�) : " << endl;
		cin >> playernum2;
		if (playernum2 == playernum1 || playernum2 < 0 || playernum2 > 9)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			return;
		}
		cout << "����° �ڸ�(���� �ڸ�) : " << endl;
		cin >> playernum3;
		if (playernum3 == playernum2 || playernum3 == playernum1 || playernum3 < 0 || playernum3 > 9)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			return;
		}

		int ballcount = 0;		//���� ��Ʈ����ũ ����
		int strikecount = 0;

		if (playernum1 == comnum1)
		{
			strikecount++;
		}
		if (playernum2 == comnum2)
		{
			strikecount++;
		}
		if (playernum3 == comnum3)
		{
			strikecount++;
		}
		if (playernum1 == comnum2 || playernum1 == comnum3)
		{
			ballcount++;
		}
		if (playernum2 == comnum1 || playernum2 == comnum3)
		{
			ballcount++;
		}
		if (playernum3 == comnum2 || playernum3 == comnum1)
		{
			ballcount++;
		}
		if (strikecount == 3)
		{
			cout << "���� ��Ʈ����ũ! ���� �¸�!!" << endl;
			return;		//��Ʈ����ũ �����϶� ���� ����
		}
		else
		{
			cout << "��Ʈ����ũ:" << strikecount << "  ��:" << ballcount << endl;
		}
	}
	cout << "��ȸ ���� ����! ���� ����!" << endl;	//���� ���� ����
}