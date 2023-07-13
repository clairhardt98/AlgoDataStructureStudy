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
//학생 관리 구조체 생성 : 번호 및 이름 포함
//구조체 리스트 만들고
//1. 입력 : 이름과 번호 입력, 2. 삭제 : 번호 입력받아서 삭제 3. 전체 출력 : 리스트에 있는 모든 학생의 번호, 이름 출력