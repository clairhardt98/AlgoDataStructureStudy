#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

class DoubleList
{
private:
	Node* head;
	Node* rear;
	int count;
public:
	DoubleList();
	~DoubleList() { Clear(); }
	void InsertFront(int data);
	void InsertRear(int data);
	void Delete(int no);
	void Print();
	void Clear();
};