#include "MyTree.h"

int BST::insert(int _data)
{
	Node* newNode = new Node(_data);
	//빈 트리일 때
	if (root == nullptr)
	{
		root = newNode;
		return 1;
	}
	//빈 트리가 아닐 때
	Node* cur = root;
	while (1)
	{
		//들어온 값이 cur의 값보다 작으면
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