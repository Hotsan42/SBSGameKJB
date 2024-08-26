#include <iostream>

#define DEBUG

using namespace std;

//변수 정의 --------------------------------------
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
		//양측 빙고판 초기화
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
	cout << turn <<"번째 턴!" << endl;

	if (turn % 2 == 1)
	{
		cout << "빙고 숫자를 입력해주세요." << endl;

		int input;
		cin >> input;

		calledNumber = input;
	}
	else
	{
		calledNumber = rand() % 25 + 1;
	}
	cout << "불린 숫자 : " << calledNumber << endl;
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
	cout << "턴 변경!" << endl;
	turn++;
}

void CheckBingo()
{
#ifdef DEBUG
	cout << "빙고갯수 체크!" << endl; 
#endif // DEBUG

	//가로줄 쭉 체크해서 -1인지
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
	// 1-25까지의 숫자
	//playerBingo, comBingo

	// 1. 플레이어 빙고판과 컴퓨터 빙고판 정의
	MakeBoard();
	// 2. 빙고판 셔플
	ShuffleBoard();
	// 2-1. 빙고판 출력
	PrintBoard();

	while (true)
	{
		// 3. 플레이어 숫자 입력
		BingoNumber();
		// 4. 빙고판에서 해당 숫자를 -1로 바꿈 (출력시 -1은 X로 출력)
		//MarkBingoNumber();
		//턴 변경
		NextTurn();


		//빙고수 체크
		CheckBingo();
	}
	// 5. 둘 중 한명이라도 빙고 3개 완성시 (가로줄, 세로줄, 대각선줄)
	// 6. 승리 선언, 게임종료
}