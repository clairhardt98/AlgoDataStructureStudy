#pragma once
/*
이진 검색 트리
각 노드의 자식은 2명 이하
오른쪽의 값은 왼쪽의 값보다 항상 크다

중위 순회
왼쪽 자식 쭉 방문
부모 방문
오른쪽 자식 방문
*/

class Node
{
public:
	int data;
	Node* right;
	Node* left;
	Node(int _data)
	{
		data = _data;
		left = right = nullptr;
	}
};


class BST
{
private:
	
	Node* root;
public:
	BST() { root = nullptr; };
	~BST();
	int insert(int _data);
	int remove(int _data);
	
};
