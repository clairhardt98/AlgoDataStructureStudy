#include "CursorList.h"

List::List(const int _n)
{
	count = 0;
	size = _n;
	n = new Node[size];
	free = new int[size];
	head = -1;
	cur = -1;
	last = -1;
	for (int i = 0; i <size; i++)
	{
		free[size - i - 1] = i;
	}
	freeIdx = size - 1;
}

List::~List()
{
	delete[] n;
}

bool List::Insert(const Student _st)
{
	if (count == size)return false;
	int idx = free[freeIdx];

	n[idx].st = _st;
	n[idx].next = -1;

	last = idx;
	//cur : �ֱ� ���� next�� -1�� ���
	if (head == -1)
	{
		cur = head = last;
	}
	else
	{
		//next�� -1�� ��带 ��� ���� ���� ����
		cur = n[cur].next = last;
	}
	freeIdx--;
	
	count++;

	return true;
	
}

bool List::Remove(int _no)
{
	//�ƹ��͵� ������ ����
	if (head == -1)return false;
	//head�� st.no�� _no��
	if (n[head].st.no == _no)
	{
		//free.push_back(head);
		free[++freeIdx] = head;
		
		int temp = head;
		head = n[head].next;
		n[temp].next = -1;
		count--;
		
		return true;
	}

	int ptr, del;
	ptr = del = head;

	while(1)
	{
		if (n[n[ptr].next].st.no == _no)//�� ���� ����� no�� ��ġ�ϸ�
		{
			//ptr�� �� ���� ���� �ű�(������ ���)
			if (n[ptr].next == cur)
				cur = ptr;
			ptr = n[ptr].next;
			//free �迭�� push
			//free.push_back(ptr);
			free[++freeIdx] = ptr;
			
			//ptr�� �ӽ� �����ϰ�
			int temp = ptr;
			//ptr�� ���� ����
			ptr = n[ptr].next;
			//�ӽ� �����ߴ� temp �̿�, n[temp].next�� -1��
			n[temp].next = -1;
			//�ӽ������س���(ptr)�� ���� n[temp].next�� ptr�� �ű�
			
			n[del].next = ptr;
			
			count--;
			
			return true;
		}
		del = ptr = n[ptr].next;
		if (ptr == -1)
			return false;
	}

}

void List::Clear()
{
	//�����Ҵ� ����
	delete[] n;
	delete[] free;
	//���� �ʱ�ȭ
	

	count = 0;
	n = new Node[size];
	free = new int[size];
	head = -1;
	cur = -1;
	last = -1;
	for (int i = 0; i < size; i++)
	{
		free[size - i - 1] = i;
	}
	freeIdx = size - 1;
}

void List::Print()
{
	int ptr = head;
	if (head == -1)return;
	while(1)
	{
		
		cout << n[ptr].st.name << " , " << n[ptr].st.no << endl;
		if (n[ptr].next == -1)break;
		ptr = n[ptr].next;
	}
}
