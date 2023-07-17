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
	//cur : 넣기 직전 next가 -1인 노드
	if (head == -1)
	{
		cur = head = last;
	}
	else
	{
		//next가 -1인 노드를 방금 넣은 노드로 갱신
		cur = n[cur].next = last;
	}
	freeIdx--;
	
	count++;

	return true;
	
}

bool List::Remove(int _no)
{
	//아무것도 없으면 리턴
	if (head == -1)return false;
	//head의 st.no가 _no면
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
		if (n[n[ptr].next].st.no == _no)//그 다음 노드의 no가 일치하면
		{
			//ptr만 그 다음 노드로 옮김(없어질 노드)
			if (n[ptr].next == cur)
				cur = ptr;
			ptr = n[ptr].next;
			//free 배열에 push
			//free.push_back(ptr);
			free[++freeIdx] = ptr;
			
			//ptr을 임시 저장하고
			int temp = ptr;
			//ptr을 다음 노드로
			ptr = n[ptr].next;
			//임시 저장했던 temp 이용, n[temp].next를 -1로
			n[temp].next = -1;
			//임시저장해놓은(ptr)에 대해 n[temp].next로 ptr을 옮김
			
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
	//동적할당 해제
	delete[] n;
	delete[] free;
	//벡터 초기화
	

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
