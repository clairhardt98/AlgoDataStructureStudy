#pragma once
/*
���� �˻� Ʈ��
�� ����� �ڽ��� 2�� ����
�������� ���� ������ ������ �׻� ũ��

���� ��ȸ
���� �ڽ� �� �湮
�θ� �湮
������ �ڽ� �湮
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
