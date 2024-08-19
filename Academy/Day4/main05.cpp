#include <iostream>

using namespace std;

void main()
{
	
	
	//for문 + 배열

	int arr[10] = {};
	
	

	//배열의 초기화
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	
	
	//출력
	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	

	//arr에 담긴 변수 섞기
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		//인덱스를 두개 잡고 swap
		int index1 = rand() % 10;
		int index2 = rand() % 10;

		//arr[index1] 과 arr[index2]의 변수를 swap
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}



//숙제 2개
//1번 숙제 : 로또번호 생성기
//	힌트 : 로또 통 lotto[45] 배열을 선언
//			이거를 섞어준 후에, 7개를 뽑기
// 
//2번 숙제 : 가위바위보 하나빼기

//하면좋은거-프로그래밍 어렵다고 느껴진다
//가위바위보 풀이 타임어택 될정도로 코드외우기-수업 한번놓치면 못따라옴, 10분내로다칠수있게