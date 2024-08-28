#include <iostream>

using namespace std;

void main()
{
	//

	int a = 3;

	cout << "a의 주소값 : " << &a << endl;
	cout << "a의 값 : " << a << endl;

	cout << "a의 주소값에 위치한 값 : " << (*(&a)) << endl;

	int arr[3] = {2,3,4};

	int* ptr2 = arr;
	cout << ptr2 << endl;
	
}