#include "MyList.h"

StudentList::StudentList()
{
	head = nullptr;
	count = 0;
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
	count++;
}

void StudentList::Delete(int no)
{
	//�ƹ��͵� ���� ��
	if (head == nullptr)return;
	//�� ���� ã�� ����� ��
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
	while (temp != nullptr)
	{
		cout << "name: " << temp->name << "\tnumber : " << temp->no << endl;
		temp = temp->next;
	}
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


