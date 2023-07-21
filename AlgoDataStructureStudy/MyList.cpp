#include "MyList.h"

StudentList::StudentList()
{
	head = nullptr;
}

void StudentList::Insert(std::string name, int no)
{
	Student* newSt = new Student;
	newSt->name = name;
	newSt->no = no;
	newSt->next = nullptr;
	if (head == nullptr)
		head = newSt;
	else
	{
		Student* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newSt;
	}
}

void StudentList::Delete(int no)
{
	//아무것도 없을 때
	if (head == nullptr)return;
	//맨 앞이 찾는 노드일 때
	if (head->no == no)
	{
		Student* temp = head->next;
		delete head;
		head = temp;
		return;
	}
	Student* ref = head;
	Student* remove = head;
	while (ref->next->no != no)
	{
		if (ref->next == nullptr)return;
		ref = ref->next;
	}
	remove = ref->next;
	ref->next = remove->next;
	delete remove;
	
}

void StudentList::Print()
{
	using std::cout;
	using std::endl;
	Student* temp = head;
	//cout << "->";
	while (temp != nullptr)
	{
		cout << "->";
		cout << temp->no << "(" << temp->name << ")";
		temp = temp->next;
	}
	cout << endl;
}

void StudentList::Clear()
{
	if (head == nullptr)return;
	Student* temp = head->next;
	while (1)
	{
		delete head;
		head = temp;
		if (head == nullptr)
			break;
		temp = head->next;
	}
}


