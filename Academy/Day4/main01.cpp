#include <iostream>

using namespace std;

int main() 
{
	//[����] �÷��̾�� = 1
	//[���] �÷��̾�� 1����
	//[��] ���� ����, ��� ���� (1:�ο��, 2:��������)
	//[��] choice
	//[if] choice = 1
	//		�������/1+�÷��̾��*2 Ȯ���� ���
	//		->����� �׳� �¸��� ������
	//[if] choice = 2
	//		������ ����Ȯ�� ���, ����ϸ�׳�

	int playerlvl = 1;

	//��������
	srand(time(NULL));

	playerlvl = rand() % 3 + 1;



	cout << "�÷��̾�� " << playerlvl << "���� �Դϴ�." << endl;
	cout << "������ �����߽��ϴ�.\n1���� ����� �����ƽ��ϴ�! (1:�ο��. 2:��������.)" << endl;
	int choice = 0;
	cin >> choice;
	bool alive = true;
	
	if (alive && choice == 1)
	{
		cout << "���� ����!" << endl;
		int losechance = rand() % (playerlvl * 2 + 1);
		if (losechance == 1)
		{
			cout << "�������� �й��� ����߽��ϴ�.\n���� ����!" << endl;
			alive = false;
		}
		else 
		{
			playerlvl += (rand() % 2) + 1;
			cout << "�������� �¸��߽��ϴ�. ���� ����:" << playerlvl << endl;
		}
	}
	if (alive && choice == 2)
	{
		cout << "���� �õ�!" << endl;
		int random = rand() % 100;
		if(random > 10)
		{
			playerlvl++;
			cout << "���� ����! ������ 1 �ö����ϴ�. ���� ����:" << playerlvl << endl;
		}
		else
		{
			cout << "������ ����߽��ϴ�.\n���� ����!" << endl;
			alive = false;
		}
	}
}