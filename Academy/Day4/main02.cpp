#include <iostream>

using namespace std;

enum eRockPaperScissor
{
	RPS_Rock = 1,
	RPS_Paper = 2,
	RPS_Scissor = 0,
	RPS_End = 3
};




void main() 
{
	srand(time(NULL));
	cout << "����,����,�� �� �ϳ��� ����ּ���.\n����:0\n����:1\n��:2" << endl;
	int choice;
	cin >> choice;
	
	if ((rand() % 2) == 0)
	{
		if (choice == 1) 
		{

		}
		if (choice == 2)
		{

		}
		if (choice == 3)
		{

		}
	}
	else
	{
		if (choice == 1)
		{

		}
		if (choice == 2)
		{

		}
		if (choice == 3)
		{

		}
	}
}