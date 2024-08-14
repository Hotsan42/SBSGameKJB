/*
홀수짝수 계산기
숫자를 입력해주세요.  (14)
14는 짝수입니다.
*/

#include <iostream>

using namespace std;

void main() 
{
	int num;
	int leftnum;
	printf("숫자를 입력해주세요 : ");
	cin >> num;
	leftnum = num % 2;
	if (leftnum == 0)
	{
		printf("짝수입니다.");
	}
	else 
	{
		printf("홀수입니다.");
	}
}