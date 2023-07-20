#include "MyTree.h"

int BST::insert(int _data)
{
	Node* newNode = new Node(_data);
	//�� Ʈ���� ��
	if (root == nullptr)
	{
		root = newNode;
		return 1;
	}
	//�� Ʈ���� �ƴ� ��
	Node* cur = root;
	while (1)
	{
		//���� ���� cur�� ������ ������
		if (newNode->data < cur->data)
		{
			if (cur->left == nullptr)
			{
				cur->left = newNode;
				return 1;
			}

			cur = cur->left;
		}
		else if (newNode->data > cur->data)
		{
			if (cur->right == nullptr)
			{
				cur->right = newNode;
				return 1;
			}

			cur = cur->right;
		}
		else
			return 0;
	}

}