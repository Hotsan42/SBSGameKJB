#include <iostream>

using namespace std;



void main()
{
	//�Լ�-2
	Function1();
	//�Ű�����

	Function2();
}

void Function1()
{

}


void Function2(int& b)
{
	cout << "Function2" << endl;
	cout << "b : " << b << endl;
	b = 30;
}