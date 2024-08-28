#include <iostream>

using namespace std;



void main()
{
	//함수-2
	Function1();
	//매개변수

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