#include <iostream>

using namespace std;

int main() 
{
	//[선언] 플레이어레벨 = 1
	//[출력] 플레이어는 1레벨
	//[출] 던전 입장, 고블린 조우 (1:싸운다, 2:도망간다)
	//[입] choice
	//[if] choice = 1
	//		고블린레벨/1+플레이어레벨*2 확률로 사망
	//		->사망시 겜끝 승리시 레벨업
	//[if] choice = 2
	//		도망시 일정확률 사망, 사망하면겜끝

	int playerlvl = 1;

	//랜덤레벨
	srand(time(NULL));

	playerlvl = rand() % 3 + 1;



	cout << "플레이어는 " << playerlvl << "레벨 입니다." << endl;
	cout << "던전에 입장했습니다.\n1레벨 고블린과 마주쳤습니다! (1:싸운다. 2:도망간다.)" << endl;
	int choice = 0;
	cin >> choice;
	bool alive = true;
	
	if (alive && choice == 1)
	{
		cout << "전투 시작!" << endl;
		int losechance = rand() % (playerlvl * 2 + 1);
		if (losechance == 1)
		{
			cout << "전투에서 패배해 사망했습니다.\n게임 오버!" << endl;
			alive = false;
		}
		else 
		{
			playerlvl += (rand() % 2) + 1;
			cout << "전투에서 승리했습니다. 현재 레벨:" << playerlvl << endl;
		}
	}
	if (alive && choice == 2)
	{
		cout << "도주 시도!" << endl;
		int random = rand() % 100;
		if(random > 10)
		{
			playerlvl++;
			cout << "도주 성공! 레벨이 1 올랐습니다. 현재 레벨:" << playerlvl << endl;
		}
		else
		{
			cout << "붙잡혀 사망했습니다.\n게임 오버!" << endl;
			alive = false;
		}
	}
}