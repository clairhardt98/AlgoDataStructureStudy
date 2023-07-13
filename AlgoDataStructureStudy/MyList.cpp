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
	if (head == nullptr)return;
	Student* ref = head;
	Student* remove = head;
	while (remove!=nullptr)
	{
		if (ref->no == no)
		{
			remove = remove->next;
			ref->next = remove->next;
			delete remove;
			count--;
			break;
		}
		remove = remove->next;
		ref = ref->next;
	}
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
