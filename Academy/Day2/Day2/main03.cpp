#include <iostream>

using namespace std;

void main()
{
	int year = 0;
	printf("태어난 년도를 입력해주세요 : ");
	scanf_s("%d", &year);


	//문자열 입력은 조금 특이함!
	//scanf_s("%s", 변수명, (int)sizeof(변수명));
	char name[100] = "";
	printf("이름을 입력해주세요 : ");
	scanf_s("%s", name, (int)sizeof(name));

	printf("제 이름은 %s이고, 저는 %d년생 입니다.", name, year);
}