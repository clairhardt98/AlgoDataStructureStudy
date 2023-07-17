#include "CursorList.h"

#include <iostream>

using namespace std;
int main()
{
	Student st1 = { 1,string("abc") };
	Student st2 = { 2,string("def") };
	Student st3 = { 3, string("ghi") };
	List list(5);
	list.Insert(st1);
	list.Insert(st2);
	list.Insert(st3);
	//list.Print();
	list.Remove(2);
	list.Print();

}