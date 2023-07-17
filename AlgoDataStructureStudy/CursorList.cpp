#include "CursorList.h"

List::List(const int _n)
{
	count = 0;
	size = _n;
	n = new Node[_n];
	head = -1;
	last = -1;
	cur = -1;
	for (int i = _n - 1; i >= 0; i--)
	{
		free.push_back(i);
	}
}

List::~List()
{
	delete[] n;
}

void List::Insert(const Student& _st)
{
	if (count == size)return;
	int idx = free.back();
	last = idx;
	n[last].st = _st;
	n[last].next = -1;
	if (head == -1)
	{
		cur = head = last;
	}
	else
	{
		cur = n[cur].next = last;
	}
	free.pop_back();
	count++;
	
}

void List::Remove(int _no)
{
	if (head == -1)return;
	if (n[head].st.no == _no)
	{
		free.push_back(head);
		head = n[head].next;
		n[head].next = -1;
		count--;
		return;
	}
	int ptr, cur;
	ptr = cur = head;

	while(1)
	{
		if (n[ptr].st.no == _no)
		{
			free.push_back(ptr);
			ptr = n[ptr].next;
			n[ptr].next = -1;
			n[cur].next = ptr;
			count--;
			return;
		}
		cur = ptr = n[ptr].next;
		if (ptr == -1)
			return;
	}

}

void List::Clear()
{
}

void List::Print()
{
	int ptr = head;

	while(1)
	{
		
		cout << n[ptr].st.name << " , " << n[ptr].st.no << endl;
		if (n[ptr].next == -1)break;
		ptr = n[ptr].next;
	}
}
