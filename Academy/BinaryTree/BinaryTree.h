#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	Node<T>* Parent;
	Node<T>* Left;
	Node<T>* Right;
	T Data;
};

template <typename T>
class BinaryTree
{
public:
	void AddData(T data);
	void RemoveData(T data);
	Node<T>* GetNode(T data);
private:
	//�ڽ��� �Ѵ��ִ� ��쿡�� ������ ����
	void RemoveNode(Node<T>* node);
private:
	Node<T>* _root = nullptr;
};

template <typename T>
void BinaryTree<T>::AddData(T data)
{
	// �����Ͱ� ���������� ����/���������� �̵�, ������ newNode�� ����
	
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Right = nullptr;
	newNode->Left = nullptr;
	newNode->Parent = nullptr;

	if (_root == nullptr)
	{
		//�����Ͱ� ���ºκп� newNode ���� �� ����
		_root = newNode;
		return;

		//early return �̶�� ����
		//�߰�ȣ�� �������� �ڵ� ������ ����
	}

	if (this->GetNode(data) != nullptr)
	{
		printf("�����Ͱ� ������ �߰� �Ұ���!");
		return;
	}

	Node<T>* current = _root;
	while (true)
	{
		if (current->Data < data)
		{
			if (current->Right == nullptr)
			{

				current = current->Right;
			}
		}
		else if (data < current->Data)
		{
			if (current->Left == nullptr)
			{
				
				current = current->Left;
			}
		}
	}
}

template <typename T>
void BinaryTree<T>::RemoveData(T data)
{
	
	if()
	{
		Node<T>* swapNode = findNode->Right;

		//1. ��ü�� ���ã��
		while (swapNode->Left != nullptr)
		{
			swapNode = swapNode->Left;
		}

		//2. ������ ��带 ��ü�� ���� ������
		findNode->Data = swapNode->Data;

		//3. ��ü�� ��带 ����
	}
	else
	{
		RemoveNode;
	}
}

template <typename T>
void RemoveNode<T>(Node* node)
{
	//1. �Ѵ� ������ �����ϴ� ���
	// - 1) �����Ϸ��� ��带 ã�´�.
	// - 2) �θ���� ���� ���� ������
	// - 3) �����Ϸ��� ��带 �����Ѵ�.

	Node<T>* findNode = this->GetNode(data);

	//���°� �����Ϸ� �Ҽ�������
	if (findNode == nullptr)
	{
		cout << "���� �������Դϴ�." << endl;
		return;
	}

	if (findNode->Left == nullptr && findNode->Right == nullptr)
	{
		if (findNode->Parent->Left == findNode)
		{
			findNode->Parent->Left = nullptr;
		}
		if (findNode->Parent->Right == findNode)
		{
			findNode->Parent->Right = nullptr;
		}

		delete findNode;
		findNode = nullptr;
	}

	//2. �ڽ��� ���ʸ� ������
	else if (findNode->Left == nullptr && findNode->Right != nullptr)
	{
		if (findNode->Parent->Left == findNode)
		{
			findNode->Parent->Left = findNode->Right;
		}
		if (findNode->Parent->Right == findNode)
		{
			findNode->Parent->Right = findNode->Right;
		}
		delete findNode;
		findNode = nullptr;
	}
	else if (findNode->Left != nullptr && findNode->Right == nullptr)
	{
		if (findNode->Parent->Left == findNode)
		{
			findNode->Parent->Left = findNode->Left;
		}
		if (findNode->Parent->Right == findNode)
		{
			findNode->Parent->Right = findNode->Left;
		}
	}
}

template <typename T>
Node<T>* BinaryTree<T>::GetNode(T data)
{
	Node<T>* current = _root;
	while (current != nullptr && current->Data != data)
	{
		if (current->Data < data)
		{
			current = current->Right;
		}
		else if (data < current->Data)
		{
			current = current->Left;
		}
	}
	return current;
}