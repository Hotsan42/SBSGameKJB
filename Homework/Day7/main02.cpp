#include <iostream>

using namespace std;

int myBingo[25] = {};
int comBingo[25] = {};
int calledNumber = 0;
int turn = 0;
int myBingCount = 0;
int comBingCount = 0;
bool isGamePlaying = true;

void MakeBoard();
void ShuffleBoard();
void PrintBoard();
void CallBingoNumber();
void MarkBingoNumber();
void GoToNextTurn();
void checkBingoCount();

void main()
{
	// ����

	// ������ �����ڵ�
	// 1. �� �����ǰ� ��ǻ�� ������ ����
	// myBingo[25] = {1 ~ 25} , comBingo[25] = {1 ~ 25}
	// 2. ������ ���� (��, ��ǻ��)
	// 3. �������� ��� (��, ��ǻ��)
	// [����]
	// 4. ���� ���ڸ� �ϳ� �θ���.
	// 5. �� ���ڸ� �� �����ǰ�, ��ǻ�� �����ǿ��� ���ڸ� -1�� ��ü�Ѵ�.
	// (-1�� ������� �츮���� ���� ���Ѱ���.)
	// 6. ��ǻ�Ͱ� ���ڸ� �ϳ� �θ���.
	// 7. �� ���ڸ� �� �����ǰ�, ��ǻ�� �����ǿ��� ���ڸ� -1�� ��ü�Ѵ�.
	// (-1�� ������� �츮���� ���� ���Ѱ���.)
	// 8. 4������ ���ư��� ������ �ݺ��Ѵ�.

	srand(time(NULL));
	// 1. �� �����ǰ� ��ǻ�� ������ ����
	MakeBoard();
	// 2. ������ ����. (��, ��ǻ��)
	ShuffleBoard();
	while (true)
	{
		// 3. �������� ��� (��, ��ǻ��)
		PrintBoard();
		// 4. ���� ���ڸ� �ϳ� �θ���.
		CallBingoNumber();
		// 5. �� ���ڸ� �� �����ǰ�, ��ǻ�� �����ǿ��� ���ڸ� -1�� ��ü�Ѵ�.
		MarkBingoNumber();
		// 6. �� ����
		GoToNextTurn();

		// 7. ����ī��Ʈ üũ
		checkBingoCount();
		// 8. �� ����ī��Ʈ�� 3�̻��̸� ���� �¸�, ��������

		if (myBingCount == 3)
		{
			cout << "���� �¸�!" << endl;
			cout << "��������" << endl;
			exit(0);
		}
		// 9. ���� ����ī��Ʈ�� 3�̻��̸� ��ǻ�Ͱ� �¸�, ��������

		if (comBingCount == 3)
		{
			cout << "���� �¸�!" << endl;
			cout << "��������" << endl;
			exit(0);
		}
	}
}

// 1. �� �����ǰ� ��ǻ�� ������ ����
void MakeBoard()
{
	cout << "�� �����ǰ� ��ǻ�� ������ ����" << endl;

	// �����ڵ�
	// myBingo, comBingo�� for�� �Ἥ 1-25���� �ʱ�ȭ

	// �� ������ �ʱ�ȭ
	for (int i = 0; i < 25; i++)
	{
		myBingo[i] = i + 1;
	}

	// ��ǻ�� ������ �ʱ�ȭ
	for (int i = 0; i < 25; i++)
	{
		comBingo[i] = i + 1;
	}
}

// 2. ������ ����. (��, ��ǻ��)
void ShuffleBoard()
{
	cout << "������ ����.(��, ��ǻ��)" << endl;

	for (int i = 0; i < 10000; i++)
	{

	}
}

// 3. �������� ��� (��, ��ǻ��)
void PrintBoard()
{
	cout << "�������� ��� (��, ��ǻ��)" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//[i,j]
			// i => ������
			// j => ������
			// �������ε��� * ���α��� + �������ε���
			if (myBingo[i * 5 + j] == -1)
			{
				cout << "xx\t";
			}
			else
			{
				cout << myBingo[i * 5 + j] << "\t";
			}
		}
		cout << endl;
	}

	cout << "��� ������ " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << comBingo[i * 5 + j] << "\t";
		}
		cout << endl;
	}
}

// 4. ���� ���ڸ� �ϳ� �θ���.
void CallBingoNumber()
{
	cout << "���� ���ڸ� �ϳ� �θ���." << endl;

	cout << "[" << turn << "] ��° ��!" << endl;

	if (turn % 2 == 1)
	{
		cout << "���� ���ڸ� �Է����ּ���." << endl;

		int input;
		cin >> input;

		calledNumber = input;
	}
	else
	{
		// ��밡 ���ںθ��� ���� �����ڵ�
		// �ϴ� �����ϰ�
		calledNumber = rand() % 25 + 1;
	}

	cout << "�Ҹ� ���� : " << calledNumber << endl;
}

// 5. �� ���ڸ� �� �����ǰ�, ��ǻ�� �����ǿ��� ���ڸ� -1�� ��ü�Ѵ�.
void MarkBingoNumber()
{
	cout << "�� ���ڸ� �� �����ǰ�, ��ǻ�� �����ǿ��� ���ڸ� -1�� ��ü�Ѵ�." << endl;

	// �����ڵ�
	// �� �����ǿ��� calledNumber�� �ִ��� üũ
	// ������ -1�� ����

	// �� �����ǿ��� calledNumber�� �ִ��� ������ üũ�� �ϳ��� ���ϸ� ��.

	for (int i = 0; i < 25; i++)
	{

	}
}

// 6. �� ����
void GoToNextTurn()
{
	cout << "�� ����" << endl;
}

void checkBingoCount()
{
	cout << "������ üũ" << endl;

	// ������ üũ
	// ������ üũ
	// �밢�� / ����
	// �밢�� \ ����
	myBingCount = 0;

	// �� ������ üũ
	// -1�� ��ũ�Ȱ�.
	// �������� �� üũ������, -1����.

	// ������ üũ
	for (int i = 0; i < 5; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < 5; j++)
		{
			if (myBingo[i * 5 + j] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			myBingCount++;
		}
	}

	// ������ üũ
	for (int i = 0; i < 5; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < 5; j++)
		{
			if (myBingo[j * 5 + i] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			myBingCount++;
		}
	}

	{
		bool isBingoLine = true;
		for (int i = 0; i < 5; i++)
		{
			if (myBingo[i * 5 + i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			myBingCount++;
		}
	}

	cout << "�� ����ī��Ʈ : " << myBingCount << endl;
}