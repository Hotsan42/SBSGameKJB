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
	//자식이 둘다있는 경우에는 사용못함 참고
	void RemoveNode(Node<T>* node);
private:
	Node<T>* _root = nullptr;
};

template <typename T>
void BinaryTree<T>::AddData(T data)
{
	// 데이터가 없을때까지 왼쪽/오른쪽으로 이동, 없으면 newNode를 연결
	
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Right = nullptr;
	newNode->Left = nullptr;
	newNode->Parent = nullptr;

	if (_root == nullptr)
	{
		//데이터가 없는부분에 newNode 연결 후 종료
		_root = newNode;
		return;

		//early return 이라는 패턴
		//중괄호가 많아지면 코드 가독성 저하
	}

	if (this->GetNode(data) != nullptr)
	{
		printf("데이터가 같으면 추가 불가능!");
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

		//1. 대체할 노드찾기
		while (swapNode->Left != nullptr)
		{
			swapNode = swapNode->Left;
		}

		//2. 삭제할 노드를 대체할 노드로 값변경
		findNode->Data = swapNode->Data;

		//3. 대체할 노드를 삭제
	}
	else
	{
		RemoveNode;
	}
}

template <typename T>
void RemoveNode<T>(Node* node)
{
	//1. 둘다 없을때 삭제하는 방법
	// - 1) 삭제하려는 노드를 찾는다.
	// - 2) 부모와의 연을 끊은 다음에
	// - 3) 삭제하려는 노드를 삭제한다.

	Node<T>* findNode = this->GetNode(data);

	//없는걸 삭제하려 할수있으니
	if (findNode == nullptr)
	{
		cout << "없는 데이터입니다." << endl;
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

	//2. 자식이 한쪽만 있을때
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