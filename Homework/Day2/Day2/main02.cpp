/*
학점 계산기
출력에서
중간평가 점수 입력
기말 점수 입력
출석점수 입력
과제점수 입력
F입니다. (0~60 F, ~70 D, ~80 C, ~90 D, ~ 100 A)
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
	
	printf("중간평가 점수 입력 : ");
	cin >> midscore;
	printf("기말평가 점수 입력 : ");
	cin >> finscore;
	printf("출석 점수 입력 : ");
	cin >> goscore;
	printf("과제 점수 입력 : ");
	cin >> hwscore;

	totalscore = midscore + finscore + goscore + hwscore;

	if (totalscore < 60 && totalscore >= 0)
	{
		printf("F입니다.");
	}
	else if (totalscore >= 60 && totalscore < 70)
	{
		printf("D입니다.");
	}
	else if (totalscore >= 70 && totalscore < 80)
	{
		printf("C입니다.");
	}
	else if (totalscore >= 80 && totalscore < 90)
	{
		printf("B입니다.");
	}
	else if (totalscore >= 90 && totalscore <= 100)
	{
		printf("A입니다.");
	}
	else if (totalscore < 0 || totalscore >100)
	{
		printf("잘못 입력하셨습니다.");
	}
}