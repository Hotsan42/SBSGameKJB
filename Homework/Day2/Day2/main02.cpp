/*
���� ����
��¿���
�߰��� ���� �Է�
�⸻ ���� �Է�
�⼮���� �Է�
�������� �Է�
F�Դϴ�. (0~60 F, ~70 D, ~80 C, ~90 D, ~ 100 A)
*/

#include <iostream>

using namespace std;

void main()
{
	float midscore;
	float finscore;
	float goscore;
	float hwscore;
	float totalscore;
	
	printf("�߰��� ���� �Է� : ");
	cin >> midscore;
	printf("�⸻�� ���� �Է� : ");
	cin >> finscore;
	printf("�⼮ ���� �Է� : ");
	cin >> goscore;
	printf("���� ���� �Է� : ");
	cin >> hwscore;

	totalscore = midscore + finscore + goscore + hwscore;

	if (totalscore < 60 && totalscore >= 0)
	{
		printf("F�Դϴ�.");
	}
	else if (totalscore >= 60 && totalscore < 70)
	{
		printf("D�Դϴ�.");
	}
	else if (totalscore >= 70 && totalscore < 80)
	{
		printf("C�Դϴ�.");
	}
	else if (totalscore >= 80 && totalscore < 90)
	{
		printf("B�Դϴ�.");
	}
	else if (totalscore >= 90 && totalscore <= 100)
	{
		printf("A�Դϴ�.");
	}
	else if (totalscore < 0 || totalscore >100)
	{
		printf("�߸� �Է��ϼ̽��ϴ�.");
	}
}