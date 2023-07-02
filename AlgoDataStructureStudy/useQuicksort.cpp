#include<iostream>
#include <vector>
#include "MySort.h"
using namespace std;

int compCnt;
int swapCnt;

int main()
{
	vector<int> v = { 7,4,3,9,8,1,2,5,6 };
	QuickSort(v, 0, v.size() - 1);
	for (auto e : v)
		cout << e << " ";
}