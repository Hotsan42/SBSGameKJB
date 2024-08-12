#include <iostream>
using namespace std;

void main()
{
	//[IF 문]
	//제일 중요하고, 가장 많이 사용

	//if (boolean)
	//{
	//	boolean이 true면 실행할 내용
	//}

	bool check = false;

	int year = 2024;
	if (check) 
	{
		printf("올해는 2024년도 입니다.\n");
	}

	// == 같음 != 다름
	int hp = 10;
	if (0 < hp) 
	{
		printf("유닛 생존중\n");
	}
	else
	{
		printf("유닛 사망!\n");
	}

	float result1 = 3 + 5;
	float result2 = 3 * 5;
	float result3 = 3 - 5;
	float result4 = 3 / 5;
	printf("result1 : %f\n", result1);
	printf("result2 : %f\n", result2);
	printf("result3 : %f\n", result3);
	printf("result4 : %f\n", result4);
}