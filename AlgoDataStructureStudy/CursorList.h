#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student
{
	int no;
	std::string name;
};
struct Node
{
	Student st;
	int next;
};

class List
{
private:
	Node* n;
	int* free;
	int freeIdx;
	int head;
	int last;
	int cur;
	int size;
	int count;
public:
	List(const int _n);
	~List();
public:
public:
	bool Insert(const Student _st);
	bool Remove(int no);
	void Clear();
	void Print();
};