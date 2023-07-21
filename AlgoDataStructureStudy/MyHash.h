#pragma once
#include "MyList.h"

class HashTable
{
private:
	const int Size = 13;
	StudentList *stList;

public:
	HashTable() { stList = new StudentList[Size]; }
	~HashTable() { delete[] stList; }

public:
	void Add(const Student& _st)
	{
		stList[_st.no % Size].Insert(_st.name, _st.no);
	}
	void Remove(int _no)
	{
		stList[_no % Size].Delete(_no);
	}
	void Print()
	{
		for (int i = 0; i < Size; i++)
		{
			std::cout << i << " ";
			stList[i].Print();
		}
	}

};