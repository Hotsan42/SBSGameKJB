#include <iostream>

#define DEBUG

using namespace std;

//���� ���� --------------------------------------
int playerBingo[25] = {};
int comBingo[25] = {};
int calledNumber;
int turn = 1;
int playerBingocount;
int comBingocount;

void MakeBoard()
{
	for (int i = 0; i < 25; i++)
	{
		//���� ������ �ʱ�ȭ
		playerBingo[i] = i + 1;
		comBingo[i] = i + 1;
	}

#ifdef DEBUG
	for (int i = 0; i < 25; i++)
	{
		cout << playerBingo << endl;
	}
	for (int i = 0; i < 25; i++)
	{
		cout << comBingo << endl;
	}
#endif // DEBUG
}

void ShuffleBoard()
{
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		i = rand() % 25;
	}

#ifdef DEBUG
	for (int i = 0; i < 25; i++)
	{
		cout << playerBingo << endl;
	}
	for (int i = 0; i < 25; i++)
	{
		cout << comBingo << endl;
	}
#endif // DEBUG
}


void PrintBoard()
{

}

void BingoNumber()
{
	cout << turn <<"��° ��!" << endl;

	if (turn % 2 == 1)
	{
		cout << "���� ���ڸ� �Է����ּ���." << endl;

		int input;
		cin >> input;

		calledNumber = input;
	}
	else
	{
		calledNumber = rand() % 25 + 1;
	}
	cout << "�Ҹ� ���� : " << calledNumber << endl;
}
/*
void MarkBingoNumber()
{
	for (int i = 0; i < 25; i++)
	{
		if (playerBingo[i] == calledNumber)
		{
			playerBingo[i] = -1;
		}
	}

	if (playerBingo[i * 5 + j])
	{

	}
}
*/
void NextTurn()
{
	cout << "�� ����!" << endl;
	turn++;
}

void CheckBingo()
{
#ifdef DEBUG
	cout << "������ üũ!" << endl; 
#endif // DEBUG

	//������ �� üũ�ؼ� -1����
	for (int i = 0; i < 5; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < 5; j++)
		{
			if (playerBingo[i + 5 + j] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine = -1)
		{

		}
	}
}

void main()
{
	// 1-25������ ����
	//playerBingo, comBingo

	// 1. �÷��̾� �����ǰ� ��ǻ�� ������ ����
	MakeBoard();
	// 2. ������ ����
	ShuffleBoard();
	// 2-1. ������ ���
	PrintBoard();

	while (true)
	{
		// 3. �÷��̾� ���� �Է�
		BingoNumber();
		// 4. �����ǿ��� �ش� ���ڸ� -1�� �ٲ� (��½� -1�� X�� ���)
		//MarkBingoNumber();
		//�� ����
		NextTurn();


		//����� üũ
		CheckBingo();
	}
	// 5. �� �� �Ѹ��̶� ���� 3�� �ϼ��� (������, ������, �밢����)
	// 6. �¸� ����, ��������
}