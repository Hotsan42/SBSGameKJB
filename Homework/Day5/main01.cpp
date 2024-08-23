#include <iostream>	

using namespace std;

void main()
{
	//컴퓨터가 겹치지 않는 3자리 랜덤 숫자를 고른다 (첫번째 자리 1이상)

	//세 자리를 각각 변수로 지정
	int comnum1;
	int comnum2;
	int comnum3;
	//난수를 위해 time 활성화
	srand(time(NULL));

	for (comnum1=0; comnum1 == 1 || comnum1 == 0;)			//0, 1이 아닐때까지 반복
	{
		comnum1 = rand() % 10;	//1~9까지 랜덤
	}
	for (comnum2=0; comnum2 == 0 || comnum2 == comnum1;)		//0이 아니고, 첫번째자리와 다를때까지 반복
	{
		comnum2 = rand() % 10;
	}
	for (comnum3=0; comnum3 == 0 || comnum3 == comnum1 || comnum3 == comnum2;) //마찬가지로 0아니고 안겹치게
	{
		comnum3 = rand() % 10;
	}

	// cout << comnum1 << comnum2 << comnum3 << endl;		//디버깅용

	//플레이어 입력


	//변수지정
	int playernum1;
	int playernum2;
	int playernum3;

	for (int i = 0; i < 9; i++) //총 9회 반복
	{
		cout << "첫번째 자리가 1 이상, 자릿수가 서로 겹치지 않게 세 자리 숫자를 입력해주세요. 기회는 총 9번입니다." << endl;
		cout << "첫번째 자리(백의 자리) : " << endl;
		cin >> playernum1;

		if (playernum1 < 1 || playernum1 > 9)
		{
			cout << "잘못된 입력입니다." << endl;		//잘못 입력받았을때 프로그램 종료
			return;
		}
		cout << "두번째 자리(십의 자리) : " << endl;
		cin >> playernum2;
		if (playernum2 == playernum1 || playernum2 < 0 || playernum2 > 9)
		{
			cout << "잘못된 입력입니다." << endl;
			return;
		}
		cout << "세번째 자리(일의 자리) : " << endl;
		cin >> playernum3;
		if (playernum3 == playernum2 || playernum3 == playernum1 || playernum3 < 0 || playernum3 > 9)
		{
			cout << "잘못된 입력입니다." << endl;
			return;
		}

		int ballcount = 0;		//볼과 스트라이크 개수
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
			cout << "쓰리 스트라이크! 게임 승리!!" << endl;
			return;		//스트라이크 세개일때 게임 종료
		}
		else
		{
			cout << "스트라이크:" << strikecount << "  볼:" << ballcount << endl;
		}
	}
	cout << "기회 전부 소진! 게임 오버!" << endl;	//게임 오버 문구
}