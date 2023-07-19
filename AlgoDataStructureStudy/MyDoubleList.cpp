#include "MyDoubleList.h"

DoubleList::DoubleList()
{
	head = nullptr;
	rear = nullptr;
	count = 0;
}

void DoubleList::InsertFront(int _data)
{
	Node* node = new Node;
	node->data = _data;

	//처음 입력
	if (head == nullptr)
	{
		head = node;
		node->next = nullptr;
		node->prev = nullptr;
		rear = node;
	}
	else
	{
		node->next = head;
		node->next->prev = node;
		node->prev = nullptr;
		head = node;
	}
	
	count++;
}

void DoubleList::InsertRear(int _data)
{
	Node* node = new Node;
	node->data = _data;

	if (head == nullptr)
	{
		head = node;
		node->next = nullptr;
		node->prev = nullptr;
		rear = node;
	}
	else
	{
		rear->next = node;
		node->prev = rear;
		node->next = nullptr;
		rear = node;
	}
	count++;

}

void DoubleList::Delete(int no)
{
	if (head == nullptr)return;
	Node* ptr = head;
	//head 지울 때
	if (ptr->data == no)
	{
		Node* temp = head;
		head = ptr->next;
		delete temp;
		count--;

		if (head == nullptr)
			return;

		else
			head->prev = nullptr;
		return;
	}

	//next의 no가 no인 상황을 만들기
	while (1)
	{
		if (ptr->next == nullptr)return;
		if (ptr->next->data == no)break;
		else ptr = ptr->next;
	}
	//rear를 지울 경우
	if (ptr->next == rear)
	{
		ptr->next = nullptr;
		delete rear;
		count--;
		rear = ptr;
		return;
	}
	ptr->next->next->prev = ptr;
	Node* temp = ptr->next;
	ptr->next = ptr->next->next;
	delete temp;
}

void DoubleList::Print()
{
	Node* ptr = head;
	while (ptr != nullptr)
	{
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout <<'\n';
}

void DoubleList::Clear()
{
	Node* ptr = head;
	while (ptr != nullptr)
	{
		Node* temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
	head = rear = nullptr;
}
