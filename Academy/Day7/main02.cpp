#include <iostream>

using namespace std;

void main()
{
	//

	int a = 3;

	cout << "a�� �ּҰ� : " << &a << endl;
	cout << "a�� �� : " << a << endl;

	cout << "a�� �ּҰ��� ��ġ�� �� : " << (*(&a)) << endl;

	int arr[3] = {2,3,4};

	int* ptr2 = arr;
	cout << ptr2 << endl;
	
}