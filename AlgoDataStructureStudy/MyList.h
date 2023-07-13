#pragma once
#include <string>
#include <iostream>
struct Student
{
	int no;
	std::string name;
	Student* next;
};

class StudentList
{
private:
	Student* head;
public:
	StudentList();
	~StudentList() { Clear(); }
	void Insert(std::string name, int no);
	void Delete(int no);
	void Print();
	void Clear();
};
//�л� ���� ����ü ���� : ��ȣ �� �̸� ����
//����ü ����Ʈ �����
//1. �Է� : �̸��� ��ȣ �Է�, 2. ���� : ��ȣ �Է¹޾Ƽ� ���� 3. ��ü ��� : ����Ʈ�� �ִ� ��� �л��� ��ȣ, �̸� ���