// 로또번호 생성기
//	힌트 : 로또 통 lotto[45] 배열을 선언
//			이거를 섞어준 후에, 7개를 뽑기

#include <iostream>

using namespace std;

void main()
{
	int arr[45] = {};

	for (int i = 0; i < 45; i++)
	{
		arr[i] = i+1;
	}


	// 디버그용
	//  for (int i = 0; i < 45; i++)
	//  {
	//		printf("arr[%d] = %d\n", i, arr[i]);
	//  }


	//arr에 담긴 변수 섞기
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		//인덱스를 두개 잡고 swap
		int index1 = rand() % 45;
		int index2 = rand() % 45;

		//swap
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	//출력
	printf("로또 번호는 ");
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("입니다.");
}