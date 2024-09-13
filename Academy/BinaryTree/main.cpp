#include <iostream>
#include "BinaryTree.h"
using namespace std;

template <typename T>

struct Student
{
	int Math;
	int Korea;
public:
	bool operator<(Student student)
	{
		if (this->Math + this->Korea)
	}
};

template <typename T>
void main()
{
	srand(time(NULL));

	BinaryTree<T> bt;

	for (int i = 0; i < 1000; i++)
	{
		bt.AddData(rand());
	}

	bt.AddData(-1);

	Node<T>* a = bt.GetNode(-1);
	cout << "a : " << a << endl;
}
